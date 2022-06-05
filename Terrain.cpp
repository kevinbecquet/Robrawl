#include "Terrain.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"

//Ajouter des élements mobiles ou obstacles dans le terrain (map) - surcharge
void Terrain::ajout(MovingElt* e)
{
	elem.push_back(e);
}


void Terrain::ajout(Obstacle o)
{
	obs.push_back(o);
}

//Premier affichage dans la map
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
	Image* i;
	Texture* t;
	int counterObstacle = 1;
	
	
	while(counterObstacle != 0)
	{
		i = new Image;
		t = new Texture;
		cout << "counterObstacle = " << counterObstacle << endl;
		if(!i->loadFromFile("Image/Obstacles/Obstacles"+to_string(counterObstacle)+".jpeg"))
		{
			cout << "Failed to load image" << endl;
			counterObstacle = 0;
		}
		else
		{
			i->createMaskFromColor(Color::White); //Suppression du fond blanc
			t->loadFromImage(*i);
			texture.push_back(t);
			counterObstacle++;
		}
	}
	return texture;
}

//Faire en sorte que les différents obstacles ne se trouvent pas à la même position
bool check_pos(vector<Vector2f> position, Vector2f pos)
{
	for(Vector2f p : position)
	{
		if(p == pos)
			return false;
	}
	return true;
}

vector<Robot*> loadRobot(Robot* rob, vector<Vector2f> start_pt)
{
//Les positions initiales
	
	Texture* texture;
	Image* im;
	vector<Robot*> robot;
	
	Color color(220,220,220); //grey
	////Créer robot1
	for(int i = 0; i < 2 ; i++)
	{
		/////////////////
		im = new Image;
		texture = new Texture;
		
		rob = new Robot(start_pt[i],"Robot"+to_string(i+1),0,10);
		cout << start_pt[i].x << " " << start_pt[i].y << endl;
		im->loadFromFile("Image/Robots/Robot"+to_string(i+1)+".jpeg");
		im->createMaskFromColor(Color::White);
		im->createMaskFromColor(color);
		texture->loadFromImage(*im);
		rob->setIm(texture);
		rob->setImPos(start_pt[i]);
		

		robot.push_back(rob);
	}
	
	return robot;
}	
