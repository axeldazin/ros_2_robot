// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece_array.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__BUILDER_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tower_interfaces/msg/detail/piece_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tower_interfaces
{

namespace msg
{

namespace builder
{

class Init_PieceArray_pieces
{
public:
  explicit Init_PieceArray_pieces(::tower_interfaces::msg::PieceArray & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::msg::PieceArray pieces(::tower_interfaces::msg::PieceArray::_pieces_type arg)
  {
    msg_.pieces = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::msg::PieceArray msg_;
};

class Init_PieceArray_header
{
public:
  Init_PieceArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PieceArray_pieces header(::tower_interfaces::msg::PieceArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PieceArray_pieces(msg_);
  }

private:
  ::tower_interfaces::msg::PieceArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::msg::PieceArray>()
{
  return tower_interfaces::msg::builder::Init_PieceArray_header();
}

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__BUILDER_HPP_
