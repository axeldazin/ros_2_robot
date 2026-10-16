// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tower_interfaces/msg/detail/piece__rosidl_typesupport_introspection_c.h"
#include "tower_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tower_interfaces/msg/detail/piece__functions.h"
#include "tower_interfaces/msg/detail/piece__struct.h"


// Include directives for member types
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"
// Member `dimensions`
#include "geometry_msgs/msg/vector3.h"
// Member `dimensions`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tower_interfaces__msg__Piece__init(message_memory);
}

void tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_fini_function(void * message_memory)
{
  tower_interfaces__msg__Piece__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_member_array[5] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__Piece, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__Piece, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__Piece, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dimensions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__Piece, dimensions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__Piece, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_members = {
  "tower_interfaces__msg",  // message namespace
  "Piece",  // message name
  5,  // number of fields
  sizeof(tower_interfaces__msg__Piece),
  false,  // has_any_key_member_
  tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_member_array,  // message members
  tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_init_function,  // function to initialize message memory (memory has to be allocated)
  tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_type_support_handle = {
  0,
  &tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_members,
  get_message_typesupport_handle_function,
  &tower_interfaces__msg__Piece__get_type_hash,
  &tower_interfaces__msg__Piece__get_type_description,
  &tower_interfaces__msg__Piece__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tower_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tower_interfaces, msg, Piece)() {
  tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_type_support_handle.typesupport_identifier) {
    tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tower_interfaces__msg__Piece__rosidl_typesupport_introspection_c__Piece_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
