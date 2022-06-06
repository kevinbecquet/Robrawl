#include "Missile.hpp"


Missile::Missile()
{
	Image* i = new Image;
	Texture* t = new Texture;
	i->loadFromFile("Image/Missile.jpeg");
	i->createMaskFromColor(Color::White);
	t->loadFromImage(*i);
	im.setTexture(*t);
	im.scale(Vector2f(ScaleFactor,ScaleFactor));
}

void Missile::deplace()
{
		
	position.x += 0.25;
	this->setImPos();
	//cout << "posMissile : " <<  "x :" << position.x << "y : " << position.y << endl;
}

bool Missile::inWindow()
{
	bool in_window;
	in_window = (position.x < WIDTH && position.x > 0);
	return in_window;
}

void Missile::displayInWindow(SFMLManager& render)
{
	render.displayMissile(*this);
}

//Initialise la position
void Missile::InitImPos(Robot* r)
{
	this->setImPos(r->getPosition());
}


