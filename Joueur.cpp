#include "Joueur.hpp"

void Joueur::displayInWindow(SFMLManager& s) const
{
	s.displayJoueur(*this);
}
