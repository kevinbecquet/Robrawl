#include "Robot.hpp"

void Robot::deplace()
{


	double x = VITESSE * cos(orientation) +
					position.x;
	double y = VITESSE * sin(orientation) +
					position.y;

	position.x = x;
	position.y = y;
}

void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
	//if (orientation > 360) orientation -= 360;
	//else if (orientation < 360) orientation += 360;
}


void Robot::displayInWindow(SFMLManager& s){
	s.displayRobot(*this);
}
