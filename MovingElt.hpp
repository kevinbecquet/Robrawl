#ifndef MOVING_MovingElt
#define MOVING_MovingElt

#include "SFMLManager.hpp"
#include <memory>
#define ScaleFactor 0.3

using namespace std;
using namespace sf;

#define VITESSE 6
#define VITESSE_ROTATION M_PI/60

//Un objet mobile est un robot ou un missile
//Ils ont tous les deux une position - un nom - orientation - position et image
class MovingElt{

	protected :
		Vector2f position;
		Sprite im;

	public :
		//Constructeur par défaut
		MovingElt(){};
		//Constructeur 
		MovingElt(Vector2f p, Texture* t) : position(p)
		{
			im.setTexture(*t);
			im.scale(Vector2f(ScaleFactor,ScaleFactor));
		}
		//Destructeur virtuel
		virtual ~MovingElt(){};
		//Return la position d'un objet mobile
		Vector2f getPosition(){ return position;}
		//Méthode abstraite qui déplace un objet
		virtual void deplace() = 0;
		//Retourne l'image sous forme de sprite
		Sprite getIm(){return im;}
		//Set la position d'un sprite
		void setImPos()
		{
			im.setPosition(this->position);
		}
		//Set la position d'un sprite par surcharge
		void setImPos(Vector2f init_pos)
		{
			im.setPosition(init_pos);
		}
		//Affiche un objet mobile 
		virtual void displayInWindow(SFMLManager&) =0;
		
};

#endif
