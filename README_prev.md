# Robrawl Game
Ce jeu consiste en une bataille de deux robots, dans un terrain avec des obstacles. Ces robots
se lancent des missiles, et celui qui perd le plus de points meurt.

L'intégration d'une IA serait possible en remplaçant les entrées clavier du deuxième joueur 
par des décisions faite par cette dernière.

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
1. q pour tourner dans le sens horaire
2. d pour tourner dans le sens trigonometrique
3. s pour l'attaque

Le robot au centre de l'écran :
1. j pour dans le sens horaire 
2. l pour tourner dans le sens trigonometrique 
3. k pour l'attaque 

## Avancement du projet

Suite à un problème de mise en commun des méthode de collisions et de missiles nous avons deux dossiers différents comprenant l'avancée du projet sur ces points respectifs : Robrawl reprenant l'avancée sur la partie collision et Robrawl2 l'avancée de la partie missile.

Pour le moment le dossier Robrawl2 ne permet que d'avancer dans la map. L'affichage des missiles ne se fait pas, bien que ceux-ci sont bien intégrés et change de position comme on peut le voire dans le terminale. La position des obstacles peut parfois être en partie à l'extérieur de la fenêtre.

Le dossier Robrawl permet d'avoir un déplacement dans la fenêtre, sans gestion de missile.

## Organisation
Kevin s'est occupé des méthodes de déplacement et collisions

Razane des méthodes d'affichage et gestions d'événements

On a principalement communiqué par facebook et partagé nos avancées sur github et discord
