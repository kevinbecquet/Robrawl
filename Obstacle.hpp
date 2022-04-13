#ifndef OBSTACLE
#define OBSTACLE

#include <iostream>
#include "Point.hpp"
#include <SFML/Graphics.hpp>

using namespace std

class Obstacle
{
	private :
		Point position;
		sf::Image image;
		//forme
	
	public :
		Obstacle(Point pos, /*frm,*/ sf::Image im) : position(pos), /*forme(frm),*/ image(im){};
		void getPosition(){ return position;}
		void getForme(){ return forme;}
		void affiche();
};
		
#endif 
