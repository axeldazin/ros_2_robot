// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE__BUILDER_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tower_interfaces/msg/detail/piece__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tower_interfaces
{

namespace msg
{

namespace builder
{

class Init_Piece_confidence
{
public:
  explicit Init_Piece_confidence(::tower_interfaces::msg::Piece & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::msg::Piece confidence(::tower_interfaces::msg::Piece::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::msg::Piece msg_;
};

class Init_Piece_dimensions
{
public:
  explicit Init_Piece_dimensions(::tower_interfaces::msg::Piece & msg)
  : msg_(msg)
  {}
  Init_Piece_confidence dimensions(::tower_interfaces::msg::Piece::_dimensions_type arg)
  {
    msg_.dimensions = std::move(arg);
    return Init_Piece_confidence(msg_);
  }

private:
  ::tower_interfaces::msg::Piece msg_;
};

class Init_Piece_pose
{
public:
  explicit Init_Piece_pose(::tower_interfaces::msg::Piece & msg)
  : msg_(msg)
  {}
  Init_Piece_dimensions pose(::tower_interfaces::msg::Piece::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Piece_dimensions(msg_);
  }

private:
  ::tower_interfaces::msg::Piece msg_;
};

class Init_Piece_color
{
public:
  explicit Init_Piece_color(::tower_interfaces::msg::Piece & msg)
  : msg_(msg)
  {}
  Init_Piece_pose color(::tower_interfaces::msg::Piece::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_Piece_pose(msg_);
  }

private:
  ::tower_interfaces::msg::Piece msg_;
};

class Init_Piece_id
{
public:
  Init_Piece_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Piece_color id(::tower_interfaces::msg::Piece::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Piece_color(msg_);
  }

private:
  ::tower_interfaces::msg::Piece msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::msg::Piece>()
{
  return tower_interfaces::msg::builder::Init_Piece_id();
}

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE__BUILDER_HPP_
