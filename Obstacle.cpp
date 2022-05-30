#include "Obstacle.hpp"


Obstacle::Obstacle(Texture* t, Vector2f pos) : Element(pos)
{
	//We set the sprite's texture and position 
	sprite.setTexture(*t);
	sprite.setPosition(position);
}

void Obstacle::displayInWindow(SFMLManager& s) 
{
	s.displayObstacle(*this);
}
