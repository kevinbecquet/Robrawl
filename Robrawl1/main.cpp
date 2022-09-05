#include "Terrain.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"



int main(){

	//Création d'une map
	Terrain* map = new Terrain();
	
	//Chargement des elements de la map
	map->loadObstacles();
	map->loadRobot();
	
	SFMLManager render;
	while(render.getWindow()->isOpen()&&!map->victoryCheck()){	

		render.eventManager(*map);
		
		map->action();
		
		render.displayWindow(*map);
	}
	


	return 0;
}
