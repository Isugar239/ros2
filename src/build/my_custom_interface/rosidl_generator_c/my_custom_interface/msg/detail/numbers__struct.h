// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_custom_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_custom_interface/msg/numbers.h"


#ifndef MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_
#define MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Numbers in the package my_custom_interface.
typedef struct my_custom_interface__msg__Numbers
{
  int16_t a;
  int16_t b;
} my_custom_interface__msg__Numbers;

// Struct for a sequence of my_custom_interface__msg__Numbers.
typedef struct my_custom_interface__msg__Numbers__Sequence
{
  my_custom_interface__msg__Numbers * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_interface__msg__Numbers__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_H_
