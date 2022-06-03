#ifndef TERRAIN
#define TERRAIN

#include "Element.hpp"
#include "MovingElt.hpp"

class Terrain
{

	private :
		vector<elem_ptr> elem;
		vector<mvElt_ptr> mvElem;

	public :
		void ajout(elem_ptr e);
		vector<elem_ptr> getElem(){ return elem;}
		void displayInWindow(SFMLManager& render);

};

#endif
