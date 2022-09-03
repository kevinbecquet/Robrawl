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
		Sprite im;
		Vector2f position;
		string nom;
		float orientation;
		int vie;
		int height;
		int width;
		float vitesse;
		
	public :
		MovingElt(){};
		
		MovingElt(Vector2f p, string n, float o,int v,int h, int w) : 
					position(p), 
					nom(n), 
					orientation(o),
					vie(v),
					height(h),
					width(w)
					{};

		virtual ~MovingElt(){};
		
		int getVie(){return vie;}

		Vector2f getPosition(){ return position;}
		float getVitesse(){return vitesse;}
		float getOrientation(){return orientation;}
		
		int getHeight(){return height;}
		int getWidth(){return width;}
		
		Sprite getIm(){return im;}

		void setVie(int hp){ vie = hp; }
		

		virtual void deplace(Terrain& map) = 0;
		virtual void reoriente(int) = 0;
		
		void setIm(Texture* t)
		{
			im.setTexture(*t);
			im.scale(Vector2f(ScaleFactor,ScaleFactor));
			
			im.setOrigin(Vector2f(width/2,height/2));
			im.move(Vector2f(width/2,height/2));
		}
		void setImPos()
		{
			Vector2f pos;
			pos.x = position.x ;
			pos.y = position.y ;

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
