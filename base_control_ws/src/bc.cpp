/******************************************************************
基于串口通信的ROS小车基础控制器，功能如下：
1.实现ros控制数据通过固定的格式和串口通信，从而达到控制小车的移动
2.订阅了/cmd_vel主题，只要向该主题发布消息，就能实现对控制小车的移动
3.发布里程计主题/odm

串口通信说明：
1.写入串口
（1）内容：左右轮速度，单位为mm/s
（2）格式：１０字节,[右轮速度４字节][左轮速度４字节][结束符"\r\n"２字节]
2.读取串口
（1）内容：小车x,y坐标，方向角，线速度，角速度，单位依次为：mm,mm,rad,mm/s,rad/s
（2）格式：２１字节，[Ｘ坐标４字节][Ｙ坐标４字节][方向角４字节][线速度４字节][角速度４字节][结束符"\n"１字节]
*******************************************************************/
#include "ros/ros.h"  //ros需要的头文件
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
//以下为串口通讯需要的头文件
#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <math.h>
#include "serial/serial.h"
#include <sensor_msgs/Imu.h>

#include <iostream>                   // C++标准库头文件
#include <iomanip>
#include <math.h>


#include <std_msgs/String.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PolygonStamped.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Point32.h>
#include <tf/tf.h>

/****************************************************************************/
using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
/*****************************************************************************/
float ratio = 1000.0f ;   //转速转换比例，执行速度调整比例
float D = 0.188f ;    //两轮间距，单位是m
float linear_temp=0,angular_temp=0;//暂存的线速度和角速度
/****************************************************/
unsigned char data_terminal0=0x0d;  //“/r"字符
unsigned char data_terminal1=0x0a;  //“/n"字符
unsigned char speed_data[10]={0};   //要发给串口的数据
string rec_buffer;  //串口数据接收变量

//发送给下位机的左右轮速度，里程计的坐标和方向
union floatData //union的作用为实现char数组和float之间的转换
{
    float d;
    unsigned char data[4];
}right_speed_data,left_speed_data,position_x,position_y,oriention,vel_linear,vel_angular;

union intData //union的作用为实现char数组和float之间的转换
{
    float d;
    unsigned char data[4];
}acc_x,acc_y,acc_z,gyro_x,gyro_y,gyro_z,Q_1,Q_2,Q_3,Q_4;

void callback(const geometry_msgs::Twist & cmd_input)//订阅/cmd_vel主题回调函数
{
//printf("serial start\r\n");
    string port("/dev/ttyAMA0");    //小车串口号
    unsigned long baud = 115200;    //小车串口波特率
    serial::Serial my_serial(port, baud, serial::Timeout::simpleTimeout(1000)); //配置串口

    angular_temp = cmd_input.angular.z ;//获取/cmd_vel的角速度,rad/s
//printf("angular=%f\r\n",angular_temp);
    linear_temp = cmd_input.linear.x ;//获取/cmd_vel的线速度.m/s
//printf("linear_temp=%f\r\n",linear_temp);
    //将转换好的小车速度分量为左右轮速度
    left_speed_data.d = linear_temp - 0.5f*angular_temp*D ;
    right_speed_data.d = linear_temp + 0.5f*angular_temp*D ;

    //存入数据到要发布的左右轮速度消息
    left_speed_data.d*=ratio;   //放大１０００倍，mm/s
    right_speed_data.d*=ratio;//放大１０００倍，mm/s

    for(int i=0;i<4;i++)    //将左右轮速度存入数组中发送给串口
    {
        speed_data[i]=right_speed_data.data[i];
        speed_data[i+4]=left_speed_data.data[i];
    }

    //在写入串口的左右轮速度数据后加入”/r/n“
    speed_data[8]=data_terminal0;
    speed_data[9]=data_terminal1;
    //写入数据到串口
   // printf("serial\r\n");
for(int j=0;j<10;j++)
{
//printf("s=%d\r\n",speed_data[j]);
}

    my_serial.write(speed_data,10);

}

