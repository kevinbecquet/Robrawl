#ifndef SFML
#define SFML

#include <SFML/Graphics.hpp>

class Obstacle;
class Robot;
class Terrain;
class Missile;


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

		void eventManager(Terrain& map);

		void displayRobot(Robot& rob);
		void displayObstacle(Obstacle& obs);
		void displayMissile(Missile& mis);

		void displayWindow(Terrain& map);

};

#endif