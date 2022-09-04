#include "Robot.hpp"

// contraint la valeur de x dans l'intervalle [a,b]
// retourne a si x<a ; b si x>b et x sinon 
double constrain(double x, double a, double b){
	return max(min(x,b),a);
}


// execute 1 incrément de déplacement du robot en vérifiant si ce dernier entre en collision avec un obstacle
void Robot::deplace(Terrain& map){

	int width = getWidth();
	int height = getHeight();

	double x = vitesse* cos(orientation) +
					position.x;
	
	double y = vitesse * sin(orientation) +
					position.y;

	x = constrain(x,0,WIDTH-width);
	y = constrain(y,0,HEIGHT-height);

	 
		for(Obstacle obs: map.getObs()){
			Vector2f pObs = obs.getPosition();

			
			if((abs((x+width/2)-(pObs.x+obs.getWidth()/2))<SEUIL_X) && 
			   (abs((y+height/2)-(pObs.y+obs.getHeight()/2))<SEUIL_Y))
			{				

				if( abs((x+width/2)-(pObs.x+obs.getWidth()/2))>SEUIL_X ||
					abs((position.y+height/2)-(pObs.y+obs.getHeight()/2))>SEUIL_Y)
				
					position.x = x;
				
				if( abs((y+height/2)-(pObs.y+obs.getHeight()/2))>SEUIL_Y ||
					abs((position.x+width/2)-(pObs.x+obs.getWidth()/2))>SEUIL_X)
					
					position.y = y;
			}
			else{
				position.x = x;
				position.y = y;
			}
		
		}
	
	if(countdown >0){
		countdown--;
	}	
	
}

void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
	
}

void Robot::attaque(Terrain& map){
	if(countdown >0) {
		
		return; // le robot doit attendre avant d'envoyer une autre attaque
	}
	else{
		countdown = 20;
		map.ajout(launchMissile(map));	
	} 
}
Missile* Robot::launchMissile(Terrain& map){
		
		string misNom = to_string(map.addMissile());

		double misX = position.x+ getWidth()/2 + cos(orientation)*5;
		double misY = position.y+ getHeight()/2 + sin(orientation)*5;
		Vector2f misPos = Vector2f(misX,misY);

		Missile* mis = new Missile(misPos,misNom,orientation,5,20,10,nom);

		Image* im = new Image;
		Texture* texture = new Texture;
		
		im->loadFromFile("Image/missile.png");
		
		texture->loadFromImage(*im);
		mis->setIm(texture);
		mis->setImPos(misPos);

		
		return mis;
}


void Robot::displayInWindow(SFMLManager& render)
{	
	render.displayRobot(*this);
}
