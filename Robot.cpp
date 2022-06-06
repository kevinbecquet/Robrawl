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

void Robot::displayInWindow(SFMLManager& render)
{
	render.displayRobot(*this);
}

void Robot::reoriente(int direction)
{
	orientation += direction*VITESSE_ROTATION ;
	//if (orientation > 360) orientation -= 360;
	//else if (orientation < 360) orientation += 360;
}

void Robot::attaque(Missile* missile, SFMLManager& render)
{
	Time t = milliseconds(100);
	//Convention : dernier élément de la map est un missile
	do
	{
		missile->deplace();
		missile->displayInWindow(render);
		sleep(t);
		
	}while(missile->inWindow());
}
