#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to tower_interfaces__srv__SetBuildingEnabled_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetBuildingEnabled_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enabled: bool,

}



impl Default for SetBuildingEnabled_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetBuildingEnabled_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetBuildingEnabled_Request {
  type RmwMsg = super::srv::rmw::SetBuildingEnabled_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        enabled: msg.enabled,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      enabled: msg.enabled,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      enabled: msg.enabled,
    }
  }
}


// Corresponds to tower_interfaces__srv__SetBuildingEnabled_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetBuildingEnabled_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SetBuildingEnabled_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetBuildingEnabled_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetBuildingEnabled_Response {
  type RmwMsg = super::srv::rmw::SetBuildingEnabled_Response;

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


