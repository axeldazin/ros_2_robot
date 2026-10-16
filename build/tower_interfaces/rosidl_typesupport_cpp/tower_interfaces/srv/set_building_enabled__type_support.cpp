// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "tower_interfaces/srv/detail/set_building_enabled__functions.h"
#include "tower_interfaces/srv/detail/set_building_enabled__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace tower_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetBuildingEnabled_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBuildingEnabled_Request_type_support_ids_t;

static const _SetBuildingEnabled_Request_type_support_ids_t _SetBuildingEnabled_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetBuildingEnabled_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBuildingEnabled_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBuildingEnabled_Request_type_support_symbol_names_t _SetBuildingEnabled_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tower_interfaces, srv, SetBuildingEnabled_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tower_interfaces, srv, SetBuildingEnabled_Request)),
  }
};

typedef struct _SetBuildingEnabled_Request_type_support_data_t
{
  void * data[2];
} _SetBuildingEnabled_Request_type_support_data_t;

static _SetBuildingEnabled_Request_type_support_data_t _SetBuildingEnabled_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBuildingEnabled_Request_message_typesupport_map = {
  2,
  "tower_interfaces",
  &_SetBuildingEnabled_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetBuildingEnabled_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetBuildingEnabled_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBuildingEnabled_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBuildingEnabled_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tower_interfaces__srv__SetBuildingEnabled_Request__get_type_hash,
  &tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description,
  &tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace tower_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Request>()
{
  return &::tower_interfaces::srv::rosidl_typesupport_cpp::SetBuildingEnabled_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tower_interfaces, srv, SetBuildingEnabled_Request)() {
  return get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tower_interfaces/srv/detail/set_building_enabled__functions.h"
// already included above
// #include "tower_interfaces/srv/detail/set_building_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tower_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetBuildingEnabled_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBuildingEnabled_Response_type_support_ids_t;

static const _SetBuildingEnabled_Response_type_support_ids_t _SetBuildingEnabled_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetBuildingEnabled_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBuildingEnabled_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBuildingEnabled_Response_type_support_symbol_names_t _SetBuildingEnabled_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tower_interfaces, srv, SetBuildingEnabled_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tower_interfaces, srv, SetBuildingEnabled_Response)),
  }
};

typedef struct _SetBuildingEnabled_Response_type_support_data_t
{
  void * data[2];
} _SetBuildingEnabled_Response_type_support_data_t;

static _SetBuildingEnabled_Response_type_support_data_t _SetBuildingEnabled_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBuildingEnabled_Response_message_typesupport_map = {
  2,
  "tower_interfaces",
  &_SetBuildingEnabled_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetBuildingEnabled_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetBuildingEnabled_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBuildingEnabled_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBuildingEnabled_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tower_interfaces__srv__SetBuildingEnabled_Response__get_type_hash,
  &tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description,
  &tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace tower_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Response>()
{
  return &::tower_interfaces::srv::rosidl_typesupport_cpp::SetBuildingEnabled_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tower_interfaces, srv, SetBuildingEnabled_Response)() {
  return get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tower_interfaces/srv/detail/set_building_enabled__functions.h"
// already included above
// #include "tower_interfaces/srv/detail/set_building_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tower_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetBuildingEnabled_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBuildingEnabled_Event_type_support_ids_t;

static const _SetBuildingEnabled_Event_type_support_ids_t _SetBuildingEnabled_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetBuildingEnabled_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBuildingEnabled_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBuildingEnabled_Event_type_support_symbol_names_t _SetBuildingEnabled_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tower_interfaces, srv, SetBuildingEnabled_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tower_interfaces, srv, SetBuildingEnabled_Event)),
  }
};

typedef struct _SetBuildingEnabled_Event_type_support_data_t
{
  void * data[2];
} _SetBuildingEnabled_Event_type_support_data_t;

static _SetBuildingEnabled_Event_type_support_data_t _SetBuildingEnabled_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBuildingEnabled_Event_message_typesupport_map = {
  2,
  "tower_interfaces",
  &_SetBuildingEnabled_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetBuildingEnabled_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetBuildingEnabled_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBuildingEnabled_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBuildingEnabled_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tower_interfaces__srv__SetBuildingEnabled_Event__get_type_hash,
  &tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description,
  &tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace tower_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Event>()
{
  return &::tower_interfaces::srv::rosidl_typesupport_cpp::SetBuildingEnabled_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tower_interfaces, srv, SetBuildingEnabled_Event)() {
  return get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "tower_interfaces/srv/detail/set_building_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tower_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetBuildingEnabled_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBuildingEnabled_type_support_ids_t;

static const _SetBuildingEnabled_type_support_ids_t _SetBuildingEnabled_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetBuildingEnabled_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBuildingEnabled_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBuildingEnabled_type_support_symbol_names_t _SetBuildingEnabled_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tower_interfaces, srv, SetBuildingEnabled)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tower_interfaces, srv, SetBuildingEnabled)),
  }
};

typedef struct _SetBuildingEnabled_type_support_data_t
{
  void * data[2];
} _SetBuildingEnabled_type_support_data_t;

static _SetBuildingEnabled_type_support_data_t _SetBuildingEnabled_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBuildingEnabled_service_typesupport_map = {
  2,
  "tower_interfaces",
  &_SetBuildingEnabled_service_typesupport_ids.typesupport_identifier[0],
  &_SetBuildingEnabled_service_typesupport_symbol_names.symbol_name[0],
  &_SetBuildingEnabled_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetBuildingEnabled_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBuildingEnabled_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tower_interfaces::srv::SetBuildingEnabled_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tower_interfaces::srv::SetBuildingEnabled>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tower_interfaces::srv::SetBuildingEnabled>,
  &tower_interfaces__srv__SetBuildingEnabled__get_type_hash,
  &tower_interfaces__srv__SetBuildingEnabled__get_type_description,
  &tower_interfaces__srv__SetBuildingEnabled__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace tower_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tower_interfaces::srv::SetBuildingEnabled>()
{
  return &::tower_interfaces::srv::rosidl_typesupport_cpp::SetBuildingEnabled_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, tower_interfaces, srv, SetBuildingEnabled)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<tower_interfaces::srv::SetBuildingEnabled>();
}

#ifdef __cplusplus
}
#endif
