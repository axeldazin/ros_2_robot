# Observation publiee sur /detected_pieces par perception_node.
# Le header permet de dater aussi une observation sans aucune piece.
std_msgs/Header header

# Toutes les poses utilisent le meme repere et la meme date que header.
# Une liste vide signifie : aucune piece detectee dans cette observation.
tower_interfaces/Piece[] pieces
