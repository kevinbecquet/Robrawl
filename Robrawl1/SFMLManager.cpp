#include "SFMLManager.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "Terrain.hpp"
#include <iostream>


//Constructeur création d'une fenêtre sfml
SFMLManager::SFMLManager(){

	window = new RenderWindow(VideoMode(WIDTH,HEIGHT),"Robrawl");
	window->setFramerateLimit(60);

	window->clear(Color::Black);
	window->display();
}

//Destructeur de l'instance
SFMLManager::~SFMLManager(){
	delete window;
}

//Renvoie de l'attribut fenêtre en pointeur
RenderWindow*& SFMLManager::getWindow(){
	return window;
}

// Gestion des touches clavier : execute une action en cas de touche pressée
//q et j : tourner à gauche
//d et l : tourner à droite
//z et i : attaquer 
void SFMLManager::eventManager(Terrain& map){
	Event e;

	window->pollEvent(e);
		
	//key manager

	if(Keyboard::isKeyPressed(Keyboard::Q))
		map.getElem()[0]->reoriente(-1);

	if(Keyboard::isKeyPressed(Keyboard::D))
		map.getElem()[0]->reoriente(1);
	
	if(Keyboard::isKeyPressed(Keyboard::Z))
		map.getElem()[0]->attaque(map);

	if(Keyboard::isKeyPressed(Keyboard::J))
		map.getElem()[1]->reoriente(-1);

	if(Keyboard::isKeyPressed(Keyboard::L))
		map.getElem()[1]->reoriente(1);

	if (Keyboard::isKeyPressed(Keyboard::I))
		map.getElem()[1]->attaque(map);
	//}
	if(e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
		window->close();	
}			
	

// Affichage et rotation de l'image du Robot dans la fenetre de jeu
void SFMLManager::displayRobot(Robot& rob){

	Sprite robImage = rob.getIm();
	robImage.setOrigin(rob.getWidth(),rob.getHeight());
	robImage.move(rob.getWidth()/2,rob.getHeight()/2);
	robImage.setRotation(rob.getOrientation()*180/M_PI);

	window->draw(robImage);	
}

// Affichage de l'image de l'Obstacle dans la fenetre de jeu
void SFMLManager::displayObstacle(Obstacle& obs){
	
	RectangleShape rect;
	rect.setOrigin(obs.getPosition());
	rect.setFillColor(Color::Black);
	rect.setSize(Vector2f(obs.getWidth(),obs.getHeight()));

	window->draw(rect);
	window->draw(obs.getSprite());
	
}

// Affichage de l'image du Missile dans la fenetre de jeu
void SFMLManager::displayMissile(Missile& mis){
	Sprite misImage = mis.getIm();
	misImage.setOrigin(mis.getWidth(),mis.getHeight());
	misImage.move(mis.getWidth()/2,mis.getHeight()/2);
	misImage.setRotation(mis.getOrientation()*180/M_PI);

	window->draw(misImage);
}


// Affichage globale du Terrain dans la fenetre de jeu  
void SFMLManager::displayWindow(Terrain& map){
	window->clear();	

	// image en arrière-plan
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("Image/background.jpeg");

	Sprite background;
	background.setTexture(backgroundTexture);
	background.setScale(WIDTH/background.getLocalBounds().width,
						HEIGHT/background.getLocalBounds().height);

	window->draw(background);

	// affichage des Obstacles
	for(Obstacle o : map.getObs())
		o.displayInWindow(*this);

	// affichage des MovingElt
	for(MovingElt* elt: map.getElem()){
		elt->displayInWindow(*this);
		
	}
	
	window->display();
}
