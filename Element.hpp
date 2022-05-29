#ifndef ELEMENT
#define ELEMENT

#include "SFMLManager.hpp"

using namespace std;
using namespace sf;

class Element{
	
	public :
		virtual void displayInWindow(SFMLManager& s) const = 0;

};

#endif
