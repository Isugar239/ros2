// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

#include "turtle_dekart_control_interface/msg/detail/numbers__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_dekart_control_interface
const rosidl_type_hash_t *
turtle_dekart_control_interface__msg__Numbers__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0x47, 0xc3, 0x47, 0x4b, 0x0c, 0x82, 0xe9,
      0x3d, 0x50, 0x84, 0x5c, 0xfa, 0xd8, 0x13, 0x05,
      0xa8, 0x1d, 0x3a, 0x6c, 0x5a, 0xca, 0x58, 0xc7,
      0x40, 0x89, 0xe8, 0xf0, 0x9c, 0x88, 0x6e, 0xc6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtle_dekart_control_interface__msg__Numbers__TYPE_NAME[] = "turtle_dekart_control_interface/msg/Numbers";

// Define type names, field names, and default values
static char turtle_dekart_control_interface__msg__Numbers__FIELD_NAME__a[] = "a";
static char turtle_dekart_control_interface__msg__Numbers__FIELD_NAME__b[] = "b";

static rosidl_runtime_c__type_description__Field turtle_dekart_control_interface__msg__Numbers__FIELDS[] = {
  {
    {turtle_dekart_control_interface__msg__Numbers__FIELD_NAME__a, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtle_dekart_control_interface__msg__Numbers__FIELD_NAME__b, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtle_dekart_control_interface__msg__Numbers__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_dekart_control_interface__msg__Numbers__TYPE_NAME, 43, 43},
      {turtle_dekart_control_interface__msg__Numbers__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int16 a\n"
  "int16 b";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_dekart_control_interface__msg__Numbers__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_dekart_control_interface__msg__Numbers__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_dekart_control_interface__msg__Numbers__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_dekart_control_interface__msg__Numbers__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
