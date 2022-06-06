#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "Terrain.hpp"
#include "Missile.hpp"
#include <iostream>


//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager()
{
	window = new RenderWindow(VideoMode(WIDTH,HEIGHT),"Robrawl");
	window->clear(Color::Black);
	window->display();
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
void SFMLManager::eventManager(Robot* rob, Missile* missile, Terrain map)
{
	Event e;
	int fire = 0;
	while(window->pollEvent(e))
	{
		window->clear(Color::Black);
		//key manager 
		if(e.type == Event::KeyPressed)
		{
		
			if(rob->getNom() == "Robot1")
			{	
				if(e.key.code == Keyboard::Q)
				{
					rob->reoriente(-1);
					rob->deplace();
					rob->setImPos();
					cout << "q pressed" << endl;
				}
				if(e.key.code == Keyboard::D)
				{
					rob->reoriente(1);
					rob->deplace();
					rob->setImPos();
					cout << "d pressed" << endl;
				}
					
				if(e.key.code == Keyboard::S)
				{
					fire = 1;
					
					cout << "s pressed" << endl;
				}
				
			}
			if(rob->getNom() == "Robot2")
			{	
				if(e.key.code == Keyboard::J)
				{
					rob->reoriente(-1);
					rob->deplace();
					rob->setImPos();
					
					cout << "j pressed" << endl;
				}
				
				if(e.key.code == Keyboard::L)
				{
					rob->reoriente(1);
					rob->deplace();
					rob->setImPos();
					
					cout << "l pressed" << endl;
				}
					
				if(e.key.code == Keyboard::K)
				{
					fire = 1;
					
					cout << "k pressed" << endl;
				}
			}
	
		}	
							
		if(e.type == Event::Closed)
			window->close();
	}
	window->draw(rob->getIm());
	if(fire)
	{
		rob->attaque(missile,rob,*this);
		fire = 0;
	}
	for(Obstacle o : map.getObs())
		o.displayInWindow(*this);
	
	window->display();
}
	



void SFMLManager::displayRobot(Robot& rob)
{
	window->draw(rob.getIm());
	
}

void SFMLManager::displayObstacle(Obstacle& obs)
{
	window->draw(obs.getSprite());

}

void SFMLManager::displayMissile(Missile& miss)
{
	window->draw(miss.getIm());
}


	
