#ifndef ELEMENT
#define ELEMENT

#include "Obstacle.hpp"
#include "Joueur.hpp"
#include "Texte.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Element{
	
	virtual void displayInWindow(SFMLManager& s) = 0;

};

#endif
