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
3. Nettoyer les masques avec des ouvertures et fermetures morphologiques adaptées
   à la résolution de l'image.
4. Extraire tous les contours séparés dépassant le seuil de surface.
5. Vérifier une forme compatible : carré rouge, pavé bleu, contour vert compact
   rond ou ovale.
6. Prendre la profondeur médiane à l'intérieur de chaque contour.
7. Projeter le centre en mètres et estimer l'orientation avec la calibration.
8. Créer les objets `Cube`, `Rectangle` ou `Cylindre` de `tower_model` et les
   convertir en messages `Piece` avec les dimensions physiques du catalogue et la
   pose du centre de l'objet.
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
- `config/perception.yaml` : topics, seuils, dimensions physiques et calibration.
- `../tower_control/src/tower_controller.cpp` : réception du vecteur côté contrôle.

## Dimensions physiques et configuration de la caméra

Cette première version vise des pièces **posées à plat, séparées et observées
depuis le dessus**. Les contours, la profondeur et la calibration donnent leur
position et leur orientation. Les dimensions publiées sont les dimensions
physiques connues des pièces du projet :

| Pièce | Dimensions réelles | `dimensions` publié, en mètres |
|---|---|---|
| Cube rouge | Côté de 5 cm | `[0.05, 0.05, 0.05]` |
| Pavé bleu | 8 × 5 × 2,5 cm | `[0.08, 0.05, 0.025]` |
| Cylindre vert | Diamètre 3 cm, hauteur 6 cm | `[0.03, 0.03, 0.06]` |

Ces valeurs sont déjà renseignées dans `config/perception.yaml` :

```yaml
cube_side_m: 0.05
rectangle_length_m: 0.08
rectangle_width_m: 0.05
rectangle_height_m: 0.025
cylinder_diameter_m: 0.03
cylinder_height_m: 0.06
```

Le constructeur de `Cylindre` reçoit un rayon : la perception convertit donc
`0.03 / 2 = 0.015 m`. Toutes les dimensions doivent être finies et positives.
Cette version suppose que toutes les pièces d'une même forme ont ces dimensions.
La largeur apparente dans l'image ne remplace pas les dimensions connues.

Le seuil de contour `min_area_px` est fixé à 75 pixels carrés pour conserver aussi
le petit cylindre. Le seuil effectif est le maximum entre cette valeur et
`min_area_fraction × surface de la ROI`. Avec `min_area_fraction: 0.00005`, il
reste à 75 pixels sur une image 640 × 480, mais passe à environ 610 pixels sur
une photo 3024 × 4032 pour écarter les petites taches. Régler la fraction à zéro
désactive cette adaptation. Ces seuils dépendent aussi de la distance et du bruit.

Pour les cylindres verts, `min_circularity` s'applique à l'enveloppe convexe du
contour : les aspérités d'une pièce imprimée ne doivent pas augmenter artificiellement
son périmètre et la faire rejeter. `min_cylinder_solidity` impose un rapport minimal
de 0,8 entre l'aire du contour et celle de son enveloppe, pour rejeter les formes
très creuses. Le contour original est conservé pour échantillonner la profondeur.

Le seuil vert accepte une saturation à partir de 60, pour conserver les faces
plus claires ou éclairées différemment. Le seuil précédent de 80 éliminait presque
toute une face sur `IMG_1618.jpeg`. Les couleurs peu saturées du fond restent exclues.

Avec `scale_morphology_with_resolution: true`, `morphology_size: 3` désigne un
noyau de référence pour une image dont le petit côté mesure 480 pixels. Le noyau
augmente avec la résolution : 19 pixels sur les photos 3024 × 4032, toujours 3
sur une image 640 × 480 ou plus petite. Cela retire les petits points du fond
reliés aux contours bleus et nettoie les découpes des cylindres. Une ROI utilise
la résolution de l'image complète pour conserver le même nettoyage. Mettre
`scale_morphology_with_resolution: false` permet de choisir une taille fixe.

L'image annotée utilise une approximation du contour avec
`contour_simplification_ratio: 0.0015` (0,15 % du périmètre), pour atténuer les
petites dents restantes. Cette approximation concerne seulement l'affichage :
le centre, l'orientation et les profondeurs utilisent le contour du masque nettoyé.
La valeur zéro affiche tous les détails ; la plage admise va de 0 à 0,01.
Les traits, croix et textes augmentent aussi avec la résolution pour rester lisibles.
Le tracé suit la silhouette visible, y compris les faces latérales : un pavé vu
de biais ne donne pas forcément quatre côtés, et un cylindre couché ne donne pas
un cercle.

`table_normal_camera` est la normale de la table, vers le haut, **exprimée dans le
repère optique de la caméra couleur**. `[0.0, 0.0, -1.0]` suppose une caméra
verticale regardant vers la table. Adapter cette normale à la pose réelle de la
caméra. Une vue très oblique, des faces latérales visibles ou des pièces empilées
dégradent les estimations ; régler la ROI pour limiter la détection à la zone des
pièces disponibles et exclure la tour.

La profondeur mesure le dessus d'une pièce. Le centre est calculé en retirant
une demi-hauteur selon la normale : il ne s'agit pas du point de contact sur le
dessus, ni de la pose de la pince.

