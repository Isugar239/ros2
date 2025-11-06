// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_dekart_control_interface/msg/numbers.hpp"


#ifndef TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__TRAITS_HPP_
#define TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_dekart_control_interface/msg/detail/numbers__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_dekart_control_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Numbers & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Numbers & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Numbers & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_dekart_control_interface

namespace rosidl_generator_traits
{

[[deprecated("use turtle_dekart_control_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_dekart_control_interface::msg::Numbers & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_dekart_control_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_dekart_control_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_dekart_control_interface::msg::Numbers & msg)
{
  return turtle_dekart_control_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_dekart_control_interface::msg::Numbers>()
{
  return "turtle_dekart_control_interface::msg::Numbers";
}

template<>
inline const char * name<turtle_dekart_control_interface::msg::Numbers>()
{
  return "turtle_dekart_control_interface/msg/Numbers";
}

template<>
struct has_fixed_size<turtle_dekart_control_interface::msg::Numbers>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_dekart_control_interface::msg::Numbers>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_dekart_control_interface::msg::Numbers>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__TRAITS_HPP_
