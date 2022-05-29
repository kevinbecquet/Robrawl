#ifndef OBSTACLE
#define OBSTACLE


#include <time.h>
#include "Element.hpp"

using namespace sf;


class Obstacle : public Element
{
	private :
		Sprite image;
		Vector2f position;
	
	public :
		Obstacle();
		Vector2f getPosition(){ return position;}
		Sprite getImage(){return image;}
		void setImage(Texture t){ image.setTexture(t);}
		void displayInWindow(SFMLManager& s);
};
		
#endif 
