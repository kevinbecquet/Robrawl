#include "Missile.hpp"

void Missile::damage(MovingElt& elt){
	int hpElt = elt.getVie();
	hpElt -= dmg;
	elt.setVie(hpElt); 
}

bool Missile::isColliding(MovingElt& elt){
    int seuilX = width+elt.getWidth()/2;
	int seuilY = height+elt.getHeight()/2;
	
	Vector2f pElt = elt.getPosition();
	if (abs((position.x+width/2) - (pElt.x + elt.getWidth()/2))<seuilX &&
		abs((position.y+height/2) - (pElt.y + elt.getHeight()/2))<seuilY){
		
		dmg = 0; // the missile is destroyed 
		damage(elt); // it damages the object in contact 
		return true;	
	}
	return false;
}

void Missile::deplace(Terrain& map)
{

	double x = vitesse * cos(orientation) + position.x;
	
	double y = vitesse * sin(orientation) + position.y;

	bool explodes = false;
	
	for(Obstacle obs: map.getObs()){
		
		
		


	
		
	}
}