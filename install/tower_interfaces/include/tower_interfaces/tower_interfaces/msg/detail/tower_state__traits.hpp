// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tower_interfaces:msg/TowerState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/tower_state.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__TRAITS_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tower_interfaces/msg/detail/tower_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace tower_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TowerState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: placed_count
  {
    out << "placed_count: ";
    rosidl_generator_traits::value_to_yaml(msg.placed_count, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: detail
  {
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TowerState & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: placed_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "placed_count: ";
    rosidl_generator_traits::value_to_yaml(msg.placed_count, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: detail
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TowerState & msg, bool use_flow_style = false)
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
  const tower_interfaces::msg::TowerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  tower_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tower_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tower_interfaces::msg::TowerState & msg)
{
  return tower_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tower_interfaces::msg::TowerState>()
{
  return "tower_interfaces::msg::TowerState";
}

template<>
inline const char * name<tower_interfaces::msg::TowerState>()
{
  return "tower_interfaces/msg/TowerState";
}

template<>
struct has_fixed_size<tower_interfaces::msg::TowerState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tower_interfaces::msg::TowerState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tower_interfaces::msg::TowerState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__TRAITS_HPP_
