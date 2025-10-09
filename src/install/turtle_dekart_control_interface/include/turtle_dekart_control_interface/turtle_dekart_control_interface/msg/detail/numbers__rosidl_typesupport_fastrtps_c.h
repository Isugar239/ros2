// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice
#ifndef TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtle_dekart_control_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtle_dekart_control_interface/msg/detail/numbers__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
bool cdr_serialize_turtle_dekart_control_interface__msg__Numbers(
  const turtle_dekart_control_interface__msg__Numbers * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
bool cdr_deserialize_turtle_dekart_control_interface__msg__Numbers(
  eprosima::fastcdr::Cdr &,
  turtle_dekart_control_interface__msg__Numbers * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
size_t get_serialized_size_turtle_dekart_control_interface__msg__Numbers(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
size_t max_serialized_size_turtle_dekart_control_interface__msg__Numbers(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
bool cdr_serialize_key_turtle_dekart_control_interface__msg__Numbers(
  const turtle_dekart_control_interface__msg__Numbers * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
size_t get_serialized_size_key_turtle_dekart_control_interface__msg__Numbers(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
size_t max_serialized_size_key_turtle_dekart_control_interface__msg__Numbers(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_dekart_control_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_dekart_control_interface, msg, Numbers)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
