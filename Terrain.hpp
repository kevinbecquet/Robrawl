#ifndef TERRAIN
#define TERRAIN

#include "MovingElt.hpp"
#include "Obstacle.hpp"

class Terrain
{

	private :
		vector<MovingElt*> elem;
		vector<Obstacle> obs;
	
	public :
		void ajout(MovingElt* e);
		void ajout(Obstacle o);
		vector<Obstacle> getObs(){return obs;}
		vector<MovingElt*> getElem(){ return elem;}
		void displayInWindow(SFMLManager& render);
		
};

vector<Texture*> loadObstacles();
bool check_pos(vector<Vector2f> position, Vector2f pos);
vector<Robot*> loadRobot(Robot* rob, vector<Vector2f> start_pt);


#endif 
