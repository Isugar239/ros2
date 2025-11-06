// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_dekart_control_interface/msg/numbers.h"


#ifndef TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_
#define TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Numbers in the package turtle_dekart_control_interface.
typedef struct turtle_dekart_control_interface__msg__Numbers
{
  int16_t a;
  int16_t b;
} turtle_dekart_control_interface__msg__Numbers;

// Struct for a sequence of turtle_dekart_control_interface__msg__Numbers.
typedef struct turtle_dekart_control_interface__msg__Numbers__Sequence
{
  turtle_dekart_control_interface__msg__Numbers * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_dekart_control_interface__msg__Numbers__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_
