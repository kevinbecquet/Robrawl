#ifndef POINT
#define POINT

#include <iostream>

using namespace std;

//Une classe qui donne les coordonnées d'un point
class Point{

	private :
		double posX;
		double posY;

	public :
		Point(double x, double y) : posX(x), posY(y){};
		double getX(){ return posX;}
		double getY(){ return posY;}

		void setX(double x){ posX = x;}
		void setY(double y){ posY = y;}
};

#endif
