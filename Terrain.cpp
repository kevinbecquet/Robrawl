#include "Terrain.hpp"
#include "Obstacle.hpp"

//Ajouter des élements dans le terrain (map)
void Terrain::ajout(elem_ptr e)
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

vector<Texture*> loadObstacles()
{
	vector<Texture*> texture;
	Texture* t;
	int counterObstacle = 1;
	
	while(counterObstacle != 0)
	{
		t = new Texture;
		cout << "counterObstacle = " << counterObstacle << endl;
		if(!t->loadFromFile("Image/Obstacles/Obstacles"+to_string(counterObstacle)+".jpeg"))
		{
			cout << "Failed to load image" << endl;
			counterObstacle = 0;
		}
		else
		{
			texture.push_back(t);
			counterObstacle++;
		}
	}
	return texture;
}
	
int main()
{
	Terrain map;
	SFMLManager render;
	//Random position 
	srand(time(NULL));
	Vector2f pos;
	//Obstacle
	elem_ptr o;
	
	vector<Texture*> t = loadObstacles();
	for(int i = 0; i < t.size(); i++)
	{
		pos.x = rand()%WIDTH;
		pos.y = rand()%HEIGHT;
		o = make_shared<Obstacle>(t[i],pos);
		cout << o->getPosition().x << " " << o->getPosition().y << endl;
		map.ajout(o);
	}
	
	map.displayInWindow(render);
	
		
	return 0;
}
