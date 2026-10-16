// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE__TRAITS_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tower_interfaces/msg/detail/piece__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'dimensions'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace tower_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Piece & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: dimensions
  {
    out << "dimensions: ";
    to_flow_style_yaml(msg.dimensions, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Piece & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: dimensions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dimensions:\n";
    to_block_style_yaml(msg.dimensions, out, indentation + 2);
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Piece & msg, bool use_flow_style = false)
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
  const tower_interfaces::msg::Piece & msg,
  std::ostream & out, size_t indentation = 0)
{
  tower_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tower_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tower_interfaces::msg::Piece & msg)
{
  return tower_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tower_interfaces::msg::Piece>()
{
  return "tower_interfaces::msg::Piece";
}

template<>
inline const char * name<tower_interfaces::msg::Piece>()
{
  return "tower_interfaces/msg/Piece";
}

template<>
struct has_fixed_size<tower_interfaces::msg::Piece>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tower_interfaces::msg::Piece>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tower_interfaces::msg::Piece>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE__TRAITS_HPP_
