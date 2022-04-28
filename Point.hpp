#ifndef POINT
#define POINT

#include <iostream>

using namespace std;

//Une classe qui donne les coordonnées d'un point
class Point{
	
	private :
		int X;
		int Y;
	
	public :
		Point(int x, int y) : X(x), Y(y){};
		int getX(){ return X;}
		int getY(){ return Y;}
};

#endif
