// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece_array.h"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__FUNCTIONS_H_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "tower_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tower_interfaces/msg/detail/piece_array__struct.h"

/// Initialize msg/PieceArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tower_interfaces__msg__PieceArray
 * )) before or use
 * tower_interfaces__msg__PieceArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__init(tower_interfaces__msg__PieceArray * msg);

/// Finalize msg/PieceArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__msg__PieceArray__fini(tower_interfaces__msg__PieceArray * msg);

/// Create msg/PieceArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tower_interfaces__msg__PieceArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__msg__PieceArray *
tower_interfaces__msg__PieceArray__create(void);

/// Destroy msg/PieceArray message.
/**
 * It calls
 * tower_interfaces__msg__PieceArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__msg__PieceArray__destroy(tower_interfaces__msg__PieceArray * msg);

/// Check for msg/PieceArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__are_equal(const tower_interfaces__msg__PieceArray * lhs, const tower_interfaces__msg__PieceArray * rhs);

/// Copy a msg/PieceArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__copy(
  const tower_interfaces__msg__PieceArray * input,
  tower_interfaces__msg__PieceArray * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__msg__PieceArray__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__msg__PieceArray__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__msg__PieceArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__msg__PieceArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/PieceArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * tower_interfaces__msg__PieceArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__Sequence__init(tower_interfaces__msg__PieceArray__Sequence * array, size_t size);

/// Finalize array of msg/PieceArray messages.
/**
 * It calls
 * tower_interfaces__msg__PieceArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__msg__PieceArray__Sequence__fini(tower_interfaces__msg__PieceArray__Sequence * array);

/// Create array of msg/PieceArray messages.
/**
 * It allocates the memory for the array and calls
 * tower_interfaces__msg__PieceArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__msg__PieceArray__Sequence *
tower_interfaces__msg__PieceArray__Sequence__create(size_t size);

/// Destroy array of msg/PieceArray messages.
/**
 * It calls
 * tower_interfaces__msg__PieceArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__msg__PieceArray__Sequence__destroy(tower_interfaces__msg__PieceArray__Sequence * array);

/// Check for msg/PieceArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__Sequence__are_equal(const tower_interfaces__msg__PieceArray__Sequence * lhs, const tower_interfaces__msg__PieceArray__Sequence * rhs);

/// Copy an array of msg/PieceArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__msg__PieceArray__Sequence__copy(
  const tower_interfaces__msg__PieceArray__Sequence * input,
  tower_interfaces__msg__PieceArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__FUNCTIONS_H_
