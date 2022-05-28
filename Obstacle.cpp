#include "Obstacle.hpp"

void Obstacle::displayInWindow(SFMLManager& s) const
{
	s.displayObstacle(*this);
}
