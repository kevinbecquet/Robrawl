#include "SFMLManager.hpp"

//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager()
{
	window = new RenderWindow(VideoMode(800,600),"Robrawl");
	window->clear(Color::Black);
}
 
//Déstructeur de l'instance
SFMLManager::~SFMLManager()
{
	delete window;
}

//Renvoie de l'attribut fenêtre
RenderWindow& SFMLManager::getWindow()
{
	return window;
}


