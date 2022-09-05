#include "MovingElt.hpp"

MovingElt::~MovingElt(){}

int MovingElt::getVie(){
    return vie;
}

string MovingElt::getNom(){
	return nom;
}

Vector2f MovingElt::getPosition(){ 
    return position;
}

float MovingElt::getOrientation(){
    return orientation;
}

int MovingElt::getHeight(){
    return height;
}
int MovingElt::getWidth(){
    return width;
}

Sprite MovingElt::getIm(){
    return im;
}

void MovingElt::setVie(int hp){ 
    vie = hp; 
}

void MovingElt::setIm(Texture* t){

	im.setTexture(*t);
	im.scale(Vector2f(ScaleFactor,ScaleFactor));	
}

void MovingElt::setImPos(){
	im.setPosition(this->position);
}
