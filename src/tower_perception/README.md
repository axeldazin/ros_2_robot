# Perception OpenCV à la demande

Le nœud `perception_node` conserve la dernière paire synchronisée d'images couleur
et de profondeur. **Il lance la détection uniquement lorsqu'il reçoit une demande.**

```text
RealSense : couleur + profondeur alignée + CameraInfo
                         ↓ abonnements
                  perception_node
                   ↑           ↓
  service AnalyzeImage     /detected_pieces : PieceArray
  ou topic Empty                ↓
                         tower_controller
                         vecteur pieces_ côté contrôle
```

## Les communications

| Interface | Type | Rôle |
|---|---|---|
| `/camera/camera/color/image_raw` | `sensor_msgs/msg/Image` | Image couleur |
| `/camera/camera/aligned_depth_to_color/image_raw` | `sensor_msgs/msg/Image` | Profondeur alignée pixel par pixel avec la couleur |
| `/camera/camera/color/camera_info` | `sensor_msgs/msg/CameraInfo` | Calibration couleur |
| Service `/perception/analyze_image` | `tower_interfaces/srv/AnalyzeImage` | Déclenche une analyse et retourne succès, message et vecteur |
| Topic `/perception/analyze` | `std_msgs/msg/Empty` | Déclenche la même analyse, sans réponse directe |
| `/detected_pieces` | `tower_interfaces/msg/PieceArray` | Publie le résultat de chaque analyse réussie |
| `/perception/debug_image` | `sensor_msgs/msg/Image` | Image couleur avec contours et noms des formes |

Les trois topics d'entrée sont configurables dans `config/perception.yaml`.
Les autres noms peuvent être adaptés avec les remappings ROS.

Le **service est préférable pour un contrôleur** qui doit savoir si l'analyse a
réussi : une requête vide suffit et `response.observation.pieces` est le vecteur
résultat. Le topic permet aussi de déclencher depuis un autre publisher.
Utiliser un seul chemin côté contrôleur pour ne pas traiter deux fois la même
observation (réponse de service et publication contiennent les mêmes données).

## Fonctionnement du traitement

1. Convertir l'image ROS en BGR avec `cv_bridge`, puis en HSV avec OpenCV.
2. Construire les masques rouge (deux plages HSV), bleu et vert.
3. Nettoyer les masques avec des ouvertures et fermetures morphologiques.
4. Extraire tous les contours séparés dépassant le seuil de surface.
5. Vérifier une forme compatible : carré rouge, pavé bleu, disque vert.
6. Prendre la profondeur médiane à l'intérieur de chaque contour.
7. Projeter le centre et les dimensions visibles en mètres avec la calibration.
8. Créer les objets `Cube`, `Rectangle` ou `Cylindre` de `tower_model` et les
   convertir en messages `Piece` avec la pose du centre de l'objet.
9. Transformer les poses avec TF si `output_frame` est renseigné.
10. Associer des identifiants et publier le vecteur ; le service le retourne aussi.

La couleur détermine la classe selon la règle du projet, complétée par des tests
géométriques simples. Ce traitement n'est pas une reconnaissance générale de
formes 3D. La confiance publiée est un score géométrique et de disponibilité de
profondeur ; ce n'est pas une probabilité calibrée.

## Fichiers à lire

- `src/color_detector.cpp` : segmentation HSV et contours 2D.
- `src/scene_analyzer.cpp` : profondeur, projection, géométrie et classes de pièces.
- `src/perception_node.cpp` : abonnements caméra, service, déclenchement et publication.
- `include/tower_perception/perception_node.hpp` : attributs du nœud.
- `config/perception.yaml` : topics, seuils, hauteurs et paramètres de calibration.
- `../tower_control/src/tower_controller.cpp` : réception du vecteur côté contrôle.

## Configuration physique à renseigner

