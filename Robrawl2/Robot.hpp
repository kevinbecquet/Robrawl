#ifndef ROBOT
#define ROBOT

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "MovingElt.hpp"
#include "Terrain.hpp"
#include "Missile.hpp"

using namespace sf;
using namespace std;

class Robot : public MovingElt
{
	private :
		int vie;
		string nom;
		float orientation;
		
	public :
	
		Robot(){};
		//constructeur classique
		Robot(Vector2f p, Texture* t, int v, string n, float o) : MovingElt(p,t), vie(v), nom(n), orientation(o){};
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
		//Retourne l'orientation d'un objet
		float getOrientation(){return orientation;}
		//Retourne le nom d'un objet
		string getNom(){return nom;}
		
		void reoriente(int direction);
		//déplace le robot suivant X et Y
		void deplace();
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void attaque(Missile* missile, SFMLManager& render);
		
        void displayInWindow(SFMLManager& s);
};




#endif
