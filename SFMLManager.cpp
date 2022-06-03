#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "MovingElt.hpp"
#include <iostream>

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
		Event e;
		while(window->pollEvent(e))
		{
			if(e.type == Event::Closed)
				window->close();

			/*if(e.type == Event::KeyPressed)
			{
				if(event.key.code == Keyboard::q || event.key.code == Keyboard::j)
					rob.reoriente(-1);
				else if(event.key.code == Keyboard::d || event.key.code == Keyboard::l)
					rob.reoriente(1);
				else if(event.key.code == Keyboard::s || event.key.code == Keyboard::k)
					rob.attaque();*/
			//}

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

	double x = rob.getPosition().x;
	double y = rob.getPosition().y;
	CircleShape circle(8); // Create circle
	circle.setPosition(floor(x - 13), floor(y - 13)); //  We must convert the center position to the top left point position
	circle.setFillColor(Color::Red);

	window->draw(circle);
}


void SFMLManager:: clearWindow()
{
	window->clear();
}

/*
void SFMLManager::displayText(const Text& t)
{
	window->draw(t);
}
*/
