// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice
#include "tower_interfaces/msg/detail/piece_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pieces`
#include "tower_interfaces/msg/detail/piece__functions.h"

bool
tower_interfaces__msg__PieceArray__init(tower_interfaces__msg__PieceArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tower_interfaces__msg__PieceArray__fini(msg);
    return false;
  }
  // pieces
  if (!tower_interfaces__msg__Piece__Sequence__init(&msg->pieces, 0)) {
    tower_interfaces__msg__PieceArray__fini(msg);
    return false;
  }
  return true;
}

void
tower_interfaces__msg__PieceArray__fini(tower_interfaces__msg__PieceArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pieces
  tower_interfaces__msg__Piece__Sequence__fini(&msg->pieces);
}

bool
tower_interfaces__msg__PieceArray__are_equal(const tower_interfaces__msg__PieceArray * lhs, const tower_interfaces__msg__PieceArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // pieces
  if (!tower_interfaces__msg__Piece__Sequence__are_equal(
      &(lhs->pieces), &(rhs->pieces)))
  {
    return false;
  }
  return true;
}

bool
tower_interfaces__msg__PieceArray__copy(
  const tower_interfaces__msg__PieceArray * input,
  tower_interfaces__msg__PieceArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // pieces
  if (!tower_interfaces__msg__Piece__Sequence__copy(
      &(input->pieces), &(output->pieces)))
  {
    return false;
  }
  return true;
}

tower_interfaces__msg__PieceArray *
tower_interfaces__msg__PieceArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__PieceArray * msg = (tower_interfaces__msg__PieceArray *)allocator.allocate(sizeof(tower_interfaces__msg__PieceArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tower_interfaces__msg__PieceArray));
  bool success = tower_interfaces__msg__PieceArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tower_interfaces__msg__PieceArray__destroy(tower_interfaces__msg__PieceArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tower_interfaces__msg__PieceArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tower_interfaces__msg__PieceArray__Sequence__init(tower_interfaces__msg__PieceArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__PieceArray * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tower_interfaces__msg__PieceArray)) {
      return false;
    }
    data = (tower_interfaces__msg__PieceArray *)allocator.zero_allocate(size, sizeof(tower_interfaces__msg__PieceArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tower_interfaces__msg__PieceArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tower_interfaces__msg__PieceArray__fini(&data[i - 1]);
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
tower_interfaces__msg__PieceArray__Sequence__fini(tower_interfaces__msg__PieceArray__Sequence * array)
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
      tower_interfaces__msg__PieceArray__fini(&array->data[i]);
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

tower_interfaces__msg__PieceArray__Sequence *
tower_interfaces__msg__PieceArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__PieceArray__Sequence * array = (tower_interfaces__msg__PieceArray__Sequence *)allocator.allocate(sizeof(tower_interfaces__msg__PieceArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tower_interfaces__msg__PieceArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tower_interfaces__msg__PieceArray__Sequence__destroy(tower_interfaces__msg__PieceArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tower_interfaces__msg__PieceArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tower_interfaces__msg__PieceArray__Sequence__are_equal(const tower_interfaces__msg__PieceArray__Sequence * lhs, const tower_interfaces__msg__PieceArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tower_interfaces__msg__PieceArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tower_interfaces__msg__PieceArray__Sequence__copy(
  const tower_interfaces__msg__PieceArray__Sequence * input,
  tower_interfaces__msg__PieceArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tower_interfaces__msg__PieceArray)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tower_interfaces__msg__PieceArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tower_interfaces__msg__PieceArray * data =
      (tower_interfaces__msg__PieceArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tower_interfaces__msg__PieceArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tower_interfaces__msg__PieceArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tower_interfaces__msg__PieceArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
