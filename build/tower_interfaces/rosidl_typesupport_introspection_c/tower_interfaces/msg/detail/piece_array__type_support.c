// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tower_interfaces/msg/detail/piece_array__rosidl_typesupport_introspection_c.h"
#include "tower_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tower_interfaces/msg/detail/piece_array__functions.h"
#include "tower_interfaces/msg/detail/piece_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `pieces`
#include "tower_interfaces/msg/piece.h"
// Member `pieces`
#include "tower_interfaces/msg/detail/piece__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tower_interfaces__msg__PieceArray__init(message_memory);
}

void tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_fini_function(void * message_memory)
{
  tower_interfaces__msg__PieceArray__fini(message_memory);
}

size_t tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__size_function__PieceArray__pieces(
  const void * untyped_member)
{
  const tower_interfaces__msg__Piece__Sequence * member =
    (const tower_interfaces__msg__Piece__Sequence *)(untyped_member);
  return member->size;
}

const void * tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_const_function__PieceArray__pieces(
  const void * untyped_member, size_t index)
{
  const tower_interfaces__msg__Piece__Sequence * member =
    (const tower_interfaces__msg__Piece__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_function__PieceArray__pieces(
  void * untyped_member, size_t index)
{
  tower_interfaces__msg__Piece__Sequence * member =
    (tower_interfaces__msg__Piece__Sequence *)(untyped_member);
  return &member->data[index];
}

void tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__fetch_function__PieceArray__pieces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tower_interfaces__msg__Piece * item =
    ((const tower_interfaces__msg__Piece *)
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_const_function__PieceArray__pieces(untyped_member, index));
  tower_interfaces__msg__Piece * value =
    (tower_interfaces__msg__Piece *)(untyped_value);
  *value = *item;
}

void tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__assign_function__PieceArray__pieces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tower_interfaces__msg__Piece * item =
    ((tower_interfaces__msg__Piece *)
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_function__PieceArray__pieces(untyped_member, index));
  const tower_interfaces__msg__Piece * value =
    (const tower_interfaces__msg__Piece *)(untyped_value);
  *item = *value;
}

bool tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__resize_function__PieceArray__pieces(
  void * untyped_member, size_t size)
{
  tower_interfaces__msg__Piece__Sequence * member =
    (tower_interfaces__msg__Piece__Sequence *)(untyped_member);
  tower_interfaces__msg__Piece__Sequence__fini(member);
  return tower_interfaces__msg__Piece__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__PieceArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pieces",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces__msg__PieceArray, pieces),  // bytes offset in struct
    NULL,  // default value
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__size_function__PieceArray__pieces,  // size() function pointer
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_const_function__PieceArray__pieces,  // get_const(index) function pointer
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__get_function__PieceArray__pieces,  // get(index) function pointer
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__fetch_function__PieceArray__pieces,  // fetch(index, &value) function pointer
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__assign_function__PieceArray__pieces,  // assign(index, value) function pointer
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__resize_function__PieceArray__pieces  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_members = {
  "tower_interfaces__msg",  // message namespace
  "PieceArray",  // message name
  2,  // number of fields
  sizeof(tower_interfaces__msg__PieceArray),
  false,  // has_any_key_member_
  tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_member_array,  // message members
  tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_init_function,  // function to initialize message memory (memory has to be allocated)
  tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_type_support_handle = {
  0,
  &tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_members,
  get_message_typesupport_handle_function,
  &tower_interfaces__msg__PieceArray__get_type_hash,
  &tower_interfaces__msg__PieceArray__get_type_description,
  &tower_interfaces__msg__PieceArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tower_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tower_interfaces, msg, PieceArray)() {
  tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tower_interfaces, msg, Piece)();
  if (!tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_type_support_handle.typesupport_identifier) {
    tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tower_interfaces__msg__PieceArray__rosidl_typesupport_introspection_c__PieceArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
