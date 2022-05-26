#ifndef ROBOT
#define ROBOT

#include "Point.hpp"
#include <cmath>

#include <cstdlib>
#include <fstream>

#include <SFML/Graphics.hpp>
using namespace sf;

#define VITESSE 0.75
#define VITESSE_ROTATION M_PI/60

class Robot
{
	private :
		string nom;
		Point position;
		float orientation;
		int vie;
		Image im;

	public :

		Robot(String n, Point p, float o, int v ) : nom(n), position(p), orientation(o), vie(v){};
		//les getters
		Point getPosition(){ return position;}
		float getOrientation(){return orientation;}
		int getVie(){return vie;}


		//déplace le robot suivant X et Y
		void deplace();
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void reoriente(int direction);
		//chaque robot à son attaque
		//virtual void attaque() = 0;
		//afficher
		void affiche();
};




#endif
