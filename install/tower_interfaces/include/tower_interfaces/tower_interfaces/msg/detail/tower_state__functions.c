// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tower_interfaces:msg/TowerState.idl
// generated code does not contain a copyright notice
#include "tower_interfaces/msg/detail/tower_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detail`
#include "rosidl_runtime_c/string_functions.h"

bool
tower_interfaces__msg__TowerState__init(tower_interfaces__msg__TowerState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tower_interfaces__msg__TowerState__fini(msg);
    return false;
  }
  // state
  // placed_count
  // height
  // detail
  if (!rosidl_runtime_c__String__init(&msg->detail)) {
    tower_interfaces__msg__TowerState__fini(msg);
    return false;
  }
  return true;
}

void
tower_interfaces__msg__TowerState__fini(tower_interfaces__msg__TowerState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  // placed_count
  // height
  // detail
  rosidl_runtime_c__String__fini(&msg->detail);
}

bool
tower_interfaces__msg__TowerState__are_equal(const tower_interfaces__msg__TowerState * lhs, const tower_interfaces__msg__TowerState * rhs)
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
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // placed_count
  if (lhs->placed_count != rhs->placed_count) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // detail
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->detail), &(rhs->detail)))
  {
    return false;
  }
  return true;
}

bool
tower_interfaces__msg__TowerState__copy(
  const tower_interfaces__msg__TowerState * input,
  tower_interfaces__msg__TowerState * output)
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
  // state
  output->state = input->state;
  // placed_count
  output->placed_count = input->placed_count;
  // height
  output->height = input->height;
  // detail
  if (!rosidl_runtime_c__String__copy(
      &(input->detail), &(output->detail)))
  {
    return false;
  }
  return true;
}

tower_interfaces__msg__TowerState *
tower_interfaces__msg__TowerState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__TowerState * msg = (tower_interfaces__msg__TowerState *)allocator.allocate(sizeof(tower_interfaces__msg__TowerState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tower_interfaces__msg__TowerState));
  bool success = tower_interfaces__msg__TowerState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tower_interfaces__msg__TowerState__destroy(tower_interfaces__msg__TowerState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tower_interfaces__msg__TowerState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tower_interfaces__msg__TowerState__Sequence__init(tower_interfaces__msg__TowerState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__TowerState * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tower_interfaces__msg__TowerState)) {
      return false;
    }
    data = (tower_interfaces__msg__TowerState *)allocator.zero_allocate(size, sizeof(tower_interfaces__msg__TowerState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tower_interfaces__msg__TowerState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tower_interfaces__msg__TowerState__fini(&data[i - 1]);
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
tower_interfaces__msg__TowerState__Sequence__fini(tower_interfaces__msg__TowerState__Sequence * array)
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
      tower_interfaces__msg__TowerState__fini(&array->data[i]);
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

tower_interfaces__msg__TowerState__Sequence *
tower_interfaces__msg__TowerState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tower_interfaces__msg__TowerState__Sequence * array = (tower_interfaces__msg__TowerState__Sequence *)allocator.allocate(sizeof(tower_interfaces__msg__TowerState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tower_interfaces__msg__TowerState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tower_interfaces__msg__TowerState__Sequence__destroy(tower_interfaces__msg__TowerState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tower_interfaces__msg__TowerState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tower_interfaces__msg__TowerState__Sequence__are_equal(const tower_interfaces__msg__TowerState__Sequence * lhs, const tower_interfaces__msg__TowerState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tower_interfaces__msg__TowerState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tower_interfaces__msg__TowerState__Sequence__copy(
  const tower_interfaces__msg__TowerState__Sequence * input,
  tower_interfaces__msg__TowerState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tower_interfaces__msg__TowerState)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tower_interfaces__msg__TowerState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tower_interfaces__msg__TowerState * data =
      (tower_interfaces__msg__TowerState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tower_interfaces__msg__TowerState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tower_interfaces__msg__TowerState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tower_interfaces__msg__TowerState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
