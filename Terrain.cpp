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
	
int main()
{
	
	//S'occuper des obstacles une bonne fois pour toute
	//////////////////////////
	
	//Création d'une map
	Terrain map;
	//Gestion de l'affichage
	SFMLManager render;
	//Random position pour les obstacles 
	srand(time(NULL));
	Vector2f pos;
	//Chargement des images
	vector<Texture*> t = loadObstacles();
	for(int i = 0; i < t.size(); i++)
	{
		//Fixer la position 
		pos.x = rand()%WIDTH;
		pos.y = rand()%HEIGHT;
		//Création de l'objet obstacle 
		Obstacle o(t[i],pos);
		cout << "Position de l'obatcle n° " << i+1 << ":" << o.getPosition().x << " " << o.getPosition().y << endl;
		//Ajout dans la map
		map.ajout(o);
	}
	
	/////////////////
	
	Vector2f p(0,0);
	////Créer un robot
	Robot* rob1 = new Robot(p,1,0,10);
	Texture* te = new Texture;
	te->loadFromFile("Image/Robots/Robot1.jpeg");
	rob1->setIm(te);
	//ajout dans la map
	map.ajout(rob1);
	
	
	map.displayInWindow(render);
	//Gérer le déplacement
	render.eventManager(map);
	

	
		
	return 0;
}
