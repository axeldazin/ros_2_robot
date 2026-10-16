// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/srv/set_building_enabled.hpp"


#ifndef TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_HPP_
#define TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Request __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Request __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetBuildingEnabled_Request_
{
  using Type = SetBuildingEnabled_Request_<ContainerAllocator>;

  explicit SetBuildingEnabled_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
    }
  }

  explicit SetBuildingEnabled_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
    }
  }

  // field types and members
  using _enabled_type =
    bool;
  _enabled_type enabled;

  // setters for named parameter idiom
  Type & set__enabled(
    const bool & _arg)
  {
    this->enabled = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Request
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Request
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetBuildingEnabled_Request_ & other) const
  {
    if (this->enabled != other.enabled) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetBuildingEnabled_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetBuildingEnabled_Request_

// alias to use template instance with default allocator
using SetBuildingEnabled_Request =
  tower_interfaces::srv::SetBuildingEnabled_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tower_interfaces


#ifndef _WIN32
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Response __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Response __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetBuildingEnabled_Response_
{
  using Type = SetBuildingEnabled_Response_<ContainerAllocator>;

  explicit SetBuildingEnabled_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetBuildingEnabled_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Response
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Response
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetBuildingEnabled_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetBuildingEnabled_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetBuildingEnabled_Response_

// alias to use template instance with default allocator
using SetBuildingEnabled_Response =
  tower_interfaces::srv::SetBuildingEnabled_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tower_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Event __attribute__((deprecated))
#else
# define DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Event __declspec(deprecated)
#endif

namespace tower_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetBuildingEnabled_Event_
{
  using Type = SetBuildingEnabled_Event_<ContainerAllocator>;

  explicit SetBuildingEnabled_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetBuildingEnabled_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::srv::SetBuildingEnabled_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tower_interfaces::srv::SetBuildingEnabled_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Event
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tower_interfaces__srv__SetBuildingEnabled_Event
    std::shared_ptr<tower_interfaces::srv::SetBuildingEnabled_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetBuildingEnabled_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetBuildingEnabled_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetBuildingEnabled_Event_

// alias to use template instance with default allocator
using SetBuildingEnabled_Event =
  tower_interfaces::srv::SetBuildingEnabled_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tower_interfaces

namespace tower_interfaces
{

namespace srv
{

struct SetBuildingEnabled
{
  using Request = tower_interfaces::srv::SetBuildingEnabled_Request;
  using Response = tower_interfaces::srv::SetBuildingEnabled_Response;
  using Event = tower_interfaces::srv::SetBuildingEnabled_Event;
};

}  // namespace srv

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_HPP_
