// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece_array.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_HPP_

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
// Member 'pieces'
#include "tower_interfaces/msg/detail/piece__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tower_interfaces__msg__PieceArray __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__msg__PieceArray __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PieceArray_
{
  using Type = PieceArray_<ContainerAllocator>;

  explicit PieceArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit PieceArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pieces_type =
    std::vector<tower_interfaces::msg::Piece_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::msg::Piece_<ContainerAllocator>>>;
  _pieces_type pieces;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pieces(
    const std::vector<tower_interfaces::msg::Piece_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::msg::Piece_<ContainerAllocator>>> & _arg)
  {
    this->pieces = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tower_interfaces::msg::PieceArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::msg::PieceArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::PieceArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::PieceArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__msg__PieceArray
    std::shared_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__msg__PieceArray
    std::shared_ptr<tower_interfaces::msg::PieceArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PieceArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pieces != other.pieces) {
      return false;
    }
    return true;
  }
  bool operator!=(const PieceArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PieceArray_

// alias to use template instance with default allocator
using PieceArray =
  tower_interfaces::msg::PieceArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_HPP_
