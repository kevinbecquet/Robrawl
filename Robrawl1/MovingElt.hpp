#ifndef MOVING_MovingElt
#define MOVING_MovingElt

#include "SFMLManager.hpp"
#include <memory>
#define ScaleFactor 0.3

using namespace std;
using namespace sf;

//Un objet mobile est un robot ou un missile
//Ils ont tous les deux une position - un nom - orientation - position et image
class MovingElt{

	protected :
		Vector2f position;
		Sprite im;
		string nom;
		float orientation;
		float vitesse;
		int height;
		int width;

	public :
		MovingElt(){};
		
		MovingElt(Vector2f p, string n, float o,int h, int w) : 
					position(p), 
					nom(n), 
					orientation(o),
					height(h),
					width(w)
					{};

		virtual ~MovingElt(){};

		Vector2f getPosition(){ return position;}
		float getVitesse(){return vitesse;}
		float getOrientation(){return orientation;}
		int getHeight(){return height;}
		int getWidth(){return width;}

		Sprite getIm(){return im;}

		virtual void deplace(Terrain& map) = 0;
		virtual void reoriente(int) = 0;
		
		void setIm(Texture* t)
		{
			im.setTexture(*t);
			im.scale(Vector2f(ScaleFactor,ScaleFactor));
		}
		void setImPos()
		{
			im.setPosition(this->position);
		}
		void setImPos(Vector2f init_pos)
		{
			im.setPosition(init_pos);
		}
		virtual void displayInWindow(SFMLManager&) =0;
		string getNom(){return nom;}
};

#endif
