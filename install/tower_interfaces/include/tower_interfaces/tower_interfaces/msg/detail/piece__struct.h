// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tower_interfaces:msg/Piece.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/msg/piece.h"


#ifndef TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_H_
#define TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'color'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'dimensions'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Piece in the package tower_interfaces.
/**
  * Une piece detectee par la perception.
  * Les commentaires precisent le contrat ; les noeuds doivent le verifier.
 */
typedef struct tower_interfaces__msg__Piece
{
  /// Identifiant conserve entre observations tant que la piece est suivie.
  uint32_t id;
  /// Correspondance du projet : red = Cube, blue = Rectangle (pave), green = Cylindre.
  /// unknown reste possible pour une detection non classee.
  rosidl_runtime_c__String color;
  /// Pose du CENTRE de la piece, avec repere et date de la mesure.
  /// Positions en metres ; orientation sous forme de quaternion unitaire.
  geometry_msgs__msg__PoseStamped pose;
  /// Dimensions positives en metres, selon les axes LOCAUX de la piece :
  /// x = longueur, y = largeur, z = hauteur.
  /// Pour un cylindre : x = y = diametre ; z = hauteur selon son axe local.
  geometry_msgs__msg__Vector3 dimensions;
  /// Confiance de detection entre 0.0 et 1.0.
  float confidence;
} tower_interfaces__msg__Piece;

// Struct for a sequence of tower_interfaces__msg__Piece.
typedef struct tower_interfaces__msg__Piece__Sequence
{
  tower_interfaces__msg__Piece * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__msg__Piece__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__MSG__DETAIL__PIECE__STRUCT_H_
