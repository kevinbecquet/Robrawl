# Robrawl Game
Ce jeu consiste en une bataille de deux robots, dans un terrain avec des obstacles. Ces robots 
se lancent des missiles, et celui qui perd le plus de points meurt.
## Les auteures 
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

Le robot au centre de l'écran :
1. j pour dans le sens trigonometrique 
2. l pour tourner dans le sens horaire 
3. k pour l'attaque 

Pour le moment le jeu ne permet que d'avancer dans la map. L'affichage des missiles ne se fait pas, bien que ceux-ci sont bien intégrés et change de position comme on peut le voire dans le terminale. La position des obstacles peut parfois être en partie à l'extérieur de la fenêtre et un dossier à part est ajouté par rapport aux collisions, non intégrées au code principale, car elles ne marchent pas tout à fait.

## Organisation
Kevin s'est occupé des méthodes de déplacement et collisions

Razane des méthodes d'affichage et gestions d'événements

On a principalement communiqué par facebook et partagé nos avancées sur github et discord
