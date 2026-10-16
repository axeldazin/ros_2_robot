// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/srv/set_building_enabled.h"


#ifndef TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__FUNCTIONS_H_
#define TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__FUNCTIONS_H_

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

#include "tower_interfaces/srv/detail/set_building_enabled__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/SetBuildingEnabled message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tower_interfaces__srv__SetBuildingEnabled_Request
 * )) before or use
 * tower_interfaces__srv__SetBuildingEnabled_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Request__init(tower_interfaces__srv__SetBuildingEnabled_Request * msg);

/// Finalize srv/SetBuildingEnabled message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Request__fini(tower_interfaces__srv__SetBuildingEnabled_Request * msg);

/// Create srv/SetBuildingEnabled message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Request *
tower_interfaces__srv__SetBuildingEnabled_Request__create(void);

/// Destroy srv/SetBuildingEnabled message.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Request__destroy(tower_interfaces__srv__SetBuildingEnabled_Request * msg);

/// Check for srv/SetBuildingEnabled message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Request__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Request * lhs, const tower_interfaces__srv__SetBuildingEnabled_Request * rhs);

/// Copy a srv/SetBuildingEnabled message.
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
tower_interfaces__srv__SetBuildingEnabled_Request__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Request * input,
  tower_interfaces__srv__SetBuildingEnabled_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the number of elements and calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__init(tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__fini(tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * array);

/// Create array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the array and calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__destroy(tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * array);

/// Check for srv/SetBuildingEnabled message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * lhs, const tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * rhs);

/// Copy an array of srv/SetBuildingEnabled messages.
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
tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * input,
  tower_interfaces__srv__SetBuildingEnabled_Request__Sequence * output);

/// Initialize srv/SetBuildingEnabled message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tower_interfaces__srv__SetBuildingEnabled_Response
 * )) before or use
 * tower_interfaces__srv__SetBuildingEnabled_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Response__init(tower_interfaces__srv__SetBuildingEnabled_Response * msg);

/// Finalize srv/SetBuildingEnabled message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Response__fini(tower_interfaces__srv__SetBuildingEnabled_Response * msg);

/// Create srv/SetBuildingEnabled message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Response *
tower_interfaces__srv__SetBuildingEnabled_Response__create(void);

/// Destroy srv/SetBuildingEnabled message.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Response__destroy(tower_interfaces__srv__SetBuildingEnabled_Response * msg);

/// Check for srv/SetBuildingEnabled message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Response__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Response * lhs, const tower_interfaces__srv__SetBuildingEnabled_Response * rhs);

/// Copy a srv/SetBuildingEnabled message.
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
tower_interfaces__srv__SetBuildingEnabled_Response__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Response * input,
  tower_interfaces__srv__SetBuildingEnabled_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the number of elements and calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__init(tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__fini(tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * array);

/// Create array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the array and calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__destroy(tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * array);

/// Check for srv/SetBuildingEnabled message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * lhs, const tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * rhs);

/// Copy an array of srv/SetBuildingEnabled messages.
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
tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * input,
  tower_interfaces__srv__SetBuildingEnabled_Response__Sequence * output);

/// Initialize srv/SetBuildingEnabled message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tower_interfaces__srv__SetBuildingEnabled_Event
 * )) before or use
 * tower_interfaces__srv__SetBuildingEnabled_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Event__init(tower_interfaces__srv__SetBuildingEnabled_Event * msg);

/// Finalize srv/SetBuildingEnabled message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Event__fini(tower_interfaces__srv__SetBuildingEnabled_Event * msg);

/// Create srv/SetBuildingEnabled message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Event *
tower_interfaces__srv__SetBuildingEnabled_Event__create(void);

/// Destroy srv/SetBuildingEnabled message.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Event__destroy(tower_interfaces__srv__SetBuildingEnabled_Event * msg);

/// Check for srv/SetBuildingEnabled message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Event__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Event * lhs, const tower_interfaces__srv__SetBuildingEnabled_Event * rhs);

/// Copy a srv/SetBuildingEnabled message.
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
tower_interfaces__srv__SetBuildingEnabled_Event__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Event * input,
  tower_interfaces__srv__SetBuildingEnabled_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the number of elements and calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__init(tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * array, size_t size);

/// Finalize array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__fini(tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * array);

/// Create array of srv/SetBuildingEnabled messages.
/**
 * It allocates the memory for the array and calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__create(size_t size);

/// Destroy array of srv/SetBuildingEnabled messages.
/**
 * It calls
 * tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
void
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__destroy(tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * array);

/// Check for srv/SetBuildingEnabled message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
bool
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__are_equal(const tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * lhs, const tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * rhs);

/// Copy an array of srv/SetBuildingEnabled messages.
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
tower_interfaces__srv__SetBuildingEnabled_Event__Sequence__copy(
  const tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * input,
  tower_interfaces__srv__SetBuildingEnabled_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__SRV__DETAIL__SET_BUILDING_ENABLED__FUNCTIONS_H_
