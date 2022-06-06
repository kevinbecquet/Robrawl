# Robrawl Game
Ce jeu consiste en une bataille de deux robots, dans un terrain avec des obstacles. Ces robots 
se lancent des missiles, et celui qui perd le plus de points meurt.
## Les autaires 
Kevin Becquet et Azrou Razane
## Bibliothèque spéciale
SFML

Comment l'installer ? Dans votre terminal linux :

`sudo apt-get install libsml-dev`

## Compilation du programme 
Pour lancer notre jeu, rien de plus simple. Ouvrez votre terminal dans le dossier Robrawl et
lancer les lignes suivantes dans l'ordre :

`make`

`./Robrawl`

Après le make un petit warning s'affichera. Ne vous en souciez pas.

## Plus sur le jeu
Une map au fond noir avec deux robots et deux obstacles s'affichera.
Chaque robot correspond à un joueur, dirigé par trois touches. Une pour avancer vers l'arrière,
une autre vers l'avant et une dernière pour attaquer.

Le robot en haut à gauche : 
1. q pour tourner dans le sens trigonometrique 
2. d pour tourner dans le sens horaire
3. s pour l'attaque
Le robot qu centre de l'écran :
1. j pour dans le sens trigonometrique 
2. l pour tourner dans le sens horaire 
3. k pour l'attaque 

Pour le moment le jeu ne permet que d'avancer dans la map et gère les collisions. L'affichage et 
l'utilisation des missiles a rencontré un mauvais contre temps dû aux hpp. Une de nos classes, 
*Terrain*, étant considérée non encore définie par le compilateur.
Deux fichiers avec la version à moitié fonctionnelle sans missile et non fonctionnelle avec 
missiles ont été ajoutés.

## Organisation
Kevin s'est occupé des méthodes de déplacement et collisions

Razane des méthodes d'affichage et gestions d'événements

On a principalement communiqué par facebook et partagé nos avancées sur github et discord
