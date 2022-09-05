#ifndef ROBOT
#define ROBOT

#include <cmath>

#include "MovingElt.hpp"
#include "Terrain.hpp"
#include "Missile.hpp"

using namespace sf;
using namespace std;

#define VITESSE_ROTATION M_PI/80

#define H_ROB 20
#define W_ROB 20

#define SEUIL_X (W_ROB+W_OBS)
#define SEUIL_Y (H_ROB+H_OBS)

class Robot : public MovingElt
{
	private :
		int cooldown = 0;
		
	public :

		//constructeur classique
		Robot(Vector2f p, string n, float o, int v,int h, int w) : 
				MovingElt(p,n,o,v,h,w,1.5){};
				
				
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
		
		//déplace le robot suivant X et Y
		void deplace(Terrain& map);

		//Modifie l'orietation du robot dans la direction indiquée (positive ou negative)
		void reoriente(int direction);

		void attaque(Terrain& map);
		Missile* launchMissile(Terrain& map);

        void displayInWindow(SFMLManager& s);
};




#endif
