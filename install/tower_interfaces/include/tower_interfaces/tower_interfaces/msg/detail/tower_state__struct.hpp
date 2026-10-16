// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tower_interfaces:msg/TowerState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/tower_state.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tower_interfaces__msg__TowerState __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__msg__TowerState __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TowerState_
{
  using Type = TowerState_<ContainerAllocator>;

  explicit TowerState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->placed_count = 0ul;
      this->height = 0.0;
      this->detail = "";
    }
  }

  explicit TowerState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    detail(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->placed_count = 0ul;
      this->height = 0.0;
      this->detail = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _state_type =
    uint8_t;
  _state_type state;
  using _placed_count_type =
    uint32_t;
  _placed_count_type placed_count;
  using _height_type =
    double;
  _height_type height;
  using _detail_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _detail_type detail;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__placed_count(
    const uint32_t & _arg)
  {
    this->placed_count = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__detail(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->detail = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t OBSERVING =
    1u;
  static constexpr uint8_t SELECTING =
    2u;
  static constexpr uint8_t MANIPULATING =
    3u;
  static constexpr uint8_t VERIFYING =
    4u;
  static constexpr uint8_t PAUSED =
    5u;
  static constexpr uint8_t FINISHED =
    6u;
  // guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
  static constexpr uint8_t ERROR =
    7u;
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif

  // pointer types
  using RawPtr =
    tower_interfaces::msg::TowerState_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::msg::TowerState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::TowerState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::TowerState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__msg__TowerState
    std::shared_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__msg__TowerState
    std::shared_ptr<tower_interfaces::msg::TowerState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TowerState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->placed_count != other.placed_count) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->detail != other.detail) {
      return false;
    }
    return true;
  }
  bool operator!=(const TowerState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TowerState_

// alias to use template instance with default allocator
using TowerState =
  tower_interfaces::msg::TowerState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::OBSERVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::SELECTING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::MANIPULATING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::VERIFYING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::PAUSED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::FINISHED;
#endif  // __cplusplus < 201703L
// guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TowerState_<ContainerAllocator>::ERROR;
#endif  // __cplusplus < 201703L
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif

}  // namespace msg

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_HPP_
