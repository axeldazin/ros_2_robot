// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tower_interfaces:msg/TowerState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/tower_state.h"


#ifndef TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_H_
#define TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'IDLE'.
enum
{
  tower_interfaces__msg__TowerState__IDLE = 0
};

/// Constant 'OBSERVING'.
enum
{
  tower_interfaces__msg__TowerState__OBSERVING = 1
};

/// Constant 'SELECTING'.
enum
{
  tower_interfaces__msg__TowerState__SELECTING = 2
};

/// Constant 'MANIPULATING'.
enum
{
  tower_interfaces__msg__TowerState__MANIPULATING = 3
};

/// Constant 'VERIFYING'.
enum
{
  tower_interfaces__msg__TowerState__VERIFYING = 4
};

/// Constant 'PAUSED'.
enum
{
  tower_interfaces__msg__TowerState__PAUSED = 5
};

/// Constant 'FINISHED'.
enum
{
  tower_interfaces__msg__TowerState__FINISHED = 6
};

/// Constant 'ERROR'.
enum
{
  tower_interfaces__msg__TowerState__ERROR = 7
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detail'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TowerState in the package tower_interfaces.
/**
  * Etat publie sur /tower_state par supervisor_node.
 */
typedef struct tower_interfaces__msg__TowerState
{
  /// Date de publication ; frame_id = repere de construction de la tour.
  std_msgs__msg__Header header;
  uint8_t state;
  /// Nombre de pieces dont le placement a ete verifie.
  uint32_t placed_count;
  /// Hauteur estimee en metres depuis la surface de support.
  double height;
  /// Explication lisible : etape courante, raison de pause ou erreur.
  rosidl_runtime_c__String detail;
} tower_interfaces__msg__TowerState;

// Struct for a sequence of tower_interfaces__msg__TowerState.
typedef struct tower_interfaces__msg__TowerState__Sequence
{
  tower_interfaces__msg__TowerState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__msg__TowerState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__MSG__DETAIL__TOWER_STATE__STRUCT_H_
