// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece_array.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__TRAITS_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tower_interfaces/msg/detail/piece_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pieces'
#include "tower_interfaces/msg/detail/piece__traits.hpp"

namespace tower_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PieceArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pieces
  {
    if (msg.pieces.size() == 0) {
      out << "pieces: []";
    } else {
      out << "pieces: [";
      size_t pending_items = msg.pieces.size();
      for (auto item : msg.pieces) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PieceArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: pieces
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pieces.size() == 0) {
      out << "pieces: []\n";
    } else {
      out << "pieces:\n";
      for (auto item : msg.pieces) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PieceArray & msg, bool use_flow_style = false)
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

}  // namespace tower_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tower_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tower_interfaces::msg::PieceArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  tower_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tower_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tower_interfaces::msg::PieceArray & msg)
{
  return tower_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tower_interfaces::msg::PieceArray>()
{
  return "tower_interfaces::msg::PieceArray";
}

template<>
inline const char * name<tower_interfaces::msg::PieceArray>()
{
  return "tower_interfaces/msg/PieceArray";
}

template<>
struct has_fixed_size<tower_interfaces::msg::PieceArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tower_interfaces::msg::PieceArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tower_interfaces::msg::PieceArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__TRAITS_HPP_
