#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "Terrain.hpp"
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
void SFMLManager::eventManager(Terrain map)
{
	
	cout << "Fermez la fenêtre pour finir le jeu" << endl; 
	
	
	Event e;
	while(window->isOpen())
	{
		
		while(window->pollEvent(e))
		{
			window->clear(Color::Black);
			for(size_t i = 0; i < map.getElem().size(); i++)
			{
			
				//key manager 
				if(e.type == Event::KeyPressed)
				{
				
					if(map.getElem()[i]->getNom() == "Robot1")
					{	
						if(e.key.code == Keyboard::Q)
						{
							map.getElem()[i]->reoriente(-1);
							map.getElem()[i]->deplace();
							map.getElem()[i]->setImPos();
						}
						
						if(e.key.code == Keyboard::D)
						{
							map.getElem()[i]->reoriente(-1);
							map.getElem()[i]->deplace();
							map.getElem()[i]->setImPos();
						}
					}
					if(map.getElem()[i]->getNom() == "Robot2")
					{	
						if(e.key.code == Keyboard::J)
						{
							map.getElem()[i]->reoriente(1);
							map.getElem()[i]->deplace();
							map.getElem()[i]->setImPos();
						}
						
						if(e.key.code == Keyboard::L)
						{
							map.getElem()[i]->reoriente(1);
							map.getElem()[i]->deplace();
							map.getElem()[i]->setImPos();
						}
					}
				}		
					
					//cout << map.getElem()[i]->getPosition().x << " " << map.getElem()[i]->getPosition().y << endl;
						
					window->draw(map.getElem()[i]->getIm());
				}
			for(size_t i = 0; i < map.getObs().size(); i++)
					window->draw(map.getObs()[i].getSprite());
			
			window->display();	
			
			if(e.type == Event::Closed)
				window->close();
			}
		}	
	}


void SFMLManager::displayRobot(Robot& rob)
{
	window->draw(rob.getIm());
	window->display();
}

void SFMLManager::displayObstacle(Obstacle& obs)
{
	window->draw(obs.getSprite());
	window->display();
}



	
