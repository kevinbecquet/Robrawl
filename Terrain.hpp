#ifndef TERRAIN
#define TERRAIN

#include <SFML/Graphics.hpp>
#include "Joueur.hpp"
#include "Obstacle.hpp"

using namespace sf

class Terrain
{
	private :
		Vector<Obstacle> Obs;
		Vector <Joueur> J;
		bool jeEnCours;
	
	public :
		Terrain();
		void pause(Keyboard::key p);
		void ajout(Obstacle o);
		void ajout(Joueur j);
		void affiche();

};

#endif 
