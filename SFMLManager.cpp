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
	
	
	int direct = 0;
	Event e;
	while(window->isOpen())
	{
		
		while(window->pollEvent(e))
		{
			//key manager 
			if(e.type == Event::KeyPressed)
			{
				if(e.key.code == Keyboard::Q || e.key.code == Keyboard::J)
					direct = -1;
				
				if(e.key.code == Keyboard::D || e.key.code == Keyboard::L)
					direct = 1;
								
				else
					direct = 0;
			}	
			for(size_t i = 0; i < map.getElem().size(); i++)
			{
				map.getElem()[i]->reoriente(direct);
				map.getElem()[i]->deplace();
				map.getElem()[i]->setImPos();
				cout << map.getElem()[i]->getPosition().x << " " << map.getElem()[i]->getPosition().y << endl;
				window->clear(Color::Black);
					
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



	
