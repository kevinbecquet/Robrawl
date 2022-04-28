#include "Terrain.hpp"

int main()
{
	//Je test l'ouverture d'une fenetre avec sfml
	Terrain t(800,600,"Hello fighters!");
	Event e;
	while(t.jeuEnCours())
	{
		t.endOfGame(e);
	}
	
	return 0;
}
