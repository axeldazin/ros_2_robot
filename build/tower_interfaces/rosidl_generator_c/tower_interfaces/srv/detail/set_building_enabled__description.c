// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tower_interfaces:srv/SetBuildingEnabled.idl
// generated code does not contain a copyright notice

#include "tower_interfaces/srv/detail/set_building_enabled__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc2, 0x8c, 0x59, 0x3c, 0x79, 0xa0, 0xbb, 0x0b,
      0x59, 0x90, 0x2f, 0x2f, 0xb7, 0x5f, 0xb1, 0x80,
      0x1a, 0xaf, 0xa9, 0xf6, 0xff, 0x11, 0xf1, 0x01,
      0x30, 0x33, 0x3e, 0x15, 0x31, 0x02, 0x4c, 0x0f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd2, 0x8f, 0x5d, 0x37, 0x0d, 0x21, 0x40, 0x53,
      0x20, 0xeb, 0xa6, 0x43, 0x7e, 0xbe, 0x5b, 0x14,
      0xd9, 0x50, 0x03, 0x7a, 0xb7, 0x36, 0xcc, 0xce,
      0xc8, 0x11, 0xf5, 0xe7, 0x95, 0x39, 0xa5, 0x78,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x7e, 0xbf, 0x8f, 0x05, 0xcf, 0xe6, 0x19,
      0x08, 0x1d, 0x47, 0x37, 0xd5, 0x83, 0x7a, 0x9f,
      0x51, 0x9f, 0x9d, 0x5d, 0x37, 0xb2, 0xe5, 0x18,
      0xbd, 0x23, 0xeb, 0x0f, 0x90, 0xe1, 0x4d, 0x01,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tower_interfaces
const rosidl_type_hash_t *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1e, 0x1b, 0x0f, 0x4e, 0x39, 0x0f, 0x5b, 0xf3,
      0x47, 0x28, 0x9b, 0x19, 0xcd, 0xd4, 0xbe, 0x03,
      0x09, 0x7f, 0x55, 0xa1, 0xb6, 0x31, 0x0a, 0x00,
      0xa7, 0xe8, 0x74, 0xdc, 0x2b, 0xfa, 0xd6, 0xed,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char tower_interfaces__srv__SetBuildingEnabled__TYPE_NAME[] = "tower_interfaces/srv/SetBuildingEnabled";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char tower_interfaces__srv__SetBuildingEnabled_Event__TYPE_NAME[] = "tower_interfaces/srv/SetBuildingEnabled_Event";
static char tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME[] = "tower_interfaces/srv/SetBuildingEnabled_Request";
static char tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME[] = "tower_interfaces/srv/SetBuildingEnabled_Response";

// Define type names, field names, and default values
static char tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__request_message[] = "request_message";
static char tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__response_message[] = "response_message";
static char tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tower_interfaces__srv__SetBuildingEnabled__FIELDS[] = {
  {
    {tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tower_interfaces__srv__SetBuildingEnabled_Event__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tower_interfaces__srv__SetBuildingEnabled__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Event__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tower_interfaces__srv__SetBuildingEnabled__TYPE_NAME, 39, 39},
      {tower_interfaces__srv__SetBuildingEnabled__FIELDS, 3, 3},
    },
    {tower_interfaces__srv__SetBuildingEnabled__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tower_interfaces__srv__SetBuildingEnabled_Request__FIELD_NAME__enabled[] = "enabled";

static rosidl_runtime_c__type_description__Field tower_interfaces__srv__SetBuildingEnabled_Request__FIELDS[] = {
  {
    {tower_interfaces__srv__SetBuildingEnabled_Request__FIELD_NAME__enabled, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
      {tower_interfaces__srv__SetBuildingEnabled_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tower_interfaces__srv__SetBuildingEnabled_Response__FIELD_NAME__success[] = "success";
static char tower_interfaces__srv__SetBuildingEnabled_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field tower_interfaces__srv__SetBuildingEnabled_Response__FIELDS[] = {
  {
    {tower_interfaces__srv__SetBuildingEnabled_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
      {tower_interfaces__srv__SetBuildingEnabled_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__info[] = "info";
static char tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__request[] = "request";
static char tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tower_interfaces__srv__SetBuildingEnabled_Event__FIELDS[] = {
  {
    {tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tower_interfaces__srv__SetBuildingEnabled_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tower_interfaces__srv__SetBuildingEnabled_Event__TYPE_NAME, 45, 45},
      {tower_interfaces__srv__SetBuildingEnabled_Event__FIELDS, 3, 3},
    },
    {tower_interfaces__srv__SetBuildingEnabled_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Service /set_building_enabled fourni par supervisor_node.\n"
  "# true : autoriser le lancement de la prochaine manipulation.\n"
  "# false : demander une pause apres la manipulation et sa verification.\n"
  "# Ce service ne remet pas les compteurs a zero et ne relance pas une tour finie.\n"
  "bool enabled\n"
  "---\n"
  "# true : demande acceptee ; false : demande refusee (ex. erreur non resolue).\n"
  "# Une demande acceptee ne signifie pas que la pause est deja effective.\n"
  "# Consulter /tower_state pour connaitre l'etat reel.\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tower_interfaces__srv__SetBuildingEnabled__TYPE_NAME, 39, 39},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 522, 522},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tower_interfaces__srv__SetBuildingEnabled_Request__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tower_interfaces__srv__SetBuildingEnabled_Response__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tower_interfaces__srv__SetBuildingEnabled_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tower_interfaces__srv__SetBuildingEnabled_Event__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tower_interfaces__srv__SetBuildingEnabled__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tower_interfaces__srv__SetBuildingEnabled_Event__get_individual_type_description_source(NULL);
    sources[4] = *tower_interfaces__srv__SetBuildingEnabled_Request__get_individual_type_description_source(NULL);
    sources[5] = *tower_interfaces__srv__SetBuildingEnabled_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tower_interfaces__srv__SetBuildingEnabled_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tower_interfaces__srv__SetBuildingEnabled_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tower_interfaces__srv__SetBuildingEnabled_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tower_interfaces__srv__SetBuildingEnabled_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tower_interfaces__srv__SetBuildingEnabled_Request__get_individual_type_description_source(NULL);
    sources[4] = *tower_interfaces__srv__SetBuildingEnabled_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
