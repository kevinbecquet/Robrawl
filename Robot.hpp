#ifndef ROBOT
#define ROBOT 

#include "Point.hpp"


class Robot
{
	protected :
		string nom;
		Point position;
		float orientation;
		int vie;
		sf::image im;
	
	public :
	
		//les getters
		Point getPosition(){ return position;}
		float getOrientation(){return orientation;}
		int getVie(){return vie;}
		//les setters
		void setPosition(Point pos) : position(pos){};
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
