#include "Robot.hpp"

double constrain(double x, double a, double b){
	return max(min(x,b),a);
}



void Robot::deplace(Terrain& map){

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
			Vector2f pObs = obs.getPosition();

			
			if((abs((x+width/2)-(pObs.x+obs.getWidth()/2))<SEUIL_X) && 
			   (abs((y+height/2)-(pObs.y+obs.getHeight()/2))<SEUIL_Y))
			{				

				if( abs((x+width/2)-(pObs.x+obs.getWidth()/2))>SEUIL_X ||
					abs((position.y+height/2)-(pObs.y-obs.getHeight()/2))>SEUIL_Y)
				
					position.x = x;
				
				if( abs((y+height/2)-(pObs.y+obs.getHeight()/2))>SEUIL_Y ||
					abs((position.x+width/2)-(pObs.x-obs.getWidth()/2))>SEUIL_X)
					
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
