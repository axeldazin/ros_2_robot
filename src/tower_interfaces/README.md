# tower_interfaces

Ce package définit le vocabulaire commun des nœuds du projet. Il contient les
**structures des données échangées**, sans traitement caméra ni commande du robot.
ROS génère les classes C++ et Python lors de la compilation.

Les classes métier `Piece`, `Cube` rouge, `Rectangle` bleu et `Cylindre` vert sont
définies dans [tower_model](../tower_model/README.md). Sa fonction `to_message`
convertit ces objets C++ vers `tower_interfaces::msg::Piece`.

Les anciens fichiers `sorting.cpp`, `sorting_node.cpp` et `sorting.hpp`, issus
de la copie de l'exemple de tri, ont été retirés de ce package. Les nœuds de
traitement seront développés dans `tower_perception` et `tower_control`.

## Les fichiers

```text
tower_interfaces/
├── msg/
│   ├── Piece.msg                # Une pièce et sa pose mesurée
│   ├── PieceArray.msg           # Les pièces d'une observation
│   └── TowerState.msg           # L'état de construction
├── srv/
│   └── SetBuildingEnabled.srv   # Autoriser la construction / demander une pause
├── action/
│   └── PickAndPlace.action      # Demander une saisie et une dépose
├── CMakeLists.txt               # Déclare les interfaces à générer
└── package.xml                  # Nom du package et dépendances
```

Un fichier `.msg` définit un message. Un fichier `.srv` contient une requête et
une réponse séparées par `---`. Un fichier `.action` contient trois parties :
objectif, résultat et progression, séparées par deux lignes `---`.

## Qui échange quoi ?

| Interface ROS proposée | Type | Émetteur / client | Récepteur / serveur |
|---|---|---|---|
| Topic `/detected_pieces` | `tower_interfaces/msg/PieceArray` | `perception_node` publie | `supervisor_node` s'abonne |
| Topic `/tower_state` | `tower_interfaces/msg/TowerState` | `supervisor_node` publie | Affichage ou suivi s'abonne |
| Service `/set_building_enabled` | `tower_interfaces/srv/SetBuildingEnabled` | Commande utilisateur | `supervisor_node` répond |
| Action `/pick_and_place` | `tower_interfaces/action/PickAndPlace` | `supervisor_node` envoie un objectif | `manipulation_node` exécute et retourne progression et résultat |

Les noms des topics, du service et de l'action sont choisis dans les futurs nœuds.
Les fichiers de ce package définissent leurs **types**, pas leurs noms ni leur
comportement. Compiler ce package ne démarre donc aucun serveur ou publisher.

## Exemple : décrire une pièce

Une pièce bleue de 4 × 4 × 2 cm, dont le centre est à 30 cm devant la base du
robot, se décrit ainsi en Python :

```python
from tower_interfaces.msg import Piece, PieceArray

# Dans la méthode d'un nœud ROS 2 (self est le nœud).
piece = Piece()
piece.id = 1
piece.color = 'blue'
piece.pose.header.frame_id = 'base_link'  # À adapter au repère réel du XARM.
piece.pose.header.stamp = self.get_clock().now().to_msg()
piece.pose.pose.position.x = 0.30
piece.pose.pose.position.y = 0.0
piece.pose.pose.position.z = 0.01  # Exemple : support à z = 0 dans ce repère.
piece.pose.pose.orientation.w = 1.0  # Quaternion identité : aucune rotation.
piece.dimensions.x = 0.04
piece.dimensions.y = 0.04
piece.dimensions.z = 0.02
piece.confidence = 0.95

observation = PieceArray()
observation.header = piece.pose.header
observation.pieces = [piece]
```

Dans cet exemple, la pose est supposée déjà transformée dans le repère du robot.
En fonctionnement réel, le timestamp correspond à la mesure caméra et la
perception utilise TF pour transformer sa pose. Le nom `base_link` est illustratif.

Pour publier depuis un nœud de perception Python :

```python
# À créer une fois dans __init__.
self.pieces_publisher = self.create_publisher(PieceArray, '/detected_pieces', 10)

# À appeler lorsque l'observation est prête.
self.pieces_publisher.publish(observation)
```

Le superviseur pourrait recevoir cette observation avec :

```python
# À créer dans __init__ ; on_pieces est une méthode du superviseur.
self.pieces_subscription = self.create_subscription(
    PieceArray, '/detected_pieces', self.on_pieces, 10
)
```

Ces extraits illustrent l'utilisation des types ; ils ne constituent pas des nœuds
complets. La vision et la stratégie restent à implémenter.

## Exemple : demander une dépose

