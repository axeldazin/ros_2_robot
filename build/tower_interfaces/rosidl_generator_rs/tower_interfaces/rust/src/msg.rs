#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tower_interfaces__msg__Piece
/// Une piece detectee par la perception.
/// Les commentaires precisent le contrat ; les noeuds doivent le verifier.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Piece {
    /// Identifiant conserve entre observations tant que la piece est suivie.
    pub id: u32,

    /// Correspondance du projet : red = Cube, blue = Rectangle (pave), green = Cylindre.
    /// unknown reste possible pour une detection non classee.
    pub color: std::string::String,

    /// Pose du CENTRE de la piece, avec repere et date de la mesure.
    /// Positions en metres ; orientation sous forme de quaternion unitaire.
    pub pose: geometry_msgs::msg::PoseStamped,

    /// Dimensions positives en metres, selon les axes LOCAUX de la piece :
    /// x = longueur, y = largeur, z = hauteur.
    /// Pour un cylindre : x = y = diametre ; z = hauteur selon son axe local.
    pub dimensions: geometry_msgs::msg::Vector3,

    /// Confiance de detection entre 0.0 et 1.0.
    pub confidence: f32,

}



impl Default for Piece {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Piece::default())
  }
}

impl rosidl_runtime_rs::Message for Piece {
  type RmwMsg = super::msg::rmw::Piece;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        color: msg.color.as_str().into(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        dimensions: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.dimensions)).into_owned(),
        confidence: msg.confidence,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        color: msg.color.as_str().into(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        dimensions: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.dimensions)).into_owned(),
      confidence: msg.confidence,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      color: msg.color.to_string(),
      pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.pose),
      dimensions: geometry_msgs::msg::Vector3::from_rmw_message(msg.dimensions),
      confidence: msg.confidence,
    }
  }
}


// Corresponds to tower_interfaces__msg__PieceArray
/// Observation publiee sur /detected_pieces par perception_node.
/// Le header permet de dater aussi une observation sans aucune piece.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PieceArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Toutes les poses utilisent le meme repere et la meme date que header.
    /// Une liste vide signifie : aucune piece detectee dans cette observation.
    pub pieces: Vec<super::msg::Piece>,

}



impl Default for PieceArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PieceArray::default())
  }
}

impl rosidl_runtime_rs::Message for PieceArray {
  type RmwMsg = super::msg::rmw::PieceArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        pieces: msg.pieces
          .into_iter()
          .map(|elem| super::msg::Piece::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        pieces: msg.pieces
          .iter()
          .map(|elem| super::msg::Piece::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      pieces: msg.pieces
          .into_iter()
          .map(super::msg::Piece::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tower_interfaces__msg__TowerState
/// Etat publie sur /tower_state par supervisor_node.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TowerState {
    /// Date de publication ; frame_id = repere de construction de la tour.
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,

    /// Nombre de pieces dont le placement a ete verifie.
    pub placed_count: u32,

    /// Hauteur estimee en metres depuis la surface de support.
    pub height: f64,

    /// Explication lisible : etape courante, raison de pause ou erreur.
    pub detail: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TowerState::default())
  }
}

impl rosidl_runtime_rs::Message for TowerState {
  type RmwMsg = super::msg::rmw::TowerState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state,
        placed_count: msg.placed_count,
        height: msg.height,
        detail: msg.detail.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      state: msg.state,
      placed_count: msg.placed_count,
      height: msg.height,
        detail: msg.detail.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state,
      placed_count: msg.placed_count,
      height: msg.height,
      detail: msg.detail.to_string(),
    }
  }
}


