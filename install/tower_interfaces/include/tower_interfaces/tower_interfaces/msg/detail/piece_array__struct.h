// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tower_interfaces:msg/PieceArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece_array.h"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_H_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pieces'
#include "tower_interfaces/msg/detail/piece__struct.h"

/// Struct defined in msg/PieceArray in the package tower_interfaces.
/**
  * Observation publiee sur /detected_pieces par perception_node.
  * Le header permet de dater aussi une observation sans aucune piece.
 */
typedef struct tower_interfaces__msg__PieceArray
{
  std_msgs__msg__Header header;
  /// Toutes les poses utilisent le meme repere et la meme date que header.
  /// Une liste vide signifie : aucune piece detectee dans cette observation.
  tower_interfaces__msg__Piece__Sequence pieces;
} tower_interfaces__msg__PieceArray;

// Struct for a sequence of tower_interfaces__msg__PieceArray.
typedef struct tower_interfaces__msg__PieceArray__Sequence
{
  tower_interfaces__msg__PieceArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__msg__PieceArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE_ARRAY__STRUCT_H_
