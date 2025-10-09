// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_custom_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_custom_interface/msg/detail/numbers__functions.h"
#include "my_custom_interface/msg/detail/numbers__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_custom_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Numbers_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_custom_interface::msg::Numbers(_init);
}

void Numbers_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_custom_interface::msg::Numbers *>(message_memory);
  typed_message->~Numbers();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Numbers_message_member_array[2] = {
  {
    "a",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_custom_interface::msg::Numbers, a),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "b",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_custom_interface::msg::Numbers, b),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Numbers_message_members = {
  "my_custom_interface::msg",  // message namespace
  "Numbers",  // message name
  2,  // number of fields
  sizeof(my_custom_interface::msg::Numbers),
  false,  // has_any_key_member_
  Numbers_message_member_array,  // message members
  Numbers_init_function,  // function to initialize message memory (memory has to be allocated)
  Numbers_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Numbers_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Numbers_message_members,
  get_message_typesupport_handle_function,
  &my_custom_interface__msg__Numbers__get_type_hash,
  &my_custom_interface__msg__Numbers__get_type_description,
  &my_custom_interface__msg__Numbers__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_custom_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_custom_interface::msg::Numbers>()
{
  return &::my_custom_interface::msg::rosidl_typesupport_introspection_cpp::Numbers_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_custom_interface, msg, Numbers)() {
  return &::my_custom_interface::msg::rosidl_typesupport_introspection_cpp::Numbers_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
