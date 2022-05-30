#ifndef ELEMENT
#define ELEMENT

#include "SFMLManager.hpp"
#include <memory>

using namespace std;
using namespace sf;

class Element{
	
	protected :
		Vector2f position;
	
	public :
		Element(){};
		Element(Vector2f p) : position(p){};
		virtual void displayInWindow(SFMLManager& s) = 0;
		virtual ~Element() {};
		Vector2f getPosition(){ return position;}
};

typedef shared_ptr<Element> elem_ptr;

#endif
