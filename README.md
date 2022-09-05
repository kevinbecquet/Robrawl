# Robrawl ( version finale)

Deux vaisseaux spaciaux ennemis poursuivent le même but: anéantir son opposant ! 
Pour y parvenir, ils pourront lancer des missiles dans le but de se toucher. Si un vaisseau se fait toucher par 5 missiles au total, il est éliminé.

## Installation et usage

Pour installer ce jeu, il faudra au préalable installer la bibliotèque **SFML** utilisée pour l'affichage graphique et la gestion d'événements clavier:
```
sudo apt-get install libsml-dev
```
Une fois la bibliothèque installée, il suffira de compiler le programme dans le dossier *Robrawl1/* pour pouvoir lancer le jeu:
```
#Compilation
make

#Lancement
./Robrawl
``` 

## Jouer 
 

Les vaisseaux avance à vitesse constante. Par conséquent chaque joueur a accès à trois actions pour vaincre son adversaire ces actions et les touches correspondantes sont resumés dans ce tableau: 
|actions|joueur1|joueur2|
|---|---|---|
|tourner en sens trigo|Q|J|
|tourner en sens horaire|D|L|
|tirer un missile |Z|I|



