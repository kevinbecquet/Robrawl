#include "Terrain.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"

vector<Texture*> loadObstacles();
bool check_pos(vector<Vector2f> position, Vector2f pos);
	
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
	vector<Vector2f> position;
	//Chargement des images
	vector<Texture*> t = loadObstacles();
	for(size_t i = 0; i < t.size(); i++)
	{
		//Vérifier que les obstacles ne sont pas en même position
		do
		{
			//Fixer la position 
			pos.x = rand()%WIDTH;
			pos.y = rand()%HEIGHT;
			
		}while(!check_pos(position,pos));
		
		//L'insérer si il n'y est pas
		position.push_back(pos);
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
