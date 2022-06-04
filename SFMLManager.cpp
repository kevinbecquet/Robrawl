#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include <iostream>

Event e;

//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager()
{
	window = new RenderWindow(VideoMode(WIDTH,HEIGHT),"Robrawl");
	window->clear(Color::Black);
}
 
//Déstructeur de l'instance
SFMLManager::~SFMLManager()
{
	delete window;
}

//Renvoie de l'attribut fenêtre en pointeur
RenderWindow*& SFMLManager::getWindow()
{
	return window;
}

//fermeture de la fenêtre et gestion des touches clavier
//Clavier Azerty - les touches considérées : q, s, d et j, k, l
//q et j : aller à gauche
//d et l : aller à droite
//s et k : attaquer
//Trois par joueurs et pour le moment 2 joueurs
void SFMLManager::eventManager()
{
	
	cout << "Fermez la fenêtre pour finir le jeu" << endl; 
	
	
	window->display();
	
	while(window->isOpen())
	{
		while(window->pollEvent(e))
		{
			if(e.type == Event::Closed)
				window->close();
				
		}
	}
}

//Afficher un obstacle ou un joueur 
void SFMLManager::displayObstacle(Obstacle& o)
{
	window->draw(o.getSprite());
}



void SFMLManager::displayRobot(Robot& rob)
{
	
	
	if(e.type == Event::KeyPressed)
	{
		if(event.key.code == Keyboard::q || event.key.code == Keyboard::j)
			rob.reoriente(-1);
		else if(event.key.code == Keyboard::d || event.key.code == Keyboard::l)
			rob.reoriente(1);
		else if(event.key.code == Keyboard::s || event.key.code == Keyboard::k)
			rob.attaque();
	}
	window->draw(rob);
}

/*
void SFMLManager::displayText(const Text& t)
{
	window->draw(t);
}
*/		



	
