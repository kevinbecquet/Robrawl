	#include "Terrain.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"



int main()
{



	//Création d'une map
	Terrain map;
	//Gestion de l'affichage
	SFMLManager render;

	//S'occuper des obstacles une bonne fois pour toute
	//////////////////////////
	//Random position pour les obstacles
	srand(time(NULL));
	Vector2f pos;
	
	//Chargement des images
	vector<Texture*> t = loadObstacles(1);
	for(size_t i = 0; i < t.size(); i++)
	{
		pos.x = WIDTH/2;
		pos.y = 250;
		//Création de l'objet obstacle
		Obstacle o(t[i],pos,36,24);
		cout << "Position de l'obstacle n° " << i+1 << ":" << o.getPosition().x << " " << o.getPosition().y << endl;
		//Ajout dans la map
		map.ajout(o);
	}

	//S'occuper des deux robots
	vector<Vector2f> start_pt;
	Vector2f start1(100,50);
	Vector2f start2(200,200);
	start_pt.push_back(start1);
	start_pt.push_back(start2);

	vector<Robot*> rob;
	Robot* robot;
	rob = loadRobot(robot, start_pt);
	for(Robot* r : rob)
		map.ajout(r);

	cout << map.getElem().size() << endl;

	while(render.getWindow()->isOpen())
	{	
		render.eventManager(map);

		map.displayInWindow(render);
	
	}



	return 0;
}
