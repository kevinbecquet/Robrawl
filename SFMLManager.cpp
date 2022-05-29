#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Joueur.hpp"
#include <iostream>

//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager()
{
	window = new RenderWindow(VideoMode(800,600),"Robrawl");
	window->setVerticalSynEnabled(true) //frame rate
	window->clear(Color::Black);
}
 
//Déstructeur de l'instance
SFMLManager::~SFMLManager()
{
	delete window;
}

//Renvoie de l'attribut fenêtre en pointeur
RenderWindow& SFMLManager::getWindow()
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
	window->display();
	
	cout << "Fermez la fenêtre pour finir le jeu" << endl; 
	
	while(window->IsOpen())
	{
		Event e;
		while(window->pollEvent(e))
		{
			if(event.type == Event::Closed)
				window->close();
			
			/*if(event.type == Event::KeyPressed)
			{
				if(event.key.code == Keyboard::q || event.key.code == Keyboard::j)
					rob.reoriente(-1);
				else if(event.key.code == Keyboard::d || event.key.code == Keyboard::l)
					rob.reoriente(1);
			/*	else if(event.key.code == Keyboard::s || event.key.code == Keyboard::k)
					rob.attaque();*/
			//}
				
		}
	}
}

//Afficher un obstacle ou un joueur 
void SFMLManager::displayObstacle(const Obstacle& o)
{
	//Image = texture
	Texture texture;
	if(!(texture.loadFromFile("Image/obstacle_test.jpeg"))
	{
		cout << "Fail to load obstacle image/texture" << endl;
		exit 0;
	}
	o.setImage(texture); //Position (0,0), taille de l'image
	o.getImage().setPosition(o.getPosition());
	
	this->getWindow().draw(o.getImage());
}

void SFMLManager::displayJoueur(const Joueur& j)
{
	window->draw(j);
}

/*
void SFMLManager::displayText(const Text& t)
{
	window->draw(t);
}
*/		



	
