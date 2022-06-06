#include "Robot.hpp"

void Robot::deplace(Terrain& map)
{


	double x = VITESSE * cos(orientation) +
					position.x;
	double y = VITESSE * sin(orientation) +
					position.y;



		for(Obstacle obs: map.getObs()){
			Vector2f pObs = obs.getPosition() + Vector2f(W_OBS/2,H_OBS/2);

			if((abs((x+W_ROB/2)-pObs.x)>SEUIL_X /*|| abs((y+H_ROB/2)-pObs.y)>SEUIL_Y*/) && x > 0 && x < WIDTH-W_ROB ){
				position.x = x;
			}
			if((abs((y+H_ROB/2)-pObs.y)>SEUIL_Y /*||abs((x+W_ROB/2)-(pObs.x))>SEUIL_X*/) && y > 0 && y < HEIGHT-H_ROB){
				position.y = y;
			}
		}
}


void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
	//if (orientation > 360) orientation -= 360;
	//else if (orientation < 360) orientation += 360;
}

void Robot::displayInWindow(SFMLManager& render)
{
	render.displayRobot(*this);
}
