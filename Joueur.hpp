#ifndef JOUEUR
#define JOUEUR

#include "Robot.hpp"

class Joueur : public Element
{
	string nom;
	//Keyboard::Key[3] touches;
	//Robot bot;

	Joueur(string n/*, Keyboard::key[3] keys Robot r*/);
	void setTouche(/*Keyboard tou*/);
	void action();
	void displayInWindow(SFMLManager& s) const;
};

#endif
