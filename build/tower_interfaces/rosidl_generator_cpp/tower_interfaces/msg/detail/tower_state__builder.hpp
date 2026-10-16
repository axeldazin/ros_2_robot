// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tower_interfaces:msg/TowerState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/tower_state.hpp"


#ifndef TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__BUILDER_HPP_
#define TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tower_interfaces/msg/detail/tower_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tower_interfaces
{

namespace msg
{

namespace builder
{

class Init_TowerState_detail
{
public:
  explicit Init_TowerState_detail(::tower_interfaces::msg::TowerState & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::msg::TowerState detail(::tower_interfaces::msg::TowerState::_detail_type arg)
  {
    msg_.detail = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::msg::TowerState msg_;
};

class Init_TowerState_height
{
public:
  explicit Init_TowerState_height(::tower_interfaces::msg::TowerState & msg)
  : msg_(msg)
  {}
  Init_TowerState_detail height(::tower_interfaces::msg::TowerState::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_TowerState_detail(msg_);
  }

private:
  ::tower_interfaces::msg::TowerState msg_;
};

class Init_TowerState_placed_count
{
public:
  explicit Init_TowerState_placed_count(::tower_interfaces::msg::TowerState & msg)
  : msg_(msg)
  {}
  Init_TowerState_height placed_count(::tower_interfaces::msg::TowerState::_placed_count_type arg)
  {
    msg_.placed_count = std::move(arg);
    return Init_TowerState_height(msg_);
  }

private:
  ::tower_interfaces::msg::TowerState msg_;
};

class Init_TowerState_state
{
public:
  explicit Init_TowerState_state(::tower_interfaces::msg::TowerState & msg)
  : msg_(msg)
  {}
  Init_TowerState_placed_count state(::tower_interfaces::msg::TowerState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_TowerState_placed_count(msg_);
  }

private:
  ::tower_interfaces::msg::TowerState msg_;
};

class Init_TowerState_header
{
public:
  Init_TowerState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TowerState_state header(::tower_interfaces::msg::TowerState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TowerState_state(msg_);
  }

private:
  ::tower_interfaces::msg::TowerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::msg::TowerState>()
{
  return tower_interfaces::msg::builder::Init_TowerState_header();
}

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__BUILDER_HPP_
