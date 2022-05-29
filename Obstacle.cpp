#include "Obstacle.hpp"


Obstacle::Obstacle()
{
	srand(time(NULL));
	position.x = rand()%800;
	position.y = rand()%600;
}

void Obstacle::displayInWindow(SFMLManager& s) 
{
	s.displayObstacle(*this);
}
