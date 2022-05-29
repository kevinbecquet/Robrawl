#ifndef JOUEUR
#define JOUEUR

#include "Robot.hpp"
#include "Element.hpp"

class Joueur : public Element
{
	string nom;
	Robot bot;

	Joueur(string n, Robot r);
	//En relation avec les touches
	void action(SFMLManager& r);
	//void displayInWindow(SFMLManager& s) const;
};

#endif
