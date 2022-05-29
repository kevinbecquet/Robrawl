#ifndef TERRAIN
#define TERRAIN

#include "Element.hpp"

class Terrain
{

	private :
		vector<Element*> elem;
	
	public :
		~Terrain(){ 
			for( Element* e : elem)
				delete e;
			}
		void ajout(Element* e);
		void displayInWindow(SFMLManager& render);
		
};

#endif 
