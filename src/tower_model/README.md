# Classes des pièces

`tower_model` contient une bibliothèque C++ partagée par la perception et le
contrôle. La hiérarchie demandée est :

```text
Piece (classe mère abstraite)
├── Cube       : rouge (red)
├── Rectangle  : bleu  (blue)
└── Cylindre   : vert  (green)
```

`Rectangle` désigne ici un **pavé rectangulaire en 3D**. Le cylindre a son axe selon
l'axe local z. Les dimensions sont en mètres et les volumes en mètres cubes.

## Ce que fait la classe mère

Dans `include/tower_model/piece.hpp`, `Piece` conserve l'identifiant et les
dimensions communes à toutes les pièces. Son constructeur vérifie que les
dimensions sont finies et strictement positives.

Les méthodes `forme()`, `couleur()` et `volume()` sont virtuelles pures (`= 0`) :
les classes filles doivent les implémenter. On ne peut donc pas créer directement
un objet `Piece`. Son destructeur virtuel permet de détruire correctement un
objet d'une classe fille manipulé par un pointeur vers `Piece`.

Les attributs sont privés et exposés en lecture seule. La taille et la couleur
d'une pièce ne peuvent pas être changées après sa construction.

## Les trois classes filles

| Classe | Constructeur | Dimensions locales x, y, z | Volume |
|---|---|---|---|
| `Cube` | `Cube(id, cote)` | côté, côté, côté | côté³ |
| `Rectangle` | `Rectangle(id, longueur, largeur, hauteur)` | longueur, largeur, hauteur | longueur × largeur × hauteur |
| `Cylindre` | `Cylindre(id, rayon, hauteur)` | diamètre, diamètre, hauteur | π × rayon² × hauteur |

Chaque classe a un fichier `.hpp` dans `include/tower_model/` pour sa déclaration,
et un fichier `.cpp` dans `src/` pour son implémentation.

Exemple :

```cpp
#include "tower_model/cube.hpp"
#include "tower_model/rectangle.hpp"
#include "tower_model/cylindre.hpp"

tower_model::Cube cube(1, 0.05);                         // Rouge, côté de 5 cm
tower_model::Rectangle rectangle(2, 0.08, 0.05, 0.025); // Bleu, 8 × 5 × 2,5 cm
tower_model::Cylindre cylindre(3, 0.015, 0.06);          // Vert, diamètre 3 cm, hauteur 6 cm
```

## Le polymorphisme

Un conteneur de pointeurs vers `Piece` peut contenir les trois formes :

```cpp
#include <memory>
#include <vector>

std::vector<std::unique_ptr<tower_model::Piece>> pieces;
pieces.push_back(std::make_unique<tower_model::Cube>(1, 0.05));
pieces.push_back(std::make_unique<tower_model::Rectangle>(2, 0.08, 0.05, 0.025));
pieces.push_back(std::make_unique<tower_model::Cylindre>(3, 0.015, 0.06));

for (const auto & piece : pieces) {
  const double volume = piece->volume();
  // La bonne formule est appelee selon la classe reelle de l'objet.
}
```

`unique_ptr` assure la destruction automatique des objets. `override` indique
qu'une méthode de la classe fille implémente une méthode virtuelle de la mère.
`final` indique que ces trois classes ne sont pas destinées à être spécialisées.

## Relation avec Piece.msg

`tower_model::Piece` représente un objet dans le programme. Le message
`tower_interfaces::msg::Piece` transporte ses données entre nœuds ROS.
Les messages ROS ne transmettent pas une hiérarchie de classes C++.

La fonction `to_message` fait le lien :

```cpp
#include "tower_model/ros_conversion.hpp"

// pose_mesuree est une geometry_msgs::msg::PoseStamped produite par la perception.
// Elle décrit le centre de la pièce, avec un repère et la date de la mesure.
auto message = tower_model::to_message(cube, pose_mesuree, 0.95F);
// Le publisher du noeud peut maintenant publier message.
```

La pose et la confiance restent des informations d'observation, fournies au
moment de la conversion. La conversion copie la pose sans la transformer : la
perception reste responsable de fournir une pose valide et d'utiliser TF lorsque
nécessaire. La confiance est vérifiée entre 0 et 1.

Le message conserve son format actuel. Dans ce projet, la correspondance fixe
couleur/forme permet d'interpréter `red` comme cube, `blue` comme pavé et `green`
comme cylindre. Pour le cylindre, `dimensions.x` et `dimensions.y` contiennent
le diamètre de sa boîte englobante, pas le rayon. Une future reconstruction côté
réception devra tenir compte de cette convention. Si plusieurs formes partagent
une couleur à l'avenir, il faudra ajouter un champ de forme explicite au message.

## Compiler, exécuter et tester

Depuis la racine `ros_2_robot`, avec ROS 2 Jazzy chargé :

```bash
colcon build --base-paths src/tower_interfaces src/tower_model --packages-up-to tower_model
source install/local_setup.bash
ros2 run tower_model demo_pieces

colcon test --base-paths src/tower_interfaces src/tower_model --packages-select tower_model
colcon test-result --test-result-base build/tower_model --verbose
```

La démonstration crée les trois pièces dans une liste commune, affiche leur
couleur et leur volume, et les convertit en messages. Elle utilise un repère
fictif `table_demo`, ne publie aucun topic et ne commande pas le robot.

La découverte est limitée à ces deux packages pour compiler le modèle sans
dépendre des pilotes matériels et de leur SDK.

Pour utiliser la bibliothèque dans un futur nœud C++, déclarer
`<depend>tower_model</depend>` dans son `package.xml`, puis dans CMake :

```cmake
find_package(tower_model REQUIRED)
target_link_libraries(mon_executable tower_model::tower_model)
```
