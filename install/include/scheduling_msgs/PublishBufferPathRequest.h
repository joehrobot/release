// Generated by gencpp from file scheduling_msgs/PublishBufferPathRequest.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_PUBLISHBUFFERPATHREQUEST_H
#define SCHEDULING_MSGS_MESSAGE_PUBLISHBUFFERPATHREQUEST_H


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
struct PublishBufferPathRequest_
{
  typedef PublishBufferPathRequest_<ContainerAllocator> Type;

  PublishBufferPathRequest_()
    : bufferID(0)  {
    }
  PublishBufferPathRequest_(const ContainerAllocator& _alloc)
    : bufferID(0)  {
  (void)_alloc;
    }



   typedef int32_t _bufferID_type;
  _bufferID_type bufferID;




  typedef boost::shared_ptr< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PublishBufferPathRequest_

typedef ::scheduling_msgs::PublishBufferPathRequest_<std::allocator<void> > PublishBufferPathRequest;

typedef boost::shared_ptr< ::scheduling_msgs::PublishBufferPathRequest > PublishBufferPathRequestPtr;
typedef boost::shared_ptr< ::scheduling_msgs::PublishBufferPathRequest const> PublishBufferPathRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace scheduling_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'scheduling_msgs': ['/home/ouiyeah/catkin_ws/src/scheduling_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d3985ab7f5447d8282273d25fb151ba7";
  }

  static const char* value(const ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd3985ab7f5447d82ULL;
  static const uint64_t static_value2 = 0x82273d25fb151ba7ULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/PublishBufferPathRequest";
  }

  static const char* value(const ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 bufferID\n\
";
  }

  static const char* value(const ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bufferID);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PublishBufferPathRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::PublishBufferPathRequest_<ContainerAllocator>& v)
  {
    s << indent << "bufferID: ";
    Printer<int32_t>::stream(s, indent + "  ", v.bufferID);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_PUBLISHBUFFERPATHREQUEST_H
