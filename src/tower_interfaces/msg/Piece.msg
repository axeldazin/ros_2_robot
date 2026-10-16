# Une piece detectee par la perception.
# Les commentaires precisent le contrat ; les noeuds doivent le verifier.

# Identifiant conserve entre observations tant que la piece est suivie.
uint32 id

# Correspondance du projet : red = Cube, blue = Rectangle (pave), green = Cylindre.
# unknown reste possible pour une detection non classee.
string color

# Pose du CENTRE de la piece, avec repere et date de la mesure.
# Positions en metres ; orientation sous forme de quaternion unitaire.
geometry_msgs/PoseStamped pose

# Dimensions positives en metres, selon les axes LOCAUX de la piece :
# x = longueur, y = largeur, z = hauteur.
# Pour un cylindre : x = y = diametre ; z = hauteur selon son axe local.
geometry_msgs/Vector3 dimensions

# Confiance de detection entre 0.0 et 1.0.
float32 confidence
