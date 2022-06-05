#include "Terrain.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"

//Ajouter des élements dans le terrain (map) - surcharge
void Terrain::ajout(MovingElt* e)
{
	elem.push_back(e);
}

void Terrain::ajout(Obstacle o)
{
	obs.push_back(o);
}

void Terrain::displayInWindow(SFMLManager& render)
{
	for(size_t i =0; i < elem.size(); i++)
		elem[i]->displayInWindow(render);
		
	for(size_t i =0; i < obs.size(); i++)
		obs[i].displayInWindow(render);
	
}

//Chargement des textures - des images obstacles
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

bool check_pos(vector<Vector2f> position, Vector2f pos)
{
	for(Vector2f p : position)
	{
		if(p == pos)
			return false;
	}
	return true;
}
