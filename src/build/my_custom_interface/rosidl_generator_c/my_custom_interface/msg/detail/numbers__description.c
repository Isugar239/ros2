// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_custom_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

#include "my_custom_interface/msg/detail/numbers__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_custom_interface
const rosidl_type_hash_t *
my_custom_interface__msg__Numbers__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7e, 0xa9, 0x26, 0x5c, 0xcb, 0x99, 0x1f, 0x9b,
      0x7b, 0xd1, 0x37, 0x10, 0xd8, 0x76, 0xcb, 0xea,
      0x70, 0x8a, 0xeb, 0x63, 0xc0, 0xb4, 0xcc, 0xb7,
      0xfd, 0xb1, 0x78, 0x8b, 0x95, 0xad, 0x94, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char my_custom_interface__msg__Numbers__TYPE_NAME[] = "my_custom_interface/msg/Numbers";

// Define type names, field names, and default values
static char my_custom_interface__msg__Numbers__FIELD_NAME__a[] = "a";
static char my_custom_interface__msg__Numbers__FIELD_NAME__b[] = "b";

static rosidl_runtime_c__type_description__Field my_custom_interface__msg__Numbers__FIELDS[] = {
  {
    {my_custom_interface__msg__Numbers__FIELD_NAME__a, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_custom_interface__msg__Numbers__FIELD_NAME__b, 1, 1},
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
my_custom_interface__msg__Numbers__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_custom_interface__msg__Numbers__TYPE_NAME, 31, 31},
      {my_custom_interface__msg__Numbers__FIELDS, 2, 2},
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
my_custom_interface__msg__Numbers__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_custom_interface__msg__Numbers__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_custom_interface__msg__Numbers__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_custom_interface__msg__Numbers__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