Cette première version vise des pièces **posées à plat, séparées et observées
depuis le dessus**. Les dimensions dans le plan sont des estimations depuis les
contours. La hauteur du cube est déduite de son côté ; les hauteurs du pavé et du
cylindre doivent être connues car une seule face supérieure ne suffit pas à les
déduire sans connaître la surface de support.

Dans `config/perception.yaml`, renseigner les hauteurs réelles en mètres :

```yaml
rectangle_height_m: 0.02  # Exemple UNIQUEMENT si vos pavés font réellement 2 cm.
cylinder_height_m: 0.05   # Exemple UNIQUEMENT si vos cylindres font réellement 5 cm.
```

Les valeurs livrées sont `0.0` : l'analyse échoue si une pièce de cette forme est
présente tant que sa hauteur n'a pas été renseignée. Cette version suppose une
hauteur commune à tous les pavés et une hauteur commune à tous les cylindres.

`table_normal_camera` est la normale de la table, vers le haut, **exprimée dans le
repère optique de la caméra couleur**. `[0.0, 0.0, -1.0]` suppose une caméra
verticale regardant vers la table. Adapter cette normale à la pose réelle de la
caméra. Une vue très oblique, des faces latérales visibles ou des pièces empilées
dégradent les estimations ; régler la ROI pour limiter la détection à la zone des
pièces disponibles et exclure la tour.

La profondeur mesure le dessus d'une pièce. Le centre est calculé en retirant
une demi-hauteur selon la normale : il ne s'agit pas du point de contact sur le
dessus, ni de la pose de la pince.

Par défaut, les poses sont publiées dans le **repère optique couleur**, indiqué
dans les headers. Pour obtenir des poses dans le repère réel du XARM, définir
`output_frame` et fournir la transformation TF calibrée caméra/robot. Le nœud
utilise la transformation à la date de l'image et refuse l'analyse si elle manque.
Renseigner seulement un nom de repère ne réalise pas la calibration physique.

La configuration est chargée au démarrage : les paramètres sont en lecture seule.
Après modification du YAML source, recompiler le package pour copier la nouvelle
configuration installée, ou lancer avec un fichier explicite :

```bash
ros2 launch tower_perception perception.launch.py config:="$PWD/src/tower_perception/config/perception.yaml"
```

## Compiler

Depuis la racine du workspace, avec ROS 2 Jazzy chargé :

```bash
colcon build \
  --base-paths src/tower_interfaces src/tower_model src/tower_perception src/tower_control \
  --packages-up-to tower_perception tower_control
source install/local_setup.bash
```

La découverte est limitée à ces packages pour compiler la perception sans
dépendre de la compilation du pilote RealSense et de son SDK.

## Lancer avec la caméra

Dans chaque terminal, charger ROS et `source install/local_setup.bash`.

Terminal 1, si le pilote RealSense et son SDK sont installés :

```bash
ros2 launch realsense2_camera rs_launch.py \
  enable_color:=true enable_depth:=true enable_sync:=true align_depth.enable:=true
```

Terminal 2, après avoir renseigné la configuration :

```bash
ros2 launch tower_perception perception.launch.py config:="$PWD/src/tower_perception/config/perception.yaml"
```

Terminal 3, pour recevoir le vecteur côté contrôle :

```bash
ros2 launch tower_control controller.launch.py
```

Terminal 4, déclencher avec le service :

```bash
ros2 service call /perception/analyze_image tower_interfaces/srv/AnalyzeImage '{}'
```

Ou déclencher avec un message sur le topic :

```bash
ros2 topic pub --once /perception/analyze std_msgs/msg/Empty '{}'
```

Observer les résultats :

```bash
ros2 topic echo /detected_pieces
```

L'image annotée marque le centre 2D de chaque pièce par une croix jaune.
Elle est publiée à chaque analyse réussie ; elle peut être affichée
avec RViz en ajoutant un affichage Image sur `/perception/debug_image`.
Elle n'est pas diffusée en continu.

## Réception dans le contrôleur

### Récupérer le centre pour préparer une saisie

