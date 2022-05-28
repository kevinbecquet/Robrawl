#ifndef SFML
#define SFML

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class SFMLManager{
	protected :
		RenderWindow* window;
	
	public :
		SFMLManager();
		~SFMLManager();
		RenderWindow& getWindow();
		void closeWindow();
		void drawInwindow();
		//gestionCollision();
		//GestionClavier();
		void diplayObstacle(const Obstacle& o);
		void displayJoueur(const Joueur& j);
		//void displayText(const Text& t);
};

#endif
