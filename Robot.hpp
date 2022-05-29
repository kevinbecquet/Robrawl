#ifndef ROBOT
#define ROBOT

#include <cmath>

#include <cstdlib>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#define VITESSE 0.75
#define VITESSE_ROTATION M_PI/60

class Robot
{
	private :
		string nom;
		Vector2f position;
		float orientation;
		int vie;
		//Sprite im;

	public :
	
		//constructeur classique
		Robot(String n, Vector2f p, float o, int v ) : nom(n), position(p), orientation(o), vie(v){};
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
		Vector2f getPosition(){ return position;}
		float getOrientation(){return orientation;}
		int getVie(){return vie;}


		//déplace le robot suivant X et Y
		void deplace();
		//Reoriente le robot en affichant une fleche qui tourne sur 180° à droite ou à gauche
		void reoriente(int direction);
		//chaque robot à son attaque
		//virtual void attaque() = 0;
};




#endif
