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

	window->pollEvent(e);
		
	//key manager

	if(e.type == Event::KeyPressed && e.key.code == Keyboard::Q)
	{
		map.getElem()[0]->reoriente(-1);

	}

	if(e.type == Event::KeyPressed && e.key.code == Keyboard::D)
	{
		map.getElem()[0]->reoriente(1);

	}

	if(e.type == Event::KeyPressed && e.key.code == Keyboard::J)
	{
		map.getElem()[1]->reoriente(-1);

	}

	if(e.type == Event::KeyPressed && e.key.code == Keyboard::L)
	{
		map.getElem()[1]->reoriente(1);

	}
	
	if(e.type == Event::Closed || e.key.code == Keyboard::Escape)
		window->close();
	

	for(size_t i = 0; i < map.getElem().size(); i++)
		{
			map.getElem()[i]->deplace(map);
			map.getElem()[i]->setImPos();	
		}
}			
	
void addOffsetImg(Sprite &object, const sf::Vector2f &offset)
{
        auto newOrigin = offset + object.getOrigin();
        object.setOrigin(newOrigin);
        object.move(offset);
}

void SFMLManager::displayRobot(Robot& rob)
{

	Sprite robImage = rob.getIm();
	robImage.setOrigin(rob.getWidth(),rob.getHeight());
	robImage.move(rob.getWidth()/2,rob.getHeight()/2);
	robImage.setRotation(rob.getOrientation()*180/M_PI);

	window->draw(robImage);	
}

void SFMLManager::displayObstacle(Obstacle& obs)
{	
	window->draw(obs.getSprite());
	
}
