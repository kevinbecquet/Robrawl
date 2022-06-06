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


				//key manager
				if(e.type == Event::KeyPressed)
				{
					if(e.key.code == Keyboard::Q)
					{
						map.getElem()[0]->reoriente(1);

					}

					if(e.key.code == Keyboard::D)
					{
						map.getElem()[0]->reoriente(-1);

					}

					if(e.key.code == Keyboard::J)
					{
						map.getElem()[1]->reoriente(1);

					}

					if(e.key.code == Keyboard::L)
					{
						map.getElem()[1]->reoriente(-1);

					}
				}



			if(e.type == Event::Closed || e.key.code == Keyboard::Escape)
				window->close();
			}

			window->clear();
			for(size_t i = 0; i < map.getElem().size(); i++)
				{
					map.getElem()[i]->deplace(map);
					map.getElem()[i]->setImPos();


					//cout << map.getElem()[i]->getPosition().x << " " << map.getElem()[i]->getPosition().y << endl;

					window->draw(map.getElem()[i]->getIm());
				}
			for(size_t i = 0; i < map.getObs().size(); i++)
					window->draw(map.getObs()[i].getSprite());

			window->display();
		}
	}


void SFMLManager::displayRobot(Robot& rob)
{

	double o = rob.getOrientation();
	double x = 10*VITESSE * cos(o) +
					rob.getPosition().x;
	double y = 10*VITESSE * sin(o) +
					rob.getPosition().y;

	CircleShape circle(10);
	circle.setFillColor(Color::Blue);
	circle.setPosition(Vector2f(x,y));


	window->draw(rob.getIm());
	window->draw(circle);
	window->display();
}

void SFMLManager::displayObstacle(Obstacle& obs)
{
	window->draw(obs.getSprite());
	window->display();
}
