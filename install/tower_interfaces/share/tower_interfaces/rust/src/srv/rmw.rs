#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__srv__SetBuildingEnabled_Request() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__srv__SetBuildingEnabled_Request__init(msg: *mut SetBuildingEnabled_Request) -> bool;
    fn tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Request>, size: usize) -> bool;
    fn tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Request>);
    fn tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetBuildingEnabled_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Request>) -> bool;
}

// Corresponds to tower_interfaces__srv__SetBuildingEnabled_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetBuildingEnabled_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enabled: bool,

}



impl Default for SetBuildingEnabled_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__srv__SetBuildingEnabled_Request__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__srv__SetBuildingEnabled_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetBuildingEnabled_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetBuildingEnabled_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetBuildingEnabled_Request where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/srv/SetBuildingEnabled_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__srv__SetBuildingEnabled_Request() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__srv__SetBuildingEnabled_Response() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__srv__SetBuildingEnabled_Response__init(msg: *mut SetBuildingEnabled_Response) -> bool;
    fn tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Response>, size: usize) -> bool;
    fn tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Response>);
    fn tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetBuildingEnabled_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetBuildingEnabled_Response>) -> bool;
}

// Corresponds to tower_interfaces__srv__SetBuildingEnabled_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetBuildingEnabled_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SetBuildingEnabled_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__srv__SetBuildingEnabled_Response__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__srv__SetBuildingEnabled_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetBuildingEnabled_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__srv__SetBuildingEnabled_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetBuildingEnabled_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetBuildingEnabled_Response where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/srv/SetBuildingEnabled_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__srv__SetBuildingEnabled_Response() }
  }
}






#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__srv__SetBuildingEnabled() -> *const std::ffi::c_void;
}

// Corresponds to tower_interfaces__srv__SetBuildingEnabled
#[allow(missing_docs, non_camel_case_types)]
pub struct SetBuildingEnabled;

impl rosidl_runtime_rs::Service for SetBuildingEnabled {
    type Request = SetBuildingEnabled_Request;
    type Response = SetBuildingEnabled_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tower_interfaces__srv__SetBuildingEnabled() }
    }
}


