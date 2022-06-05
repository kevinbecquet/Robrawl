#ifndef MOVING_MovingElt
#define MOVING_MovingElt

#include "SFMLManager.hpp"
#include <memory>
#define ScaleFactor 0.3

using namespace std;
using namespace sf;

class MovingElt{

	protected :
		Vector2f position;
		Sprite im;

	public :
		MovingElt(){};
		MovingElt(Vector2f p) : position(p){};
		virtual ~MovingElt(){};
		Vector2f getPosition(){ return position;}
		virtual void reoriente(int) = 0;
		virtual void deplace() = 0;
		Sprite getIm(){return im;}
		void setIm(Texture* t)
		{ 
			im.setTexture(*t);
			im.scale(Vector2f(ScaleFactor,ScaleFactor));
		}
		void setImPos()
		{
			im.setPosition(this->position);
		}
		virtual void displayInWindow(SFMLManager&) =0;
};

#endif
