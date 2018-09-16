// Generated by gencpp from file scheduling_msgs/DeleteProductionPlanResponse.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_DELETEPRODUCTIONPLANRESPONSE_H
#define SCHEDULING_MSGS_MESSAGE_DELETEPRODUCTIONPLANRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace scheduling_msgs
{
template <class ContainerAllocator>
struct DeleteProductionPlanResponse_
{
  typedef DeleteProductionPlanResponse_<ContainerAllocator> Type;

  DeleteProductionPlanResponse_()
    : feedback(0)
    , message()  {
    }
  DeleteProductionPlanResponse_(const ContainerAllocator& _alloc)
    : feedback(0)
    , message(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _feedback_type;
  _feedback_type feedback;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;




  typedef boost::shared_ptr< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> const> ConstPtr;

}; // struct DeleteProductionPlanResponse_

typedef ::scheduling_msgs::DeleteProductionPlanResponse_<std::allocator<void> > DeleteProductionPlanResponse;

typedef boost::shared_ptr< ::scheduling_msgs::DeleteProductionPlanResponse > DeleteProductionPlanResponsePtr;
typedef boost::shared_ptr< ::scheduling_msgs::DeleteProductionPlanResponse const> DeleteProductionPlanResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace scheduling_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'scheduling_msgs': ['/home/ouiyeah/catkin_ws/src/scheduling_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6106db65d9740ad18b27381ab9159913";
  }

  static const char* value(const ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6106db65d9740ad1ULL;
  static const uint64_t static_value2 = 0x8b27381ab9159913ULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/DeleteProductionPlanResponse";
  }

  static const char* value(const ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 feedback\n\
\n\
\n\
string message\n\
\n\
";
  }

  static const char* value(const ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.feedback);
      stream.next(m.message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DeleteProductionPlanResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::DeleteProductionPlanResponse_<ContainerAllocator>& v)
  {
    s << indent << "feedback: ";
    Printer<int32_t>::stream(s, indent + "  ", v.feedback);
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_DELETEPRODUCTIONPLANRESPONSE_H