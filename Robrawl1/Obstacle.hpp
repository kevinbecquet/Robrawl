#ifndef OBSTACLE
#define OBSTACLE

#include "SFMLManager.hpp"


#define scaleFactor 0.25

#define H_OBS 25
#define W_OBS 45
using namespace sf;


class Obstacle
{
	private :
		Sprite sprite;
		Vector2f position;
		int height;
		int width;

	public :
		Obstacle(Texture* t, Vector2f pos, int h, int w);

		Sprite getSprite(){ return sprite; }
		Vector2f getPosition(){ return position;}
		int getHeight(){return height;}
		int getWidth(){return width;}

		void displayInWindow(SFMLManager& render);
};

#endif
