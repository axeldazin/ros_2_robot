// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/srv/set_building_enabled.hpp"


#ifndef TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__BUILDER_HPP_
#define TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tower_interfaces/srv/detail/set_building_enabled__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tower_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBuildingEnabled_Request_enabled
{
public:
  Init_SetBuildingEnabled_Request_enabled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tower_interfaces::srv::SetBuildingEnabled_Request enabled(::tower_interfaces::srv::SetBuildingEnabled_Request::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::srv::SetBuildingEnabled_Request>()
{
  return tower_interfaces::srv::builder::Init_SetBuildingEnabled_Request_enabled();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBuildingEnabled_Response_message
{
public:
  explicit Init_SetBuildingEnabled_Response_message(::tower_interfaces::srv::SetBuildingEnabled_Response & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::srv::SetBuildingEnabled_Response message(::tower_interfaces::srv::SetBuildingEnabled_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Response msg_;
};

class Init_SetBuildingEnabled_Response_success
{
public:
  Init_SetBuildingEnabled_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBuildingEnabled_Response_message success(::tower_interfaces::srv::SetBuildingEnabled_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetBuildingEnabled_Response_message(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::srv::SetBuildingEnabled_Response>()
{
  return tower_interfaces::srv::builder::Init_SetBuildingEnabled_Response_success();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBuildingEnabled_Event_response
{
public:
  explicit Init_SetBuildingEnabled_Event_response(::tower_interfaces::srv::SetBuildingEnabled_Event & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::srv::SetBuildingEnabled_Event response(::tower_interfaces::srv::SetBuildingEnabled_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Event msg_;
};

class Init_SetBuildingEnabled_Event_request
{
public:
  explicit Init_SetBuildingEnabled_Event_request(::tower_interfaces::srv::SetBuildingEnabled_Event & msg)
  : msg_(msg)
  {}
  Init_SetBuildingEnabled_Event_response request(::tower_interfaces::srv::SetBuildingEnabled_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetBuildingEnabled_Event_response(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Event msg_;
};

class Init_SetBuildingEnabled_Event_info
{
public:
  Init_SetBuildingEnabled_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBuildingEnabled_Event_request info(::tower_interfaces::srv::SetBuildingEnabled_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetBuildingEnabled_Event_request(msg_);
  }

private:
  ::tower_interfaces::srv::SetBuildingEnabled_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::srv::SetBuildingEnabled_Event>()
{
  return tower_interfaces::srv::builder::Init_SetBuildingEnabled_Event_info();
}

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__BUILDER_HPP_
