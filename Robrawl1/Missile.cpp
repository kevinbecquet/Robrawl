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
		
		vie = 0; // the missile is destroyed 
		damage(elt); // it damages the object in contact 
		return true;	
	}
	return false;
}

bool Missile::isColliding(Obstacle& obs){
	int seuilX = width+obs.getWidth()/2;
	int seuilY = height+obs.getHeight()/2;
	
	Vector2f pElt = obs.getPosition();
	if (abs((position.x+width/2) - (pElt.x + obs.getWidth()/2))<seuilX &&
		abs((position.y+height/2) - (pElt.y + obs.getHeight()/2))<seuilY){
		 vie = 0; // the missile is destroyed
		return true;	
	}
	return false;
}

void Missile::deplace(Terrain& map)
{
	// deplacement du missile
	double x = vitesse * cos(orientation) + position.x;
	double y = vitesse * sin(orientation) + position.y;
	position = Vector2f(x,y);


	//le missile explose au contact d'un autre MovingElt ou d'un Obstacle ou s'il sort de la fenetre
	bool explodes =(x>WIDTH || y>HEIGHT || x<0 || y<0)? true : false; 
	
	for(MovingElt* e: map.getElem()){
		
		if(e->getNom()!= nom && e->getNom()!= launcher )
			if (isColliding(*e)) explodes = true;
	}

	if(!explodes)
		for(Obstacle obs: map.getObs()){
			if(isColliding(obs)){
				break;
			}
		}
	if(explodes) vie = 0;
	
}

void Missile::displayInWindow(SFMLManager& render){
	render.displayMissile(*this);
}