int main(int argc, char **argv)
{
    string port("/dev/ttyAMA0");//小车串口号
    unsigned long baud = 115200;//小车串口波特率
    serial::Serial my_serial(port, baud, serial::Timeout::simpleTimeout(1000));//配置串口

    ros::init(argc, argv, "base_controller");//初始化串口节点

    ros::NodeHandle n;  //定义节点进程句柄

    ros::Subscriber sub = n.subscribe("cmd_vel",1, callback); //订阅/cmd_vel主题
    ros::Publisher odom_pub= n.advertise<nav_msgs::Odometry>("odom", 1); //定义要发布/odom主题
    ros::Publisher IMU_pub = n.advertise<sensor_msgs::Imu>("IMU_data", 20);

    static tf::TransformBroadcaster odom_broadcaster;//定义tf对象

    geometry_msgs::TransformStamped odom_trans;//创建一个tf发布需要使用的TransformStamped类型消息
    nav_msgs::Odometry odom;//定义里程计对象
    geometry_msgs::Quaternion odom_quat; //四元数变量
    sensor_msgs::Imu imu_data;

    ros::Publisher poly_pub = n.advertise<geometry_msgs::PolygonStamped>("polygon",10); // 发布PolygonStamped信息，rviz中显示机器人边界
    //定义covariance矩阵，作用为解决文职和速度的不同测量的不确定性
    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

  float covariance[36] = {0.01,   0,    0,     0,     0,     0,  // covariance on gps_x
                            0,  0.01, 0,     0,     0,     0,  // covariance on gps_y
                            0,  0,    99999, 0,     0,     0,  // covariance on gps_z
                            0,  0,    0,     99999, 0,     0,  // large covariance on rot x
                            0,  0,    0,     0,     99999, 0,  // large covariance on rot y
                            0,  0,    0,     0,     0,     0.01};  // large covariance on rot z 
    //载入covariance矩阵
    for(int i = 0; i < 36; i++)
    {
        odom.pose.covariance[i] = covariance[i];;
    }

    ros::Rate loop_rate(1);//设置周期休眠时间
    while(ros::ok())
   {
       current_time = ros::Time::now();
       //my_serial.write("init ok\r\n");
       printf("init ok\r\n");

        rec_buffer =my_serial.readline(44,"\n");    //获取串口发送来的数据
        const char *receive_data=rec_buffer.data(); //保存串口发送来的数据
        //printf("%c\r\n",receive_data[2]);
        printf("length=%d\r\n",rec_buffer.length());
        if(rec_buffer.length()==21)//串口接收的数据长度正确就处理并发布里程计数据消息
        {
            for(int i=0;i<4;i++)//提取X，Y坐标，方向，线速度，角速度
            {
                position_x.data[i]=receive_data[i];
                position_y.data[i]=receive_data[i+4];
                oriention.data[i]=receive_data[i+8];
                vel_linear.data[i]=receive_data[i+12];
                vel_angular.data[i]=receive_data[i+16];
            }
            //将X，Y坐标，线速度缩小1000倍
            position_x.d/=1000; //m
            position_y.d/=1000; //m
            vel_linear.d/=1000; //m/s

            printf("pst_x=%f\r\n",position_x.d);
            //里程计的偏航角需要转换成四元数才能发布
      odom_quat = tf::createQuaternionMsgFromYaw(oriention.d);//将偏航角转换成四元数

            //载入坐标（tf）变换时间戳
            odom_trans.header.stamp = ros::Time::now();
            //发布坐标变换的父子坐标系
            odom_trans.header.frame_id = "odom";
            odom_trans.child_frame_id = "base_link";
            //tf位置数据：x,y,z,方向
            odom_trans.transform.translation.x = position_x.d;
            odom_trans.transform.translation.y = position_y.d;
            odom_trans.transform.translation.z = 0.0;
            odom_trans.transform.rotation = odom_quat;
            //发布tf坐标变化
       odom_broadcaster.sendTransform(odom_trans);

            //载入里程计时间戳
            odom.header.stamp = ros::Time::now();
            //里程计的父子坐标系
            odom.header.frame_id = "odom";
            odom.child_frame_id = "base_link";
            //里程计位置数据：x,y,z,方向
            odom.pose.pose.position.x = position_x.d;
            odom.pose.pose.position.y = position_y.d;
            odom.pose.pose.position.z = 0.0;
            odom.pose.pose.orientation = odom_quat;
            //载入线速度和角速度
            odom.twist.twist.linear.x = vel_linear.d;
            //odom.twist.twist.linear.y = odom_vy;
            odom.twist.twist.angular.z = vel_angular.d;
            //发布里程计
            odom_pub.publish(odom);
}



{
            if(rec_buffer.length()==42)
          {

            for(int i=0;i<4;i++)//提取X，Y坐标，方向，线速度，角速度
            {
               acc_x.data[i]=receive_data[i];
                acc_y.data[i]=receive_data[i+4];
                acc_z.data[i]=receive_data[i+8];
                gyro_x.data[i]=receive_data[i+12];
                gyro_y.data[i]=receive_data[i+16];
                gyro_z.data[i]=receive_data[i+20];
                Q_1.data[i]=receive_data[i+24];
                Q_2.data[i]=receive_data[i+28];
                Q_3.data[i]=receive_data[i+32];
                Q_4.data[i]=receive_data[i+36];
     }


            imu_data.header.stamp = ros::Time::now();
            imu_data.header.frame_id = "imu"; //四元数位姿,所有数据设为固定值，可以自己写代码获取ＩＭＵ的数据，，然后进行传递 

            imu_data.orientation.x = Q_1.d;
            imu_data.orientation.y = Q_2.d;
            imu_data.orientation.z = Q_3.d;
            imu_data.orientation.w =Q_4.d; //线加速度 
          //  printf("Q_1=%f  Q_2=%f  Q_3=%f  Q_4%f\r\n",imu_data.orientation.x,imu_data.orientation.y,imu_data.orientation.z,imu_data.orientation.w);

//printf("Q_1=%f  Q_2=%f  Q_3=%f Q_4=%f\r\n",Q_1.d,Q_2.d,Q_3.d,Q_4.d);

            imu_data.linear_acceleration.x = acc_x.d;
            imu_data.linear_acceleration.y = acc_y.d;
            imu_data.linear_acceleration.z = acc_z.d; //角速度 
          //  printf("acc_z=%f\r\n",imu_data.linear_acceleration.z);
            imu_data.angular_velocity.x = gyro_x.d;
            imu_data.angular_velocity.y = gyro_y.d;
            imu_data.angular_velocity.z = gyro_z.d;
            IMU_pub.publish(imu_data);
        }


            /*******************publish polygon message***********************/
             geometry_msgs::Point32 point[4];
             // coordinates described in base_link frame
             point[0].x = -0.11;  point[0].y = -0.10;
             point[1].x = 0.11;   point[1].y = -0.10;
             point[2].x = 0.11;   point[2].y = 0.10;
             point[3].x = -0.11;  point[3].y = 0.10;

             geometry_msgs::PolygonStamped poly;
             poly.header.stamp = current_time;
             poly.header.frame_id = "base_link";  // 多边形相对于base_link来描述
             poly.polygon.points.push_back(point[0]);
             poly.polygon.points.push_back(point[1]);
             poly.polygon.points.push_back(point[2]);
             poly.polygon.points.push_back(point[3]);
    poly_pub.publish(poly);
}


      //      ros::spinOnce();//周期执行
    //  loop_rate.sleep();//周期休眠

        //程序周期性调用
//ros::spin();
        ros::spinOnce();  //callback函数必须处理所有问题时，才可以用到
//        loop_rate.sleep();//周期休眠
    }
//    return 0;
}

