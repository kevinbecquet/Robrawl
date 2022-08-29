#include "Robot.hpp"

double constrain(double x, double a, double b){
	return max(min(x,b),a);
}

void Robot::deplace(Terrain& map)
{

	double x = VITESSE * cos(orientation) +
					position.x;
	
	double y = VITESSE * sin(orientation) +
					position.y;

	x = constrain(x,0,WIDTH-W_ROB);
	y = constrain(y,0,HEIGHT-H_ROB);
	int count = 0; 
		for(Obstacle obs: map.getObs()){
			Vector2f pObs = obs.getPosition() + Vector2f(W_OBS/2,H_OBS/2);

			


			if((abs((x)-(pObs.x))<SEUIL_X) && 
			   (abs((y)-(pObs.y))<SEUIL_Y))
			// if((abs((x)-(pObs.x))<SEUIL_X) && 
			//    (abs((y)-(pObs.y))<SEUIL_Y))
			{
				printf("Collides : %f,%f |%d,%d  ! \n",
						(abs((x+W_ROB/2)-(pObs.x+W_OBS/2))),
						(abs((y+H_ROB/2)-(pObs.y+H_OBS/2))),
						SEUIL_X,
						SEUIL_Y);
				

				if( abs((x)-(pObs.x))>SEUIL_X ||
					abs((position.y)-(pObs.y))>SEUIL_Y)
				
					position.x = x;
				
				if( abs(y)-(pObs.y)>SEUIL_Y ||
					abs((position.x)-(pObs.x))>SEUIL_X)
					
					position.y = y;
			}
			else{
				position.x = x;
				position.y = y;
			}
			count++; 
		}
}

/*void accelere(int sens){
	if (sens == 1) vitesse+= ;
	elif (sens == -1) vitesse -= ;

	vitesse = constrain(vitesse, -V_MAX/2, V_MAX); 
}*/

void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
	//if (orientation > 360) orientation -= 360;
	//else if (orientation < 360) orientation += 360;
}

void Robot::displayInWindow(SFMLManager& render)
{
	render.displayRobot(*this);
}