```python
from geometry_msgs.msg import PoseStamped
from tower_interfaces.action import PickAndPlace

goal = PickAndPlace.Goal()
goal.piece = piece
goal.place_pose = PoseStamped()
goal.place_pose.header = piece.pose.header
goal.place_pose.pose.position.x = 0.40
goal.place_pose.pose.position.y = 0.10
goal.place_pose.pose.position.z = 0.03
goal.place_pose.pose.orientation.w = 1.0
```

Si le support est à `z = 0` et qu'une pièce de 2 cm de haut est déjà posée,
le centre de la deuxième pièce de 2 cm de haut sera à `z = 0.03 m`.
Le serveur calcule la pose de la pince à partir de cette pose d'objet, de la
géométrie de l'outil et de la prise choisie. Le superviseur devra ensuite envoyer
`goal` avec un client d'action ROS 2.

Les constantes du feedback permettent par exemple de signaler
`PickAndPlace.Feedback.GRASPING`. Le résultat `success = true` signifie que la
séquence de manipulation a réussi selon le serveur ; le superviseur passe ensuite
à la vérification du placement avant d'incrémenter `placed_count`.

## Conventions communes

- Les positions, dimensions et hauteurs sont exprimées en **mètres**.
- Les poses décrivent le **centre de l'objet**, avec une orientation en quaternion
  unitaire. Un quaternion laissé entièrement à zéro n'est pas une rotation valide.
- Les dimensions sont mesurées selon les axes locaux de l'objet.
- Chaque pose indique son repère dans `header.frame_id` et sa date dans `header.stamp`.
- Dans une observation `PieceArray`, toutes les poses ont le même repère et la
  même date que le header de l'observation. Une liste vide reste une observation datée.
- Les identifiants sont conservés entre observations lorsque le suivi le permet.
- Les contraintes telles que dimensions positives, confiance entre 0 et 1 et poses
  valides doivent être contrôlées par les nœuds : les définitions ne les imposent pas.
- Une pause demandée par service prend effet après la manipulation en cours et
  sa vérification. L'état effectif est publié dans `TowerState`.
- L'annulation d'une action doit être implémentée par le serveur et transmise à
  l'exécution du robot. Le fichier `.action` ne réalise pas cet arrêt à lui seul.

Le service personnalisé est ici un exemple pédagogique. `std_srvs/srv/SetBool`
pourrait aussi servir pour une requête booléenne avec une réponse succès/message.

## Compiler et inspecter

Depuis la racine `ros_2_robot`, dans un terminal où ROS 2 Jazzy est chargé :

```bash
colcon build --base-paths src/tower_interfaces --packages-select tower_interfaces
source install/local_setup.bash

ros2 interface show tower_interfaces/msg/Piece
ros2 interface show tower_interfaces/msg/PieceArray
ros2 interface show tower_interfaces/msg/TowerState
ros2 interface show tower_interfaces/srv/SetBuildingEnabled
ros2 interface show tower_interfaces/action/PickAndPlace
```

`--base-paths` limite la découverte à ce dossier. Au moment de la création de ce
package, les dossiers `tower_control`, `tower_perception` et `tower_bringup`
déclarent encore tous le nom ROS `sorting`. Il faudra corriger leurs noms dans
leurs `package.xml` et leurs configurations CMake avant une compilation globale.

Les autres packages qui utiliseront ces types devront déclarer une dépendance
sur `tower_interfaces` dans leur `package.xml`. Pour un nœud C++, ajouter aussi :

```cmake
find_package(tower_interfaces REQUIRED)
ament_target_dependencies(mon_executable rclcpp tower_interfaces)
```

Exemple de type C++ généré :

```cpp
#include "tower_interfaces/msg/piece_array.hpp"

// Dans le constructeur d'un nœud ; conserver le publisher comme membre.
auto publisher = create_publisher<tower_interfaces::msg::PieceArray>(
  "/detected_pieces", 10);
```

Une fois les futurs nœuds développés et lancés, on pourra observer et commander :

```bash
ros2 topic echo /detected_pieces
ros2 topic echo /tower_state
ros2 service call /set_building_enabled tower_interfaces/srv/SetBuildingEnabled "{enabled: true}"
ros2 service call /set_building_enabled tower_interfaces/srv/SetBuildingEnabled "{enabled: false}"
ros2 action info /pick_and_place
```

Ces dernières commandes nécessitent les nœuds correspondants : ce package seul
fournit uniquement les types.

Références : [interfaces personnalisées ROS 2 Jazzy](https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html)
et [création d'une action](https://docs.ros.org/en/jazzy/Tutorials/Intermediate/Creating-an-Action.html).
