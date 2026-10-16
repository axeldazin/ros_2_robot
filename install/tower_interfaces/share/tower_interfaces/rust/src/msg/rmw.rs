#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__Piece() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__msg__Piece__init(msg: *mut Piece) -> bool;
    fn tower_interfaces__msg__Piece__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Piece>, size: usize) -> bool;
    fn tower_interfaces__msg__Piece__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Piece>);
    fn tower_interfaces__msg__Piece__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Piece>, out_seq: *mut rosidl_runtime_rs::Sequence<Piece>) -> bool;
}

// Corresponds to tower_interfaces__msg__Piece
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Une piece detectee par la perception.
/// Les commentaires precisent le contrat ; les noeuds doivent le verifier.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Piece {
    /// Identifiant conserve entre observations tant que la piece est suivie.
    pub id: u32,

    /// Correspondance du projet : red = Cube, blue = Rectangle (pave), green = Cylindre.
    /// unknown reste possible pour une detection non classee.
    pub color: rosidl_runtime_rs::String,

    /// Pose du CENTRE de la piece, avec repere et date de la mesure.
    /// Positions en metres ; orientation sous forme de quaternion unitaire.
    pub pose: geometry_msgs::msg::rmw::PoseStamped,

    /// Dimensions positives en metres, selon les axes LOCAUX de la piece :
    /// x = longueur, y = largeur, z = hauteur.
    /// Pour un cylindre : x = y = diametre ; z = hauteur selon son axe local.
    pub dimensions: geometry_msgs::msg::rmw::Vector3,

    /// Confiance de detection entre 0.0 et 1.0.
    pub confidence: f32,

}



impl Default for Piece {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__msg__Piece__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__msg__Piece__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Piece {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__Piece__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__Piece__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__Piece__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Piece {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Piece where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/msg/Piece";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__Piece() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__PieceArray() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__msg__PieceArray__init(msg: *mut PieceArray) -> bool;
    fn tower_interfaces__msg__PieceArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PieceArray>, size: usize) -> bool;
    fn tower_interfaces__msg__PieceArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PieceArray>);
    fn tower_interfaces__msg__PieceArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PieceArray>, out_seq: *mut rosidl_runtime_rs::Sequence<PieceArray>) -> bool;
}

// Corresponds to tower_interfaces__msg__PieceArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Observation publiee sur /detected_pieces par perception_node.
/// Le header permet de dater aussi une observation sans aucune piece.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PieceArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Toutes les poses utilisent le meme repere et la meme date que header.
    /// Une liste vide signifie : aucune piece detectee dans cette observation.
    pub pieces: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Piece>,

}



impl Default for PieceArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__msg__PieceArray__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__msg__PieceArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PieceArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__PieceArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__PieceArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__PieceArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PieceArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PieceArray where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/msg/PieceArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__PieceArray() }
  }
}


#[link(name = "tower_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__TowerState() -> *const std::ffi::c_void;
}

#[link(name = "tower_interfaces__rosidl_generator_c")]
extern "C" {
    fn tower_interfaces__msg__TowerState__init(msg: *mut TowerState) -> bool;
    fn tower_interfaces__msg__TowerState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TowerState>, size: usize) -> bool;
    fn tower_interfaces__msg__TowerState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TowerState>);
    fn tower_interfaces__msg__TowerState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TowerState>, out_seq: *mut rosidl_runtime_rs::Sequence<TowerState>) -> bool;
}

// Corresponds to tower_interfaces__msg__TowerState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Etat publie sur /tower_state par supervisor_node.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TowerState {
    /// Date de publication ; frame_id = repere de construction de la tour.
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,

    /// Nombre de pieces dont le placement a ete verifie.
    pub placed_count: u32,

    /// Hauteur estimee en metres depuis la surface de support.
    pub height: f64,

    /// Explication lisible : etape courante, raison de pause ou erreur.
    pub detail: rosidl_runtime_rs::String,

}

impl TowerState {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const IDLE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OBSERVING: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SELECTING: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MANIPULATING: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VERIFYING: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PAUSED: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FINISHED: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ERROR: u8 = 7;

}


impl Default for TowerState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tower_interfaces__msg__TowerState__init(&mut msg as *mut _) {
        panic!("Call to tower_interfaces__msg__TowerState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TowerState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__TowerState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__TowerState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tower_interfaces__msg__TowerState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TowerState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TowerState where Self: Sized {
  const TYPE_NAME: &'static str = "tower_interfaces/msg/TowerState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tower_interfaces__msg__TowerState() }
  }
}


