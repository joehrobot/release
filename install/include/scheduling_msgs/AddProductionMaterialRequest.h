// Generated by gencpp from file scheduling_msgs/AddProductionMaterialRequest.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_ADDPRODUCTIONMATERIALREQUEST_H
#define SCHEDULING_MSGS_MESSAGE_ADDPRODUCTIONMATERIALREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <scheduling_msgs/ProductionMaterialList.h>

namespace scheduling_msgs
{
template <class ContainerAllocator>
struct AddProductionMaterialRequest_
{
  typedef AddProductionMaterialRequest_<ContainerAllocator> Type;

  AddProductionMaterialRequest_()
    : materials()  {
    }
  AddProductionMaterialRequest_(const ContainerAllocator& _alloc)
    : materials(_alloc)  {
  (void)_alloc;
    }



   typedef  ::scheduling_msgs::ProductionMaterialList_<ContainerAllocator>  _materials_type;
  _materials_type materials;




  typedef boost::shared_ptr< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AddProductionMaterialRequest_

typedef ::scheduling_msgs::AddProductionMaterialRequest_<std::allocator<void> > AddProductionMaterialRequest;

typedef boost::shared_ptr< ::scheduling_msgs::AddProductionMaterialRequest > AddProductionMaterialRequestPtr;
typedef boost::shared_ptr< ::scheduling_msgs::AddProductionMaterialRequest const> AddProductionMaterialRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e394acb3c989a7f4f59a1f3695633189";
  }

  static const char* value(const ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe394acb3c989a7f4ULL;
  static const uint64_t static_value2 = 0xf59a1f3695633189ULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/AddProductionMaterialRequest";
  }

  static const char* value(const ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
ProductionMaterialList materials\n\
\n\
================================================================================\n\
MSG: scheduling_msgs/ProductionMaterialList\n\
# msg for innolux\n\
ProductionMaterial[] materials\n\
================================================================================\n\
MSG: scheduling_msgs/ProductionMaterial\n\
# msg for innolux\n\
string line\n\
string station\n\
string machine\n\
string model\n\
string material_type\n\
string material_no\n\
";
  }

  static const char* value(const ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.materials);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddProductionMaterialRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::AddProductionMaterialRequest_<ContainerAllocator>& v)
  {
    s << indent << "materials: ";
    s << std::endl;
    Printer< ::scheduling_msgs::ProductionMaterialList_<ContainerAllocator> >::stream(s, indent + "  ", v.materials);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_ADDPRODUCTIONMATERIALREQUEST_H
