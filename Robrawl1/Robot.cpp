#include "Robot.hpp"

double constrain(double x, double a, double b){
	return max(min(x,b),a);
}



void Robot::deplace(Terrain& map)
{	
	int width = getWidth();
	int height = getHeight();

	double x = VITESSE * cos(orientation) +
					position.x;
	
	double y = VITESSE * sin(orientation) +
					position.y;

	x = constrain(x,0,WIDTH-width);
	y = constrain(y,0,HEIGHT-height);

	int count = 0; 
		for(Obstacle obs: map.getObs()){
			Vector2f pObs = obs.getPosition() + Vector2f(W_OBS/2,H_OBS/2);

			


			if((abs((x)-(pObs.x-obs.getWidth()))<SEUIL_X) && 
			   (abs((y)-(pObs.y-obs.getHeight()))<SEUIL_Y))
			// if((abs((x)-(pObs.x))<SEUIL_X) && 
			//    (abs((y)-(pObs.y))<SEUIL_Y))
			{				

				if( abs((x)-(pObs.x-obs.getWidth()))>SEUIL_X ||
					abs((position.y)-(pObs.y-obs.getHeight()))>SEUIL_Y)
				
					position.x = x;
				
				if( abs(y)-(pObs.y-obs.getHeight())>SEUIL_Y ||
					abs((position.x)-(pObs.x-obs.getWidth()))>SEUIL_X)
					
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
	
}

void Robot::displayInWindow(SFMLManager& render)
{
	render.displayRobot(*this);
}
