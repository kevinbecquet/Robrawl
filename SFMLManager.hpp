#ifndef SFML
#define SFML


#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle;
class Robot;
class Missile;
class Terrain;

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
		void eventManager(Robot*,Missile*,Terrain);
		void displayRobot(Robot& rob);
		void displayObstacle(Obstacle& obs);
		void displayMissile(Missile& miss);

};

#endif
