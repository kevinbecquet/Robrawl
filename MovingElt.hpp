#ifndef MOVING_MovingElt
#define MOVING_MovingElt

#include "SFMLManager.hpp"
#include <memory>

using namespace std;
using namespace sf;

class MovingElt{

	protected :
		Vector2f position;

	public :
		MovingElt(){};
		MovingElt(Vector2f p) : position(p){};
		virtual void displayInWindow(SFMLManager& s) = 0;
    virtual void deplace() = 0;
		virtual ~MovingElt() {};
		Vector2f getPosition(){ return position;}
};

typedef shared_ptr<MovingElt> mvElt_ptr;

#endif
