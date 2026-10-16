// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice
#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tower_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tower_interfaces/msg/detail/piece__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
bool cdr_serialize_tower_interfaces__msg__Piece(
  const tower_interfaces__msg__Piece * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
bool cdr_deserialize_tower_interfaces__msg__Piece(
  eprosima::fastcdr::Cdr &,
  tower_interfaces__msg__Piece * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
size_t get_serialized_size_tower_interfaces__msg__Piece(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
size_t max_serialized_size_tower_interfaces__msg__Piece(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
bool cdr_serialize_key_tower_interfaces__msg__Piece(
  const tower_interfaces__msg__Piece * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
size_t get_serialized_size_key_tower_interfaces__msg__Piece(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
size_t max_serialized_size_key_tower_interfaces__msg__Piece(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tower_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tower_interfaces, msg, Piece)();

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
