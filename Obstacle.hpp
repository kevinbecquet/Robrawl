#ifndef OBSTACLE
#define OBSTACLE


#include <time.h>
#include "Element.hpp"

using namespace sf;


class Obstacle : public Element
{
	private :
		Sprite sprite;
	
	public :
		Obstacle(Texture* t, Vector2f pos);
		Sprite getSprite(){ return sprite; }
		void displayInWindow(SFMLManager& s);
		
};
		
#endif 
