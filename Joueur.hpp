#ifndef JOUEUR
#define JOUEUR

#include "Robot.hpp"
#include "Element.hpp"

class Joueur : public Element
{
	string nom;
	Robot bot;

	Joueur(string n, Robot r)
	{
		nom = n;
		bot = r; //marche grâce à l'opérateur d'assignement
	}	
	//En relation avec les touches
	void action(const SFMLManager& r);
	void displayInWindow(SFMLManager& s) const;
};

#endif
