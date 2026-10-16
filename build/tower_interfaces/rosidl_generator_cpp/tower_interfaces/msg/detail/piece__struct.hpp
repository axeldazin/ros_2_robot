// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"
// Member 'dimensions'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tower_interfaces__msg__Piece __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__msg__Piece __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Piece_
{
  using Type = Piece_<ContainerAllocator>;

  explicit Piece_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    dimensions(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->color = "";
      this->confidence = 0.0f;
    }
  }

  explicit Piece_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : color(_alloc),
    pose(_alloc, _init),
    dimensions(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->color = "";
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    uint32_t;
  _id_type id;
  using _color_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_type color;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;
  using _dimensions_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _dimensions_type dimensions;
  using _confidence_type =
    float;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__color(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__dimensions(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->dimensions = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tower_interfaces::msg::Piece_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::msg::Piece_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::msg::Piece_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::msg::Piece_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::Piece_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::Piece_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::msg::Piece_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::msg::Piece_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::msg::Piece_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::msg::Piece_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__msg__Piece
    std::shared_ptr<tower_interfaces::msg::Piece_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__msg__Piece
    std::shared_ptr<tower_interfaces::msg::Piece_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Piece_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->color != other.color) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->dimensions != other.dimensions) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const Piece_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Piece_

// alias to use template instance with default allocator
using Piece =
  tower_interfaces::msg::Piece_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_HPP_
