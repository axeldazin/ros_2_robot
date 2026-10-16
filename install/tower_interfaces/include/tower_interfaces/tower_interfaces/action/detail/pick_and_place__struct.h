// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tower_interfaces:action/PickAndPlace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/action/pick_and_place.h"


#ifndef TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_
#define TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'piece'
#include "tower_interfaces/msg/detail/piece__struct.h"
// Member 'place_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_Goal
{
  tower_interfaces__msg__Piece piece;
  /// Pose desiree du CENTRE de l'objet apres la depose.
  /// Ce n'est pas la pose de la pince : manipulation_node calcule le decalage.
  /// Le serveur transforme les poses vers son repere de planification avec TF.
  geometry_msgs__msg__PoseStamped place_pose;
} tower_interfaces__action__PickAndPlace_Goal;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_Goal.
typedef struct tower_interfaces__action__PickAndPlace_Goal__Sequence
{
  tower_interfaces__action__PickAndPlace_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_Result
{
  bool success;
  rosidl_runtime_c__String message;
} tower_interfaces__action__PickAndPlace_Result;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_Result.
typedef struct tower_interfaces__action__PickAndPlace_Result__Sequence
{
  tower_interfaces__action__PickAndPlace_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_Result__Sequence;

// Constants defined in the message

/// Constant 'APPROACHING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__APPROACHING = 0
};

/// Constant 'GRASPING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__GRASPING = 1
};

/// Constant 'LIFTING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__LIFTING = 2
};

/// Constant 'TRANSPORTING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__TRANSPORTING = 3
};

/// Constant 'PLACING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__PLACING = 4
};

/// Constant 'RETREATING'.
enum
{
  tower_interfaces__action__PickAndPlace_Feedback__RETREATING = 5
};

// Include directives for member types
// Member 'detail'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_Feedback
{
  uint8_t stage;
  rosidl_runtime_c__String detail;
} tower_interfaces__action__PickAndPlace_Feedback;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_Feedback.
typedef struct tower_interfaces__action__PickAndPlace_Feedback__Sequence
{
  tower_interfaces__action__PickAndPlace_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "tower_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  tower_interfaces__action__PickAndPlace_Goal goal;
} tower_interfaces__action__PickAndPlace_SendGoal_Request;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_SendGoal_Request.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence
{
  tower_interfaces__action__PickAndPlace_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} tower_interfaces__action__PickAndPlace_SendGoal_Response;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_SendGoal_Response.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence
{
  tower_interfaces__action__PickAndPlace_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tower_interfaces__action__PickAndPlace_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tower_interfaces__action__PickAndPlace_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence request;
  tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence response;
} tower_interfaces__action__PickAndPlace_SendGoal_Event;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_SendGoal_Event.
typedef struct tower_interfaces__action__PickAndPlace_SendGoal_Event__Sequence
{
  tower_interfaces__action__PickAndPlace_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} tower_interfaces__action__PickAndPlace_GetResult_Request;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_GetResult_Request.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence
{
  tower_interfaces__action__PickAndPlace_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "tower_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Response
{
  int8_t status;
  tower_interfaces__action__PickAndPlace_Result result;
} tower_interfaces__action__PickAndPlace_GetResult_Response;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_GetResult_Response.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence
{
  tower_interfaces__action__PickAndPlace_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tower_interfaces__action__PickAndPlace_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tower_interfaces__action__PickAndPlace_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence request;
  tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence response;
} tower_interfaces__action__PickAndPlace_GetResult_Event;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_GetResult_Event.
typedef struct tower_interfaces__action__PickAndPlace_GetResult_Event__Sequence
{
  tower_interfaces__action__PickAndPlace_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "tower_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package tower_interfaces.
typedef struct tower_interfaces__action__PickAndPlace_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  tower_interfaces__action__PickAndPlace_Feedback feedback;
} tower_interfaces__action__PickAndPlace_FeedbackMessage;

// Struct for a sequence of tower_interfaces__action__PickAndPlace_FeedbackMessage.
typedef struct tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence
{
  tower_interfaces__action__PickAndPlace_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_
