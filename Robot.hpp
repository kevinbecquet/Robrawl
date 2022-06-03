#ifndef ROBOT
#define ROBOT

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "MovingElt.hpp"

using namespace sf;
using namespace std;

#define VITESSE 0.75
#define VITESSE_ROTATION M_PI/60

class Robot : public MovingElt
{
	private :
		string nom;
		float orientation;
		int vie;
		//Sprite im;

	public :

		Robot();
		//constructeur classique
		Robot(Vector2f p,string n, float o, int v ) : MovingElt(p), nom(n), orientation(o), vie(v){};
		//Constructeur par copie
		Robot(const Robot& r)
		{
			*this = r; //fait appel à l'opérateur d'assignement
		}
		//opérateur d'assignement
		Robot& operator=(const Robot& r)
		{
			nom = r.nom;
			position = r.position;
			orientation = r.orientation;
			vie = r.vie;
			//im = r.im;
			return *this;
		}
		//les getters
		float getOrientation(){return orientation;}
		int getVie(){return vie;}


		//déplace le robot suivant X et Y
		void deplace();
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void reoriente(int direction);
		//chaque robot à son attaque
		//virtual void attaque() = 0;

		void displayInWindow(SFMLManager& s);
};




#endif
