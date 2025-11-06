// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtle_dekart_control_interface/msg/detail/numbers__rosidl_typesupport_introspection_c.h"
#include "turtle_dekart_control_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtle_dekart_control_interface/msg/detail/numbers__functions.h"
#include "turtle_dekart_control_interface/msg/detail/numbers__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtle_dekart_control_interface__msg__Numbers__init(message_memory);
}

void turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_fini_function(void * message_memory)
{
  turtle_dekart_control_interface__msg__Numbers__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_member_array[2] = {
  {
    "a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_dekart_control_interface__msg__Numbers, a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_dekart_control_interface__msg__Numbers, b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_members = {
  "turtle_dekart_control_interface__msg",  // message namespace
  "Numbers",  // message name
  2,  // number of fields
  sizeof(turtle_dekart_control_interface__msg__Numbers),
  false,  // has_any_key_member_
  turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_member_array,  // message members
  turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_init_function,  // function to initialize message memory (memory has to be allocated)
  turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_type_support_handle = {
  0,
  &turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_members,
  get_message_typesupport_handle_function,
  &turtle_dekart_control_interface__msg__Numbers__get_type_hash,
  &turtle_dekart_control_interface__msg__Numbers__get_type_description,
  &turtle_dekart_control_interface__msg__Numbers__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtle_dekart_control_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_dekart_control_interface, msg, Numbers)() {
  if (!turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_type_support_handle.typesupport_identifier) {
    turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtle_dekart_control_interface__msg__Numbers__rosidl_typesupport_introspection_c__Numbers_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
