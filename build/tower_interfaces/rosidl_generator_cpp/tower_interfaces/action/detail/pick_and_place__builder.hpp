// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tower_interfaces:action/PickAndPlace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tower_interfaces/action/pick_and_place.hpp"


#ifndef TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__BUILDER_HPP_
#define TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tower_interfaces/action/detail/pick_and_place__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_Goal_place_pose
{
public:
  explicit Init_PickAndPlace_Goal_place_pose(::tower_interfaces::action::PickAndPlace_Goal & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_Goal place_pose(::tower_interfaces::action::PickAndPlace_Goal::_place_pose_type arg)
  {
    msg_.place_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Goal msg_;
};

class Init_PickAndPlace_Goal_piece
{
public:
  Init_PickAndPlace_Goal_piece()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_Goal_place_pose piece(::tower_interfaces::action::PickAndPlace_Goal::_piece_type arg)
  {
    msg_.piece = std::move(arg);
    return Init_PickAndPlace_Goal_place_pose(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_Goal>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_Goal_piece();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_Result_message
{
public:
  explicit Init_PickAndPlace_Result_message(::tower_interfaces::action::PickAndPlace_Result & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_Result message(::tower_interfaces::action::PickAndPlace_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Result msg_;
};

class Init_PickAndPlace_Result_success
{
public:
  Init_PickAndPlace_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_Result_message success(::tower_interfaces::action::PickAndPlace_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PickAndPlace_Result_message(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_Result>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_Result_success();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_Feedback_detail
{
public:
  explicit Init_PickAndPlace_Feedback_detail(::tower_interfaces::action::PickAndPlace_Feedback & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_Feedback detail(::tower_interfaces::action::PickAndPlace_Feedback::_detail_type arg)
  {
    msg_.detail = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Feedback msg_;
};

class Init_PickAndPlace_Feedback_stage
{
public:
  Init_PickAndPlace_Feedback_stage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_Feedback_detail stage(::tower_interfaces::action::PickAndPlace_Feedback::_stage_type arg)
  {
    msg_.stage = std::move(arg);
    return Init_PickAndPlace_Feedback_detail(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_Feedback>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_Feedback_stage();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_SendGoal_Request_goal
{
public:
  explicit Init_PickAndPlace_SendGoal_Request_goal(::tower_interfaces::action::PickAndPlace_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_SendGoal_Request goal(::tower_interfaces::action::PickAndPlace_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Request msg_;
};

class Init_PickAndPlace_SendGoal_Request_goal_id
{
public:
  Init_PickAndPlace_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_SendGoal_Request_goal goal_id(::tower_interfaces::action::PickAndPlace_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PickAndPlace_SendGoal_Request_goal(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_SendGoal_Request>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_SendGoal_Request_goal_id();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_SendGoal_Response_stamp
{
public:
  explicit Init_PickAndPlace_SendGoal_Response_stamp(::tower_interfaces::action::PickAndPlace_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_SendGoal_Response stamp(::tower_interfaces::action::PickAndPlace_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Response msg_;
};

class Init_PickAndPlace_SendGoal_Response_accepted
{
public:
  Init_PickAndPlace_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_SendGoal_Response_stamp accepted(::tower_interfaces::action::PickAndPlace_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PickAndPlace_SendGoal_Response_stamp(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_SendGoal_Response>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_SendGoal_Response_accepted();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_SendGoal_Event_response
{
public:
  explicit Init_PickAndPlace_SendGoal_Event_response(::tower_interfaces::action::PickAndPlace_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_SendGoal_Event response(::tower_interfaces::action::PickAndPlace_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Event msg_;
};

class Init_PickAndPlace_SendGoal_Event_request
{
public:
  explicit Init_PickAndPlace_SendGoal_Event_request(::tower_interfaces::action::PickAndPlace_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_PickAndPlace_SendGoal_Event_response request(::tower_interfaces::action::PickAndPlace_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PickAndPlace_SendGoal_Event_response(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Event msg_;
};

class Init_PickAndPlace_SendGoal_Event_info
{
public:
  Init_PickAndPlace_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_SendGoal_Event_request info(::tower_interfaces::action::PickAndPlace_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PickAndPlace_SendGoal_Event_request(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_SendGoal_Event>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_SendGoal_Event_info();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_GetResult_Request_goal_id
{
public:
  Init_PickAndPlace_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tower_interfaces::action::PickAndPlace_GetResult_Request goal_id(::tower_interfaces::action::PickAndPlace_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_GetResult_Request>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_GetResult_Request_goal_id();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_GetResult_Response_result
{
public:
  explicit Init_PickAndPlace_GetResult_Response_result(::tower_interfaces::action::PickAndPlace_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_GetResult_Response result(::tower_interfaces::action::PickAndPlace_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Response msg_;
};

class Init_PickAndPlace_GetResult_Response_status
{
public:
  Init_PickAndPlace_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_GetResult_Response_result status(::tower_interfaces::action::PickAndPlace_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PickAndPlace_GetResult_Response_result(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_GetResult_Response>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_GetResult_Response_status();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_GetResult_Event_response
{
public:
  explicit Init_PickAndPlace_GetResult_Event_response(::tower_interfaces::action::PickAndPlace_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_GetResult_Event response(::tower_interfaces::action::PickAndPlace_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Event msg_;
};

class Init_PickAndPlace_GetResult_Event_request
{
public:
  explicit Init_PickAndPlace_GetResult_Event_request(::tower_interfaces::action::PickAndPlace_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_PickAndPlace_GetResult_Event_response request(::tower_interfaces::action::PickAndPlace_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PickAndPlace_GetResult_Event_response(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Event msg_;
};

class Init_PickAndPlace_GetResult_Event_info
{
public:
  Init_PickAndPlace_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_GetResult_Event_request info(::tower_interfaces::action::PickAndPlace_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PickAndPlace_GetResult_Event_request(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_GetResult_Event>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_GetResult_Event_info();
}

}  // namespace tower_interfaces


namespace tower_interfaces
{

namespace action
{

namespace builder
{

class Init_PickAndPlace_FeedbackMessage_feedback
{
public:
  explicit Init_PickAndPlace_FeedbackMessage_feedback(::tower_interfaces::action::PickAndPlace_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tower_interfaces::action::PickAndPlace_FeedbackMessage feedback(::tower_interfaces::action::PickAndPlace_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_FeedbackMessage msg_;
};

class Init_PickAndPlace_FeedbackMessage_goal_id
{
public:
  Init_PickAndPlace_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlace_FeedbackMessage_feedback goal_id(::tower_interfaces::action::PickAndPlace_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PickAndPlace_FeedbackMessage_feedback(msg_);
  }

private:
  ::tower_interfaces::action::PickAndPlace_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tower_interfaces::action::PickAndPlace_FeedbackMessage>()
{
  return tower_interfaces::action::builder::Init_PickAndPlace_FeedbackMessage_goal_id();
}

}  // namespace tower_interfaces

#endif  // TOWER_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__BUILDER_HPP_
