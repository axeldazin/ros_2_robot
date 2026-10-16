# tower_interfaces

Ce package définit les types de données échangés entre la perception et le
contrôleur. ROS génère leurs classes C++ et Python lors de la compilation.

## Interfaces utilisées

```text
tower_interfaces/
├── msg/
│   ├── Piece.msg          # Une pièce et son centre 3D
│   └── PieceArray.msg     # Le vecteur de pièces d'une observation
├── srv/
│   └── AnalyzeImage.srv   # Demande d'analyse et réponse avec le vecteur
├── CMakeLists.txt
└── package.xml
```

| Type | Utilisation actuelle |
|---|---|
| `Piece` | Identifiant, couleur, pose du centre, dimensions et confiance d'une pièce |
| `PieceArray` | Vecteur `pieces` accompagné d'un header commun (date et repère) |
| `AnalyzeImage` | Requête vide ; réponse contenant `success`, `message` et `observation` |

## Qui échange quoi ?

```text
Demande par service /perception/analyze_image
                     ↓
              perception_node
                     ↓
       /detected_pieces : PieceArray
                     ↓
              tower_controller
```

Le service retourne le vecteur dans `response.observation.pieces`. Après chaque
analyse réussie, le même résultat est publié sur `/detected_pieces` et reçu par
`tower_controller`. Une analyse réussie sans pièce renvoie un vecteur vide.
En cas d'erreur, le service répond `success = false` et aucun vecteur n'est publié.

Les noms des topics et du service sont définis dans les nœuds. Ce package fournit
uniquement leurs types et ne démarre aucun nœud.

## Accéder au centre d'une pièce

Dans une callback du contrôleur recevant `observation` :

```cpp
for (const auto & piece : observation->pieces) {
  const auto & centre = piece.pose.pose.position;
  // centre.x, centre.y et centre.z : coordonnées en mètres.
  // piece.pose.header.frame_id : repère de ces coordonnées.
}
```

La pose décrit le centre du volume de la pièce, avec son orientation. Elle est
exprimée dans le repère optique caméra par défaut ; la perception peut utiliser
TF pour la convertir dans le repère du robot via son paramètre `output_frame`.
La pose de la pince est à calculer à partir de la pièce et de la géométrie de l'outil.

## Conventions

- Les positions et dimensions sont exprimées en mètres.
- La couleur suit la règle du projet : `red` pour un cube, `blue` pour un pavé
  rectangulaire, `green` pour un cylindre.
- L'orientation est un quaternion unitaire.
- Les dimensions suivent les axes locaux de la pièce. Pour un cylindre,
  `dimensions.x` et `dimensions.y` contiennent le diamètre ; `dimensions.z` la hauteur.
- Toutes les poses d'un `PieceArray` utilisent le même repère et la même date que
  son header. Une observation vide reste datée.
- La confiance est comprise entre 0 et 1 ; elle correspond au score fourni par la perception.
- Les contraintes sont vérifiées par les nœuds : les fichiers de définition ne
  réalisent pas ces contrôles à eux seuls.

Les classes métier `Piece`, `Cube`, `Rectangle` et `Cylindre` se trouvent dans
[tower_model](../tower_model/README.md), avec la conversion vers le message ROS.

## Compiler et inspecter

Depuis la racine du workspace, avec ROS 2 Jazzy chargé :

```bash
colcon build --base-paths src/tower_interfaces --packages-select tower_interfaces
source install/local_setup.bash

ros2 interface show tower_interfaces/msg/Piece
ros2 interface show tower_interfaces/msg/PieceArray
ros2 interface show tower_interfaces/srv/AnalyzeImage
```

Une fois la perception et le contrôleur lancés :

```bash
ros2 service call /perception/analyze_image tower_interfaces/srv/AnalyzeImage '{}'
ros2 topic echo /detected_pieces
```

Voir [tower_perception](../tower_perception/README.md) pour la caméra, la
configuration et les commandes de lancement, et
[tower_control](../tower_control/README.md) pour le contrôleur.

## Utilisation dans un nœud C++

Déclarer `<depend>tower_interfaces</depend>` dans son `package.xml`, puis :

```cmake
find_package(tower_interfaces REQUIRED)
ament_target_dependencies(mon_executable rclcpp tower_interfaces)
```

Exemple d'inclusion :

```cpp
#include "tower_interfaces/msg/piece_array.hpp"
#include "tower_interfaces/srv/analyze_image.hpp"
```
