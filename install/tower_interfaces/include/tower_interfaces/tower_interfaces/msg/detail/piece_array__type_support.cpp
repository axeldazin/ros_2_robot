// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tower_interfaces/msg/detail/piece_array__functions.h"
#include "tower_interfaces/msg/detail/piece_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tower_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PieceArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tower_interfaces::msg::PieceArray(_init);
}

void PieceArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tower_interfaces::msg::PieceArray *>(message_memory);
  typed_message->~PieceArray();
}

size_t size_function__PieceArray__pieces(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tower_interfaces::msg::Piece> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PieceArray__pieces(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tower_interfaces::msg::Piece> *>(untyped_member);
  return &member[index];
}

void * get_function__PieceArray__pieces(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tower_interfaces::msg::Piece> *>(untyped_member);
  return &member[index];
}

void fetch_function__PieceArray__pieces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tower_interfaces::msg::Piece *>(
    get_const_function__PieceArray__pieces(untyped_member, index));
  auto & value = *reinterpret_cast<tower_interfaces::msg::Piece *>(untyped_value);
  value = item;
}

void assign_function__PieceArray__pieces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tower_interfaces::msg::Piece *>(
    get_function__PieceArray__pieces(untyped_member, index));
  const auto & value = *reinterpret_cast<const tower_interfaces::msg::Piece *>(untyped_value);
  item = value;
}

void resize_function__PieceArray__pieces(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tower_interfaces::msg::Piece> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PieceArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces::msg::PieceArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pieces",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tower_interfaces::msg::Piece>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tower_interfaces::msg::PieceArray, pieces),  // bytes offset in struct
    nullptr,  // default value
    size_function__PieceArray__pieces,  // size() function pointer
    get_const_function__PieceArray__pieces,  // get_const(index) function pointer
    get_function__PieceArray__pieces,  // get(index) function pointer
    fetch_function__PieceArray__pieces,  // fetch(index, &value) function pointer
    assign_function__PieceArray__pieces,  // assign(index, value) function pointer
    resize_function__PieceArray__pieces  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PieceArray_message_members = {
  "tower_interfaces::msg",  // message namespace
  "PieceArray",  // message name
  2,  // number of fields
  sizeof(tower_interfaces::msg::PieceArray),
  false,  // has_any_key_member_
  PieceArray_message_member_array,  // message members
  PieceArray_init_function,  // function to initialize message memory (memory has to be allocated)
  PieceArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PieceArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PieceArray_message_members,
  get_message_typesupport_handle_function,
  &tower_interfaces__msg__PieceArray__get_type_hash,
  &tower_interfaces__msg__PieceArray__get_type_description,
  &tower_interfaces__msg__PieceArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tower_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tower_interfaces::msg::PieceArray>()
{
  return &::tower_interfaces::msg::rosidl_typesupport_introspection_cpp::PieceArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tower_interfaces, msg, PieceArray)() {
  return &::tower_interfaces::msg::rosidl_typesupport_introspection_cpp::PieceArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
