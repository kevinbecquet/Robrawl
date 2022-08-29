#include "Missile.hpp"

bool Missile::isColliding(MovingElt& e){
    
}

void Missile::deplace(Terrain& map)
{

	double x = vitesse * cos(orientation) +
					position.x;
	
	double y = vitesse * sin(orientation) +
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