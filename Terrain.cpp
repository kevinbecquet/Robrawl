#include "Terrain.hpp"
#include "Obstacle.hpp"
	
//Ajouter des élements dans le terrain (map)
void Terrain::ajout(Element* e)
{
	elem.push_back(e);
}

//Les afficher dans le terrain 
void Terrain::displayInWindow(SFMLManager& render)
{
	
	for(size_t i = 0; i < elem.size(); i++)
		elem[i]->displayInWindow(render);
		
	render.eventManager();
	
}
	
int main()
{
	Terrain map;
	
	SFMLManager f;
	
	Obstacle* o1 = new Obstacle();
	//Robot r1("O6",Vector2f(0,0),90,100);
	//Joueur J1("Gabriel",r1);
	
	map.ajout(o1);
	
	cout << o1->getPosition().x <<" "<< o1->getPosition().y << endl;
	
	map.displayInWindow(f);

	return 0;
}
