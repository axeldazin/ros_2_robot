# Projet ROS : construction d’une tour avec le XARM6

## Introduction

Ce projet est conçu pour mettre en pratique vos compétences en ROS tout en découvrant un bras robotisé industriel, le XARM6. L’objectif est de construire la tour la plus haute possible en empilant des pièces de différentes tailles et couleurs.

Vous aurez accès :
- Au robot XARM6 pour des sessions de tests en conditions réelles.
- À une caméra pour la détection des pièces.
- Aux simulateurs Gazebo (& RViz) pour la modélisation et la visualisation de votre travail en temps réel.

## Objectifs du projet

- Détection des pièces : Utiliser la caméra pour identifier les pièces par leur taille et leur couleur.
- Planification et optimisation : Concevoir une stratégie d’empilage pour maximiser la hauteur de la tour.
- Contrôle du bras robotisé : Utiliser ROS pour programmer les mouvements du XARM6 de manière précise et fluide.
- Précision et stabilité : Assurer la stabilité de la tour tout au long de la construction.

## Groupe

La classe sera réparti en 4 groupes. Chaque groupe aura un leader et sera libre de s’organiser comme bon lui semble. Toutefois, voici quelques suggestions:
- Détection de pièces : Gère le traitement des images pour la détection de la taille et de la couleur des pièces.
- Planification des trajectoires : Conçoit les mouvements optimaux du bras pour saisir et poser les pièces.
- Contrôle de stabilité : S’assure de la précision et de la stabilité de chaque ajout à la tour.
- Supervision et correction : Détecte les erreurs et ajuste les actions si nécessaire.

## Déroulement du Projet

- Prise en main des outils :
  - XARM6 : Familiarisez-vous avec les fonctionnalités de base du robot et des commandes ROS.
  - Caméra : Utilisez la caméra pour détecter les caractéristiques des pièces.
  - Gazebo et RViz : Mettez en place une simulation du XARM6 dans Gazebo et visualisez les résultats dans RViz pour tester vos codes avant le test en réel.
- Planification du projet :
  - Définissez la stratégie d’empilage en fonction des tailles et couleurs des pièces.
  - Organisez les mouvements de manière à minimiser les erreurs et à maximiser la hauteur et la stabilité de la tour.
- Phases de tests :
  - Simulation dans Gazebo : Utilisez cette phase pour ajuster vos paramètres et tester votre code dans un environnement simulé.
  - RViz : Visualisez les positions et trajectoires pour vérifier les placements.
  - Tests réels : Accès au robot pour tester votre programme en conditions réelles.

## Informations techniques
### Robot XARM6

- Description : Le XARM6 est un bras robotisé à 6 axes. Il peut saisir, déplacer et empiler des objets avec précision. Il est équipé d'une caméra RealSense 425.
- Packages disponibles : Utilisez le package ROS `xarm_ros` https://github.com/xArm-Developer/xarm_ros2 pour commander le robot. Ce package inclut :
  - La modélisation et les fichiers URDF du robot.
  - Des interfaces pour la commande de chaque articulation.
  - Des outils pour le contrôle en simulation et en réel.


### Détection d’objets avec la caméra

- Objectif : Reconnaître la taille et la couleur des pièces pour une meilleure gestion de l’empilage.
- Utilisez le package `realsense-ros` pour la caméra: https://github.com/IntelRealSense/realsense-ros
- Package ROS pouvant aussi être utile : `cv_bridge` pour l’intégration entre ROS et OpenCV, une bibliothèque puissante pour le traitement d’images. Astuces :
   - Utilisez la détection de couleur pour classer les pièces.
  - Estimez la taille en fonction de la distance et de l’angle de la caméra.

### Planification de trajectoires

- Utilisez le package MoveIt pour planifier les mouvements. MoveIt est compatible avec le XARM6 et permet de concevoir des trajectoires précises.
- Astuce : Prévoyez des trajectoires courtes et fluides pour réduire le temps de manipulation.

### Gazebo et RViz

- Gazebo : C’est un simulateur 3D qui vous permettra de tester votre code ROS dans un environnement virtuel avant de passer au robot réel.
  - Astuce : Utilisez des objets de tailles et couleurs similaires à vos pièces pour simuler le comportement réel.
- RViz : Utilisez RViz pour visualiser les mouvements du robot, ce qui est crucial pour corriger les trajectoires et éviter les erreurs de placement.
  - Astuce : Activez l’affichage des axes et des cadres de chaque articulation pour bien comprendre les positions.

## Tips pour réussir

- Testez d’abord en simulation : Avant de passer au test réel, assurez-vous que tout fonctionne correctement dans Gazebo et RViz.
- Documentez votre travail : Prenez des notes sur vos essais et vos observations. Cela vous aidera lors de la présentation finale.
- Optimisez vos trajectoires : Plus les mouvements sont courts et fluides, plus la construction sera rapide et stable.
- Communiquez en équipe : Assurez-vous que chaque membre comprend bien le projet et le rôle qu’il doit jouer.

## Contraintes

- Temps de travail total : 24 heures de projet dont 1h30 d'évaluation
- Robot disponible : XARM6 (accès limité pour des sessions de test).

## Evaluation

- Les deux dernières heures seront réservées à l'évaluation. Celle-ci sera composée d'une présentation orale avec support de chaque groupe qui devra contenir une démonstration. Chaque groupe aura un temps total de 30min, dont 15min de présentation, 5min de démo et 10min de questions.
- La hauteur de la tour, la précision, la stabilité, et la rapidité de construction seront pris en compte dans la notation. La présentation et l'implication seront aussi pris en compte.
- La note est individuelle.


