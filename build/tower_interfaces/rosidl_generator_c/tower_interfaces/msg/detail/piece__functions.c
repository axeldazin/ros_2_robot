// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice
#include "tower_interfaces/msg/detail/piece__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `dimensions`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
tower_interfaces__msg__Piece__init(tower_interfaces__msg__Piece * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    tower_interfaces__msg__Piece__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    tower_interfaces__msg__Piece__fini(msg);
    return false;
  }
  // dimensions
  if (!geometry_msgs__msg__Vector3__init(&msg->dimensions)) {
    tower_interfaces__msg__Piece__fini(msg);
    return false;
  }
  // confidence
  return true;
}

void
tower_interfaces__msg__Piece__fini(tower_interfaces__msg__Piece * msg)
{
  if (!msg) {
    return;
  }
  // id
  // color
  rosidl_runtime_c__String__fini(&msg->color);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
  // dimensions
  geometry_msgs__msg__Vector3__fini(&msg->dimensions);
  // confidence
}

bool
tower_interfaces__msg__Piece__are_equal(const tower_interfaces__msg__Piece * lhs, const tower_interfaces__msg__Piece * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // dimensions
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->dimensions), &(rhs->dimensions)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
tower_interfaces__msg__Piece__copy(
  const tower_interfaces__msg__Piece * input,
  tower_interfaces__msg__Piece * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // dimensions
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->dimensions), &(output->dimensions)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  return true;
}

tower_interfaces__msg__Piece *
tower_interfaces__msg__Piece__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__Piece * msg = (tower_interfaces__msg__Piece *)allocator.allocate(sizeof(tower_interfaces__msg__Piece), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tower_interfaces__msg__Piece));
  bool success = tower_interfaces__msg__Piece__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tower_interfaces__msg__Piece__destroy(tower_interfaces__msg__Piece * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tower_interfaces__msg__Piece__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tower_interfaces__msg__Piece__Sequence__init(tower_interfaces__msg__Piece__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__Piece * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tower_interfaces__msg__Piece)) {
      return false;
    }
    data = (tower_interfaces__msg__Piece *)allocator.zero_allocate(size, sizeof(tower_interfaces__msg__Piece), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tower_interfaces__msg__Piece__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tower_interfaces__msg__Piece__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tower_interfaces__msg__Piece__Sequence__fini(tower_interfaces__msg__Piece__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tower_interfaces__msg__Piece__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tower_interfaces__msg__Piece__Sequence *
tower_interfaces__msg__Piece__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__Piece__Sequence * array = (tower_interfaces__msg__Piece__Sequence *)allocator.allocate(sizeof(tower_interfaces__msg__Piece__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tower_interfaces__msg__Piece__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tower_interfaces__msg__Piece__Sequence__destroy(tower_interfaces__msg__Piece__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tower_interfaces__msg__Piece__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tower_interfaces__msg__Piece__Sequence__are_equal(const tower_interfaces__msg__Piece__Sequence * lhs, const tower_interfaces__msg__Piece__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tower_interfaces__msg__Piece__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tower_interfaces__msg__Piece__Sequence__copy(
  const tower_interfaces__msg__Piece__Sequence * input,
  tower_interfaces__msg__Piece__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tower_interfaces__msg__Piece)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tower_interfaces__msg__Piece);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tower_interfaces__msg__Piece * data =
      (tower_interfaces__msg__Piece *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tower_interfaces__msg__Piece__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tower_interfaces__msg__Piece__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tower_interfaces__msg__Piece__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
