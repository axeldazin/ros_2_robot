
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tower_interfaces__action__PickAndPlace_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub piece: super::msg::Piece,

    /// Pose desiree du CENTRE de l'objet apres la depose.
    /// Ce n'est pas la pose de la pince : manipulation_node calcule le decalage.
    /// Le serveur transforme les poses vers son repere de planification avec TF.
    pub place_pose: geometry_msgs::msg::PoseStamped,

}



impl Default for PickAndPlace_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Goal {
  type RmwMsg = super::action::rmw::PickAndPlace_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        piece: super::msg::Piece::into_rmw_message(std::borrow::Cow::Owned(msg.piece)).into_owned(),
        place_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.place_pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        piece: super::msg::Piece::into_rmw_message(std::borrow::Cow::Borrowed(&msg.piece)).into_owned(),
        place_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.place_pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      piece: super::msg::Piece::from_rmw_message(msg.piece),
      place_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.place_pose),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for PickAndPlace_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_Result::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Result {
  type RmwMsg = super::action::rmw::PickAndPlace_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detail: std::string::String,

}

impl PickAndPlace_Feedback {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const APPROACHING: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GRASPING: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LIFTING: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSPORTING: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PLACING: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETREATING: u8 = 5;

}


impl Default for PickAndPlace_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Feedback {
  type RmwMsg = super::action::rmw::PickAndPlace_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stage: msg.stage,
        detail: msg.detail.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      stage: msg.stage,
        detail: msg.detail.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stage: msg.stage,
      detail: msg.detail.to_string(),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::PickAndPlace_Feedback,

}



impl Default for PickAndPlace_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_FeedbackMessage {
  type RmwMsg = super::action::rmw::PickAndPlace_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::PickAndPlace_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::PickAndPlace_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::PickAndPlace_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to tower_interfaces__action__PickAndPlace_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::PickAndPlace_Goal,

}



impl Default for PickAndPlace_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_SendGoal_Request {
  type RmwMsg = super::action::rmw::PickAndPlace_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::PickAndPlace_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::PickAndPlace_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::PickAndPlace_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for PickAndPlace_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_SendGoal_Response {
  type RmwMsg = super::action::rmw::PickAndPlace_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for PickAndPlace_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_GetResult_Request {
  type RmwMsg = super::action::rmw::PickAndPlace_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to tower_interfaces__action__PickAndPlace_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::PickAndPlace_Result,

}



impl Default for PickAndPlace_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PickAndPlace_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_GetResult_Response {
  type RmwMsg = super::action::rmw::PickAndPlace_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::PickAndPlace_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::PickAndPlace_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::PickAndPlace_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to tower_interfaces__action__PickAndPlace_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct PickAndPlace_SendGoal;

impl rosidl_runtime_rs::Service for PickAndPlace_SendGoal {
    type Request = PickAndPlace_SendGoal_Request;
    type Response = PickAndPlace_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal() }
    }
}




#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to tower_interfaces__action__PickAndPlace_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct PickAndPlace_GetResult;

impl rosidl_runtime_rs::Service for PickAndPlace_GetResult {
    type Request = PickAndPlace_GetResult_Request;
    type Response = PickAndPlace_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult() }
    }
}






#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__tower_interfaces__action__PickAndPlace() -> *const std::ffi::c_void;
}

// Corresponds to tower_interfaces__action__PickAndPlace
#[allow(missing_docs, non_camel_case_types)]
pub struct PickAndPlace;

impl rosidl_runtime_rs::Action for PickAndPlace {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = PickAndPlace_Goal;

  /// The result message defined in the action definition.
  type Result = PickAndPlace_Result;

  /// The feedback message defined in the action definition.
  type Feedback = PickAndPlace_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::PickAndPlace_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::PickAndPlace_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::PickAndPlace_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__tower_interfaces__action__PickAndPlace() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::PickAndPlace_Goal,
  ) -> super::action::rmw::PickAndPlace_SendGoal_Request {
   super::action::rmw::PickAndPlace_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::PickAndPlace_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::PickAndPlace_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::PickAndPlace_SendGoal_Response {
   super::action::rmw::PickAndPlace_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::PickAndPlace_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::PickAndPlace_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::PickAndPlace_Feedback,
  ) -> super::action::rmw::PickAndPlace_FeedbackMessage {
    let mut message = super::action::rmw::PickAndPlace_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::PickAndPlace_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::PickAndPlace_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::PickAndPlace_GetResult_Request {
   super::action::rmw::PickAndPlace_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::PickAndPlace_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::PickAndPlace_Result,
  ) -> super::action::rmw::PickAndPlace_GetResult_Response {
   super::action::rmw::PickAndPlace_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::PickAndPlace_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::PickAndPlace_Result,
  ) {
    (response.status, response.result)
  }
}


