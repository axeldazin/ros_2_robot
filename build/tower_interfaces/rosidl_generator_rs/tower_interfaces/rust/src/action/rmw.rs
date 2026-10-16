
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Goal() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_Goal__init(msg: *mut PickAndPlace_Goal) -> bool;
    fn tower_interfaces__action__PickAndPlace_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Goal>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Goal>);
    fn tower_interfaces__action__PickAndPlace_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Goal>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub piece: super::super::msg::rmw::Piece,

    /// Pose desiree du CENTRE de l'objet apres la depose.
    /// Ce n'est pas la pose de la pince : manipulation_node calcule le decalage.
    /// Le serveur transforme les poses vers son repere de planification avec TF.
    pub place_pose: geometry_msgs::msg::rmw::PoseStamped,

}



impl Default for PickAndPlace_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_Goal__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Goal() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Result() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_Result__init(msg: *mut PickAndPlace_Result) -> bool;
    fn tower_interfaces__action__PickAndPlace_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Result>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Result>);
    fn tower_interfaces__action__PickAndPlace_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Result>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for PickAndPlace_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_Result__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_Result where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Result() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_Feedback__init(msg: *mut PickAndPlace_Feedback) -> bool;
    fn tower_interfaces__action__PickAndPlace_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Feedback>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Feedback>);
    fn tower_interfaces__action__PickAndPlace_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_Feedback>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detail: rosidl_runtime_rs::String,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_Feedback__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_Feedback() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_FeedbackMessage__init(msg: *mut PickAndPlace_FeedbackMessage) -> bool;
    fn tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_FeedbackMessage>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_FeedbackMessage>);
    fn tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_FeedbackMessage>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::PickAndPlace_Feedback,

}



impl Default for PickAndPlace_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_FeedbackMessage() }
  }
}




#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_SendGoal_Request__init(msg: *mut PickAndPlace_SendGoal_Request) -> bool;
    fn tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Request>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Request>);
    fn tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Request>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::PickAndPlace_Goal,

}



impl Default for PickAndPlace_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal_Request() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_SendGoal_Response__init(msg: *mut PickAndPlace_SendGoal_Response) -> bool;
    fn tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Response>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Response>);
    fn tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_SendGoal_Response>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for PickAndPlace_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_SendGoal_Response() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_GetResult_Request__init(msg: *mut PickAndPlace_GetResult_Request) -> bool;
    fn tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Request>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Request>);
    fn tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Request>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for PickAndPlace_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult_Request() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__action__PickAndPlace_GetResult_Response__init(msg: *mut PickAndPlace_GetResult_Response) -> bool;
    fn tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Response>, size: usize) -> bool;
    fn tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Response>);
    fn tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PickAndPlace_GetResult_Response>) -> bool;
}

// Corresponds to tower_interfaces__action__PickAndPlace_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickAndPlace_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::PickAndPlace_Result,

}



impl Default for PickAndPlace_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__action__PickAndPlace_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__action__PickAndPlace_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickAndPlace_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__action__PickAndPlace_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickAndPlace_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickAndPlace_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/action/PickAndPlace_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__action__PickAndPlace_GetResult_Response() }
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


