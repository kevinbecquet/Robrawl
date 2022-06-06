#ifndef SFML
#define SFML


#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle;
class Robot;
class Terrain;

#define WIDTH 800
#define HEIGHT 500

using namespace std;
using namespace sf;

class SFMLManager{
	protected :
		RenderWindow* window;

	public :
		SFMLManager();
		~SFMLManager();
		RenderWindow*& getWindow();
		void eventManager(Terrain map);
		void displayRobot(Robot& rob);
		void displayObstacle(Obstacle& obs);

};

#endif
