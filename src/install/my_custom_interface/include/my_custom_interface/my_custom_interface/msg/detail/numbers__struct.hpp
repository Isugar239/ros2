// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_custom_interface:msg/Numbers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_custom_interface/msg/numbers.hpp"


#ifndef MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_HPP_
#define MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_custom_interface__msg__Numbers __attribute__((deprecated))
#else
# define DEPRECATED__my_custom_interface__msg__Numbers __declspec(deprecated)
#endif

namespace my_custom_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Numbers_
{
  using Type = Numbers_<ContainerAllocator>;

  explicit Numbers_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0;
      this->b = 0;
    }
  }

  explicit Numbers_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0;
      this->b = 0;
    }
  }

  // field types and members
  using _a_type =
    int16_t;
  _a_type a;
  using _b_type =
    int16_t;
  _b_type b;

  // setters for named parameter idiom
  Type & set__a(
    const int16_t & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const int16_t & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_custom_interface::msg::Numbers_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_custom_interface::msg::Numbers_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_custom_interface::msg::Numbers_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_custom_interface::msg::Numbers_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_custom_interface__msg__Numbers
    std::shared_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_custom_interface__msg__Numbers
    std::shared_ptr<my_custom_interface::msg::Numbers_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Numbers_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const Numbers_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Numbers_

// alias to use template instance with default allocator
using Numbers =
  my_custom_interface::msg::Numbers_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_custom_interface

#endif  // MY_CUSTOM_INTERFACE__MSG__DETAIL__NUMBERS__STRUCT_HPP_
