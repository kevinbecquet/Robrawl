#ifndef ROBOT
#define ROBOT 

#include "Point.hpp"
#include <SFML/Graphics.hpp>


class Robot
{
	protected :
		string nom;
		Point position;
		float orientation;
		int vie;
		sf::Image im;
	
	public :
	
		//les getters
		Point getPosition(){ return position;}
		float getOrientation(){return orientation;}
		int getVie(){return vie;}
		//les setters
		//A mettre en place l'opérateur =, le constructeur par copie et maybe un destructeur
		//void setPosition(Point pos){};
		void setOrientation(float angle);
		
		//déplace le robot suivant X et Y
		void deplace();
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void reoriente(sf::Keyboard::Key gauche, sf::Keyboard::Key droit);
		//chaque robot à son attaque
		virtual void attaque() = 0;
		//afficher
		void affiche();
};
	
	


#endif 
