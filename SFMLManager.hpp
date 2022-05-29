#ifndef SFML
#define SFML


#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle;
class Joueur;
class Robot;

using namespace std;
using namespace sf;

class SFMLManager{
	protected :
		RenderWindow* window;
	
	public :
		SFMLManager();
		~SFMLManager();
		RenderWindow*& getWindow();
		void eventManager();
		//gestionCollision();
		void displayObstacle(Obstacle& o);
		//void displayJoueur(const Joueur& j);
		//void displayText(const Text& t);
};

#endif
