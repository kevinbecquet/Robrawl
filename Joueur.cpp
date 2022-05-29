#include "Joueur.hpp"

void Joueur::displayInWindow(SFMLManager& s) const
{
	s.displayJoueur(*this);
}

void Joueur::action(const SFMLManager& r)
{
	r.eventManager(bot);
}
