// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/srv/set_building_enabled.h"


#ifndef TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_H_
#define TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetBuildingEnabled in the package tower_interfaces.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Request
{
  bool enabled;
} tower_interfaces__srv__SetBuildingEnabled_Request;

// Struct for a sequence of tower_interfaces__srv__SetBuildingEnabled_Request.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Request__Sequence
{
  tower_interfaces__srv__SetBuildingEnabled_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__srv__SetBuildingEnabled_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetBuildingEnabled in the package tower_interfaces.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Response
{
  bool success;
  rosidl_runtime_c__String message;
} tower_interfaces__srv__SetBuildingEnabled_Response;

// Struct for a sequence of tower_interfaces__srv__SetBuildingEnabled_Response.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Response__Sequence
{
  tower_interfaces__srv__SetBuildingEnabled_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__srv__SetBuildingEnabled_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tower_interfaces__srv__SetBuildingEnabled_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tower_interfaces__srv__SetBuildingEnabled_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetBuildingEnabled in the package tower_interfaces.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tower_interfaces__srv__SetBuildingEnabled_Request__Sequence request;
  tower_interfaces__srv__SetBuildingEnabled_Response__Sequence response;
} tower_interfaces__srv__SetBuildingEnabled_Event;

// Struct for a sequence of tower_interfaces__srv__SetBuildingEnabled_Event.
typedef struct tower_interfaces__srv__SetBuildingEnabled_Event__Sequence
{
  tower_interfaces__srv__SetBuildingEnabled_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__srv__SetBuildingEnabled_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__STRUCT_H_
