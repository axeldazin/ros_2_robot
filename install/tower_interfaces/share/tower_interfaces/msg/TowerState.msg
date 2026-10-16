# Etat publie sur /tower_state par supervisor_node.
uint8 IDLE=0
uint8 OBSERVING=1
uint8 SELECTING=2
uint8 MANIPULATING=3
uint8 VERIFYING=4
uint8 PAUSED=5
uint8 FINISHED=6
uint8 ERROR=7

# Date de publication ; frame_id = repere de construction de la tour.
std_msgs/Header header
uint8 state

# Nombre de pieces dont le placement a ete verifie.
uint32 placed_count

# Hauteur estimee en metres depuis la surface de support.
float64 height

# Explication lisible : etape courante, raison de pause ou erreur.
string detail
