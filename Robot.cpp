#include "Robot.hpp"

void Robot::deplace()
{


	double x = VITESSE * cos(orientation) +
					position.getX();
	double y = VITESSE * sin(orientation) +
					position.getY();

	position.setX(x);
	position.setY(y);
}

void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
	//if (orientation > 360) orientation -= 360;
	//else if (orientation < 360) orientation += 360;
}