Un cylindre couché peut aussi être reconnu dans l'image grâce à sa silhouette
ovale. Son orientation et son centre 3D réels nécessitent un traitement supplémentaire :
le calcul actuel suppose un cylindre debout, dont l'axe suit la normale de la table.

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

## Simulation depuis une image, sans caméra

La simulation lance le même `perception_node`, une source d'images virtuelle et
le `tower_controller`. Les échanges passent par `/simulation/` :

```text
Image PNG/JPG ou scène générée + profondeur/calibration virtuelles
                              ↓
                  /simulation/perception_node
                              ↓
                 /simulation/detected_pieces
                              ↓
                  /simulation/tower_controller
```

Après compilation et chargement du workspace, une seule commande suffit :

```bash
ros2 launch tower_perception image_simulation.launch.py
```

Sans argument `image`, la source génère une vue du dessus avec un cube rouge,
un pavé bleu et un cylindre vert aux dimensions du catalogue. Elle simule une
caméra et un support à 80 cm, avec une profondeur différente sur le dessus de
chaque pièce. L'analyse démarre automatiquement et les centres s'affichent :

```text
id  couleur    u(px)  v(px)     X(m)     Y(m)     Z(m)
 1  red        240.0  230.0   -0.2250  -0.0844   0.7750
 2  blue       520.0  260.0    0.0388  -0.0581   0.7875
 3  green      750.0  430.0    0.2498   0.1018   0.7700
```

Les valeurs peuvent varier légèrement avec l'arrondi des contours dans l'image.
`u` et `v` sont les coordonnées en pixels depuis le coin supérieur gauche ;
`X`, `Y`, `Z` sont les centres 3D dans le repère optique virtuel (x à droite,
y vers le bas, z vers l'avant).

Les fichiers suivants sont écrits dans `simulation_output/`, à partir du dossier
où la commande est lancée :

- `scene.png` : l'image analysée.
- `annotated.png` : contours, formes et croix sur les centres.
- `pieces.json` et `pieces.csv` : coordonnées et pièces détectées.
- `depth.npy` : profondeur virtuelle, en mètres.
- `scene.json` : paramètres de caméra et positions attendues de la scène générée.

Ce dossier est ignoré par Git. `output_dir:=/chemin/resultats` permet de choisir
une autre destination. Pour arrêter automatiquement après sauvegarde :

```bash
ros2 launch tower_perception image_simulation.launch.py once:=true
```

### Analyser ta propre image

```bash
ros2 launch tower_perception image_simulation.launch.py \
  image:="/chemin/vers/mes_pieces.jpg" once:=true
```

Une photo couleur seule permet de trouver les centres en pixels. **Les XYZ de ce
mode sont simulés** : la source suppose une profondeur uniforme de 0,8 m sur les
faces visibles et une caméra virtuelle sans distorsion. Ils ne donnent pas la
position réelle de la photo dans le repère du robot. Il faut une calibration et
une profondeur réelles, ou un plan de travail calibré, pour obtenir ces mesures.
La méthode de détection vise toujours les faces du dessus, séparées, avec les
couleurs du projet.

Les arguments `depth_m`, `fx`, `fy`, `cx` et `cy` permettent de régler cette caméra
virtuelle. Le centre optique est placé au centre de l'image par défaut.
La simulation utilise une normale `[0, 0, -1]` et conserve les poses dans le repère
optique virtuel ; les dimensions et seuils de détection viennent du YAML choisi
par `config:=...`.

Sans `once:=true`, les nœuds restent actifs. On peut relancer une analyse :

```bash
ros2 service call /simulation/perception/analyze_image tower_interfaces/srv/AnalyzeImage '{}'
ros2 topic echo /simulation/detected_pieces
```

`auto_analyze:=false` permet d'attendre une demande manuelle. Le topic de
déclenchement est `/simulation/perception/analyze` et l'image annotée est aussi
publiée sur `/simulation/perception/debug_image`.
L'analyse automatique attend les abonnements caméra et la découverte du contrôleur,
pour que celui-ci reçoive la publication unique même sur une petite image traitée
très vite. Avec `start_controller:=false`, cette attente du contrôleur est désactivée.

La source se trouve dans `scripts/image_simulator.py` et l'assemblage des nœuds
dans `launch/image_simulation.launch.py`.

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
- En l'absence d'images, de calibration valide, de profondeur suffisante ou de TF
  requise, le service répond `success: false` et aucun vecteur
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
python3 src/tower_perception/test/image_simulation_smoke_test.py
```

Les tests C++ utilisent des images synthétiques. Le test ROS démarre les vrais
exécutables sur un domaine de test, publie des données RGB-D synthétiques et
vérifie les deux déclenchements, la conversion TF, les identifiants, les erreurs
et la réception côté contrôleur. Il ne nécessite ni caméra ni robot.

Références : [segmentation HSV OpenCV](https://docs.opencv.org/4.x/da/d97/tutorial_threshold_inRange.html),
[contours et formes OpenCV](https://docs.opencv.org/4.x/d3/dc0/group__imgproc__shape.html),
[pilote et alignement RealSense](https://github.com/realsenseai/realsense-ros).
