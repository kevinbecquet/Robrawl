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
	//display element par element 
	for(size_t i = 0; i < elem.size(); i++)
		elem[i]->displayInWindow(render);
	
	render.eventManager();
}

//Chargement des textures - des images
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
	//Création d'une map
	Terrain map;
	//Gestion de l'affichage
	SFMLManager render;
	//Random position pour les obstacles 
	srand(time(NULL));
	Vector2f pos;
	//Obstacle
	elem_ptr o;
	//Chargement des images
	vector<Texture*> t = loadObstacles();
	for(int i = 0; i < t.size(); i++)
	{
		//Fixer la position 
		pos.x = rand()%WIDTH;
		pos.y = rand()%HEIGHT;
		//Création de l'objet obstacle 
		o = make_shared<Obstacle>(t[i],pos);
		cout << o->getPosition().x << " " << o->getPosition().y << endl;
		//Ajout dans la map
		map.ajout(o);
	}
	
	//Affichage dans la map
	map.displayInWindow(render);
	
		
	return 0;
}
