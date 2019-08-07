// Generated by gencpp from file control_msgs/QueryTrajectoryStateResponse.msg
// DO NOT EDIT!


#ifndef CONTROL_MSGS_MESSAGE_QUERYTRAJECTORYSTATERESPONSE_H
#define CONTROL_MSGS_MESSAGE_QUERYTRAJECTORYSTATERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace control_msgs
{
template <class ContainerAllocator>
struct QueryTrajectoryStateResponse_
{
  typedef QueryTrajectoryStateResponse_<ContainerAllocator> Type;

  QueryTrajectoryStateResponse_()
    : name()
    , position()
    , velocity()
    , acceleration()  {
    }
  QueryTrajectoryStateResponse_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , position(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _name_type;
  _name_type name;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _position_type;
  _position_type position;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _velocity_type;
  _velocity_type velocity;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _acceleration_type;
  _acceleration_type acceleration;





  typedef boost::shared_ptr< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> const> ConstPtr;

}; // struct QueryTrajectoryStateResponse_

typedef ::control_msgs::QueryTrajectoryStateResponse_<std::allocator<void> > QueryTrajectoryStateResponse;

typedef boost::shared_ptr< ::control_msgs::QueryTrajectoryStateResponse > QueryTrajectoryStateResponsePtr;
typedef boost::shared_ptr< ::control_msgs::QueryTrajectoryStateResponse const> QueryTrajectoryStateResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'control_msgs': ['/home/wenhou/base_control_ws/devel/share/control_msgs/msg', '/home/wenhou/base_control_ws/src/control_msgs/control_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1f1a6554ad060f44d013e71868403c1a";
  }

  static const char* value(const ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1f1a6554ad060f44ULL;
  static const uint64_t static_value2 = 0xd013e71868403c1aULL;
};

template<class ContainerAllocator>
struct DataType< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_msgs/QueryTrajectoryStateResponse";
  }

  static const char* value(const ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] name\n\
float64[] position\n\
float64[] velocity\n\
float64[] acceleration\n\
\n\
";
  }

  static const char* value(const ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.position);
      stream.next(m.velocity);
      stream.next(m.acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct QueryTrajectoryStateResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_msgs::QueryTrajectoryStateResponse_<ContainerAllocator>& v)
  {
    s << indent << "name[]" << std::endl;
    for (size_t i = 0; i < v.name.size(); ++i)
    {
      s << indent << "  name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name[i]);
    }
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.position[i]);
    }
    s << indent << "velocity[]" << std::endl;
    for (size_t i = 0; i < v.velocity.size(); ++i)
    {
      s << indent << "  velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.velocity[i]);
    }
    s << indent << "acceleration[]" << std::endl;
    for (size_t i = 0; i < v.acceleration.size(); ++i)
    {
      s << indent << "  acceleration[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.acceleration[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_MSGS_MESSAGE_QUERYTRAJECTORYSTATERESPONSE_H