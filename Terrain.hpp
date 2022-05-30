#ifndef TERRAIN
#define TERRAIN

#include "Element.hpp"

class Terrain
{

	private :
		vector<elem_ptr> elem;
	
	public :
		void ajout(elem_ptr e);
		vector<elem_ptr> getElem(){ return elem;}
		void displayInWindow(SFMLManager& render);
		
};

#endif 