Chaque pièce du vecteur contient déjà son centre 3D dans
`piece.pose.pose.position`. Le service et le topic retournent cette même information :

```cpp
for (const auto & piece : observation->pieces) {
  const auto & centre = piece.pose.pose.position;
  const double x = centre.x;  // Metres dans piece.pose.header.frame_id.
  const double y = centre.y;
  const double z = centre.z;
  // Utiliser ce centre et l'orientation pour calculer la pose de la pince.
}
```

Depuis la réponse du service, le chemin est
`response.observation.pieces[i].pose.pose.position` (ou `response->...` avec un
pointeur C++). Le centre dans l'image est `detection.box.center`, en pixels,
avant la projection 3D.

Le centre renvoyé est celui du volume de la pièce. La prise depuis le dessus
doit tenir compte de sa hauteur, de son orientation et du décalage de l'outil.
Les coordonnées sont dans le repère optique caméra par défaut ; définir
`output_frame` et la TF calibrée pour les obtenir dans le repère du robot.

Dans `TowerController`, la callback contient :

```cpp
pieces_ = observation->pieces;
```

`pieces_` est un `std::vector<tower_interfaces::msg::Piece>` : chaque élément
contient l'identifiant, la couleur, la pose, les dimensions et le score.
L'état précédent est remplacé, y compris quand le vecteur reçu est vide.
Le nœud récepteur actuel affiche les résultats ; la stratégie et MoveIt restent à
implémenter. Avant une manipulation, le contrôleur devra vérifier la fraîcheur
des données et le repère.

## Gestion des erreurs et limites

- Pas de publication avant une demande : les callbacks caméra mémorisent les données.
- Le service analyse la dernière paire disponible, pas obligatoirement une nouvelle
  image acquise après la requête. Il faut des images récentes et des horloges cohérentes.
- Couleur et profondeur doivent avoir le même repère, la même taille et des dates
  suffisamment proches (`sync_tolerance_s`). La profondeur non alignée est inutilisable.
- En l'absence d'images, de calibration valide, de profondeur suffisante, de hauteur
  connue ou de TF requise, le service répond `success: false` et aucun vecteur
  n'est publié. Le déclenchement par topic signale l'erreur dans les logs.
- Une analyse réussie sans pièce publie une liste vide ; cela est différent d'une erreur.
- Une pièce reconnue sans profondeur exploitable fait échouer toute l'analyse.
  Les contours trop petits, coupés par la ROI ou incompatibles avec la forme sont ignorés.
- Les objets qui se touchent avec la même couleur peuvent fusionner en un contour.
  Les objets masqués, les reflets et les fonds colorés nécessitent des adaptations.
- Les identifiants sont associés à la dernière observation réussie par couleur et
  proximité 3D, sans réutilisation au sein d'une observation. C'est un suivi simple :
  après une disparition, un déplacement important ou un redémarrage, un identifiant
  peut changer. Deux pièces voisines de même couleur peuvent être confondues.

## Vérifier sans caméra

```bash
colcon test \
  --base-paths src/tower_interfaces src/tower_model src/tower_perception src/tower_control \
  --packages-select tower_model tower_perception
colcon test-result --test-result-base build/tower_perception --verbose

python3 src/tower_perception/test/smoke_test.py
```

Les tests C++ utilisent des images synthétiques. Le test ROS démarre les vrais
exécutables sur un domaine de test, publie des données RGB-D synthétiques et
vérifie les deux déclenchements, la conversion TF, les identifiants, les erreurs
et la réception côté contrôleur. Il ne nécessite ni caméra ni robot.

Références : [segmentation HSV OpenCV](https://docs.opencv.org/4.x/da/d97/tutorial_threshold_inRange.html),
[contours et formes OpenCV](https://docs.opencv.org/4.x/d3/dc0/group__imgproc__shape.html),
[pilote et alignement RealSense](https://github.com/realsenseai/realsense-ros).
