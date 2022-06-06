#include "Obstacle.hpp"


Obstacle::Obstacle(Texture* t, Vector2f pos)
{
	position.x  = pos.x;
	position.y = pos.y;
	//We set the sprite's texture and position 
	sprite.setTexture(*t);
	sprite.setPosition(position);
	sprite.scale(Vector2f(scaleFactor,scaleFactor));
}

void Obstacle::displayInWindow(SFMLManager& s) 
{
	s.displayObstacle(*this);
}
