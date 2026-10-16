# Contrôleur de la tour

Le fichier [tower_controller.cpp](src/tower_controller.cpp) contient la classe
`TowerController` et son point d'entrée `main`. Le nœud `tower_controller`
s'abonne à `/detected_pieces` et conserve le dernier
`std::vector<tower_interfaces::msg::Piece>` dans l'attribut `pieces_`.
Il affiche les identifiants, couleurs, centres et le repère de l'observation.
Une liste vide remplace bien la liste précédente.

```bash
source install/local_setup.bash
ros2 launch tower_control controller.launch.py
```

On peut également lancer directement l'exécutable :

```bash
ros2 run tower_control tower_controller
```

La stratégie et les commandes MoveIt restent à développer. Le récepteur ne
déplace aucun robot. Avant de commander le XARM, le contrôleur devra notamment
vérifier la date de l'observation et utiliser des poses dans le repère du robot.

Voir [tower_perception](../tower_perception/README.md) pour déclencher l'analyse.
