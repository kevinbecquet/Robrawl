#ifndef TERRAIN
#define TERRAIN

#include <iostream>
#include <time.h>

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

		void loadRobot();
		void loadObstacles();

		int addMissile();
		void supprElem();

		vector<Obstacle> getObs(){return obs;}
		vector<MovingElt*> getElem(){ return elem;}

		void action();

		bool victoryCheck();

};

Texture* loadImg(string path);



#endif
