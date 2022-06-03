#ifndef SFML
#define SFML


#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle;
class Robot;

#define WIDTH 1000
#define HEIGHT 800

using namespace std;
using namespace sf;

class SFMLManager{
	protected :
		RenderWindow* window;

	public :
		SFMLManager();
		~SFMLManager();
		RenderWindow*& getWindow();
		void eventManager();
		//gestionCollision();
		void displayObstacle(Obstacle& o);
		void displayRobot(Robot& rob);
		//void displayText(const Text& t);


		void clearWindow();
};

#endif
