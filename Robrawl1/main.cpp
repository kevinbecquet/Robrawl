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
	vector<Vector2f> position;
	//Chargement des images
	vector<Texture*> t = loadObstacles(10);
	for(size_t i = 0; i < t.size(); i++)
	{
		//Vérifier que les obstacles ne sont pas en même position
		do
		{
			//Fixer la position
			pos.x = rand()%(WIDTH-98);
			pos.y = rand()%(HEIGHT-146);

		}while(!check_pos(position,pos));

		//L'insérer si il n'y est pas
		position.push_back(pos);
		//Création de l'objet obstacle
		Obstacle o(t[i],pos);
		cout << "Position de l'obstacle n° " << i+1 << ":" << o.getPosition().x << " " << o.getPosition().y << endl;
		//Ajout dans la map
		map.ajout(o);
	}

	//S'occuper des deux robots
	vector<Vector2f> start_pt;
	Vector2f start1(1,50);
	Vector2f start2(200,200);
	start_pt.push_back(start1);
	start_pt.push_back(start2);

	vector<Robot*> rob;
	Robot* robot;
	rob = loadRobot(robot, start_pt);
	for(Robot* r : rob)
		map.ajout(r);

	cout << map.getElem().size() << endl;


	map.displayInWindow(render);
	//Gérer le déplacement


	render.eventManager(map);




	return 0;
}
