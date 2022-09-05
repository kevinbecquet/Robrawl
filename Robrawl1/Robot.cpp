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

	//Les robots sont contraints à rester dans la fenetre
	x = constrain(x,0,WIDTH-width);
	y = constrain(y,0,HEIGHT-height);

	//collision avec les obstacles
	bool collided = false; 
	for(Obstacle obs: map.getObs()){
		Vector2f pObs = obs.getPosition();

		
		if((abs((x)-(pObs.x+obs.getWidth()/2))<SEUIL_X) && 
			(abs((y+height/2)-(pObs.y+obs.getHeight()/2))<SEUIL_Y))
		{				
			collided = true;
			if( abs((x)-(pObs.x+obs.getWidth()/2))>SEUIL_X ||
				abs((position.y+height/2)-(pObs.y+obs.getHeight()/2))>SEUIL_Y)
			
				position.x = x;
			
			if( abs((y+height/2)-(pObs.y+obs.getHeight()/2))>SEUIL_Y ||
				abs((position.x)-(pObs.x+obs.getWidth()/2))>SEUIL_X)
				
				position.y = y;
		}
	
	}
	// si aucune collision, le robot avance normalement
	if(!collided){
		position.x = x;
		position.y = y;

	}

	// decrementation du cooldown
	if(cooldown >0){
		cooldown--;
	}	
	
}

//Permet au Robot de tourner suivant le signe de la direction indiquée
void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;	
}

// Le Robot lance un si son cooldown le lui permet
void Robot::attaque(Terrain& map){
	if(cooldown >0) {
		
		return; // le robot doit attendre avant d'envoyer une autre attaque
	}
	else{
		cooldown = 40; 
		map.ajout(launchMissile(map));	
	} 
}

// création d'un missile à lancer 
Missile* Robot::launchMissile(Terrain& map){
		
		// nom du missile (nombre indiquant combien de missile ont deja été lancés) 
		string misNom = to_string(map.addMissile());

		// position du missile : devant le Robot
		double misX = position.x+ getWidth()/2 + cos(orientation)*5;
		double misY = position.y+ getHeight()/2 + sin(orientation)*5;
		Vector2f misPos = Vector2f(misX,misY);

		// creéation d'un missile
		Missile* mis = new Missile(misPos,misNom,orientation,5,20,1,nom);

		// initialisation de son image
		Texture* texture = loadImg("Image/missile.png");
		mis->setIm(texture);
		mis->setImPos();

		return mis;
}

void Robot::displayInWindow(SFMLManager& render)
{	
	render.displayRobot(*this);
}
