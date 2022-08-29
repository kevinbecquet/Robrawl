#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "Terrain.hpp"
#include <iostream>


//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager()
{
	window = new RenderWindow(VideoMode(WIDTH,HEIGHT),"Robrawl");
	window->setFramerateLimit(60);

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
	Event e;

	while(window->pollEvent(e))
	{
		window->clear(Color::Black);


			//key manager
			if(e.type == Event::KeyPressed)
			{
				if(e.key.code == Keyboard::Q)
				{
					map.getElem()[0]->reoriente(-1);

				}

				if(e.key.code == Keyboard::D)
				{
					map.getElem()[0]->reoriente(1);

				}

				if(e.key.code == Keyboard::J)
				{
					map.getElem()[1]->reoriente(-1);

				}

				if(e.key.code == Keyboard::L)
				{
					map.getElem()[1]->reoriente(1);

				}
			}



		if(e.type == Event::Closed || e.key.code == Keyboard::Escape)
			window->close();
		}

			for(size_t i = 0; i < map.getElem().size(); i++)
				{
					map.getElem()[i]->deplace(map);
					map.getElem()[i]->setImPos();	
				}
			
	}


void SFMLManager::displayRobot(Robot& rob)
{

	double o = rob.getOrientation();
	double x = VITESSE * cos(o) +
					rob.getPosition().x;
	double y = VITESSE * sin(o) +
					rob.getPosition().y;

	CircleShape nextPos(5);
	nextPos.setFillColor(Color::White);
	nextPos.setPosition(Vector2f(x,y));


	RectangleShape robBox;
	robBox.setPosition(Vector2f(rob.getPosition().x,rob.getPosition().y));
	robBox.setSize(Vector2f(W_ROB,H_ROB));
	robBox.setFillColor(Color::Blue);


	//window->draw(rob.getIm());
	window->draw(robBox);
	window->draw(nextPos);

	
}

void SFMLManager::displayObstacle(Obstacle& obs)
{	
	window->draw(obs.getSprite());
	
}
