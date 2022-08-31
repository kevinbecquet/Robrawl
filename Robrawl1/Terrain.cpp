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
	render.getWindow()->clear();

	for(size_t i =0; i < obs.size(); i++)
		obs[i].displayInWindow(render);

	for(size_t i =0; i < elem.size(); i++)
		elem[i]->displayInWindow(render);
	render.getWindow()->display();
}


//Chargement des textures - des images obstacles
vector<Texture*> loadObstacles(int n)
{
	vector<Texture*> texture;
	Image* im;
	Texture* t;



	for(int i = 0 ; i< n; ++i)
	{
		im = new Image;
		t = new Texture;
	
		if(!im->loadFromFile("Image/Obstacles/Box.png"))
		{
			cout << "Failed to load image" << endl;
		}
		else
		{
			t->loadFromImage(*im);
			texture.push_back(t);
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

		rob = new Robot(start_pt[i],"robot"+to_string(i+1),0,10,52,52);
		cout << start_pt[i].x << " " << start_pt[i].y << endl;
		im->loadFromFile("Image/Robots/robot"+to_string(i+1)+".png");
		
		texture->loadFromImage(*im);
		rob->setIm(texture);
		rob->setImPos(start_pt[i]);


		robot.push_back(rob);
	}

	return robot;
}
