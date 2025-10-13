// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_dekart_control_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_dekart_control_interface/msg/numbers.hpp"


#ifndef TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__BUILDER_HPP_
#define TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_dekart_control_interface/msg/detail/numbers__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_dekart_control_interface
{

namespace msg
{

namespace builder
{

class Init_Numbers_b
{
public:
  explicit Init_Numbers_b(::turtle_dekart_control_interface::msg::Numbers & msg)
  : msg_(msg)
  {}
  ::turtle_dekart_control_interface::msg::Numbers b(::turtle_dekart_control_interface::msg::Numbers::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_dekart_control_interface::msg::Numbers msg_;
};

class Init_Numbers_a
{
public:
  Init_Numbers_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Numbers_b a(::turtle_dekart_control_interface::msg::Numbers::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Numbers_b(msg_);
  }

private:
  ::turtle_dekart_control_interface::msg::Numbers msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_dekart_control_interface::msg::Numbers>()
{
  return turtle_dekart_control_interface::msg::builder::Init_Numbers_a();
}

}  // namespace turtle_dekart_control_interface

#endif  // TURTLE_DEKART_CONTROL_INTERFACE__MSG__DETAIL__NUMBERS__BUILDER_HPP_
