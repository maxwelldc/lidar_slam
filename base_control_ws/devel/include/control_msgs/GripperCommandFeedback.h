// Generated by gencpp from file control_msgs/GripperCommandFeedback.msg
// DO NOT EDIT!


#ifndef CONTROL_MSGS_MESSAGE_GRIPPERCOMMANDFEEDBACK_H
#define CONTROL_MSGS_MESSAGE_GRIPPERCOMMANDFEEDBACK_H


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
struct GripperCommandFeedback_
{
  typedef GripperCommandFeedback_<ContainerAllocator> Type;

  GripperCommandFeedback_()
    : position(0.0)
    , effort(0.0)
    , stalled(false)
    , reached_goal(false)  {
    }
  GripperCommandFeedback_(const ContainerAllocator& _alloc)
    : position(0.0)
    , effort(0.0)
    , stalled(false)
    , reached_goal(false)  {
  (void)_alloc;
    }



   typedef double _position_type;
  _position_type position;

   typedef double _effort_type;
  _effort_type effort;

   typedef uint8_t _stalled_type;
  _stalled_type stalled;

   typedef uint8_t _reached_goal_type;
  _reached_goal_type reached_goal;





  typedef boost::shared_ptr< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct GripperCommandFeedback_

typedef ::control_msgs::GripperCommandFeedback_<std::allocator<void> > GripperCommandFeedback;

typedef boost::shared_ptr< ::control_msgs::GripperCommandFeedback > GripperCommandFeedbackPtr;
typedef boost::shared_ptr< ::control_msgs::GripperCommandFeedback const> GripperCommandFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_msgs::GripperCommandFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'control_msgs': ['/home/wenhou/base_control_ws/devel/share/control_msgs/msg', '/home/wenhou/base_control_ws/src/control_msgs/control_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e4cbff56d3562bcf113da5a5adeef91f";
  }

  static const char* value(const ::control_msgs::GripperCommandFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe4cbff56d3562bcfULL;
  static const uint64_t static_value2 = 0x113da5a5adeef91fULL;
};

template<class ContainerAllocator>
struct DataType< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_msgs/GripperCommandFeedback";
  }

  static const char* value(const ::control_msgs::GripperCommandFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
float64 position  # The current gripper gap size (in meters)\n\
float64 effort    # The current effort exerted (in Newtons)\n\
bool stalled      # True iff the gripper is exerting max effort and not moving\n\
bool reached_goal # True iff the gripper position has reached the commanded setpoint\n\
\n\
";
  }

  static const char* value(const ::control_msgs::GripperCommandFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.effort);
      stream.next(m.stalled);
      stream.next(m.reached_goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GripperCommandFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_msgs::GripperCommandFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_msgs::GripperCommandFeedback_<ContainerAllocator>& v)
  {
    s << indent << "position: ";
    Printer<double>::stream(s, indent + "  ", v.position);
    s << indent << "effort: ";
    Printer<double>::stream(s, indent + "  ", v.effort);
    s << indent << "stalled: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.stalled);
    s << indent << "reached_goal: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.reached_goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_MSGS_MESSAGE_GRIPPERCOMMANDFEEDBACK_H
