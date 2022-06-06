#ifndef ROBOT
#define ROBOT

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "MovingElt.hpp"
#include "Terrain.hpp"

using namespace sf;
using namespace std;

#define VITESSE 1
#define VITESSE_ROTATION M_PI/60

#define H_ROB 50
#define W_ROB 50

#define SEUIL_X (W_ROB+W_OBS)
#define SEUIL_Y (W_ROB+W_OBS)

class Robot : public MovingElt
{
	private :
		int vie;

	public :

		Robot();
		//constructeur classique
		Robot(Vector2f p, string n, float o, int v) : MovingElt(p,n,o),  vie(v){};
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
			im = r.im;
			return *this;
		}
		//les getters
		int getVie(){return vie;}


		//déplace le robot suivant X et Y
		void deplace(Terrain& map);
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void reoriente(int direction);
		//chaque robot à son attaque
		//virtual void attaque() = 0;

        void displayInWindow(SFMLManager& s);
};




#endif
