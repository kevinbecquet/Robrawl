#include "Joueur.hpp"


Joueur::Joueur(string n, Robot r) : nom(n), bot(r){};

/*
void Joueur::displayInWindow(SFMLManager& s) const
{
	s.displayJoueur(*this);
}*/

void Joueur::action(SFMLManager& r)
{
	r.eventManager();
}
