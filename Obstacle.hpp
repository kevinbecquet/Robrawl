#ifndef OBSTACLE
#define OBSTACLE

#include "Point.hpp"
#include <SFML/Graphics.hpp>


using namespace sf;

class Obstacle
{
	private :
		Point position;
		Image image;
		//forme
	
	public :
		Obstacle(Point pos, /*frm,*/ sf::Image im) : position(pos), /*forme(frm),*/ image(im){};
		Point getPosition(){ return position;}
		//void getForme(){ return forme;}
		void displayInWindow(SFMLManager& s);
};
		
#endif 
