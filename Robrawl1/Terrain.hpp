#ifndef TERRAIN
#define TERRAIN

#include "MovingElt.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"


class Terrain
{

	private :
		vector<MovingElt*> elem;
		vector<Obstacle> obs;
		int countMissile = 0;
	public :
		void ajout(MovingElt* e);
		void ajout(Obstacle o);

		int addMissile();
		void supprElem();

		vector<Obstacle> getObs(){return obs;}
		vector<MovingElt*> getElem(){ return elem;}

		void displayInWindow(SFMLManager& render);
		void action();

};

vector<Texture*> loadObstacles(int n);
bool check_pos(vector<Vector2f> position, Vector2f pos);
vector<Robot*> loadRobot(Robot* rob, vector<Vector2f> start_pt);



#endif
