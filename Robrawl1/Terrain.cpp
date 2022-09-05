#include "Terrain.hpp"

//Ajouter des élements mobiles ou obstacles dans le terrain (map) - surcharge
void Terrain::ajout(MovingElt* e)
{
	elem.push_back(e);
	
}

// Retourne vrai si un des deux robots est vaincu
bool Terrain::victoryCheck(){
	//si l'un des robots est vaincu, il quitte la liste des MovingElt
	// cette liste est donc soit de taille 1 s'il ne reste que le robot gagnant (pas de missile sur le terrain)
	//soit le 2ème element de cette liste est un missile 
	if(elem.size() == 1 || elem[1]->getNom() != "robot2"){
		cout<<"Vainqueur: "+ elem[0]->getNom()<<endl;
		return true;
	}
	return false;
}

//Ajoute un obstacle au vecteur d'obstacle
void Terrain::ajout(Obstacle o)
{
	obs.push_back(o);
}

// Incremente le compteur de missile et retourne sa valeur
int Terrain:: addMissile(){
	countMissile++;
	return countMissile;
}

// Supprime tous les MovingElt n'ayant plus de vie 
void Terrain:: supprElem(){

	for(int i = elem.size()-1; i>=0 ;--i){
		if(elem[i]->getVie() <= 0){
			elem.erase(elem.begin()+i);

		} 
	}	
}
// Execute une itération d'action : déplace les elements et supprime ceux qui sont "mort"
void Terrain::action(){
	for(MovingElt* elt : elem){

		elt->deplace(*this);
		elt->setImPos();	
	}
	supprElem();
}

// Charge une image dont le chemin d'accès est indiqué dans une texture
Texture* loadImg(string path){
	Image im;
	Texture* t = new Texture;
	im.loadFromFile(path);
	t->loadFromImage(im);
	return t;
}


//Chargement des obstacles dans la map
void Terrain::loadObstacles(){
	
	//Position des obstacles
	vector<Vector2f> pos;
	Vector2f pos1(WIDTH/2,250);
	pos.push_back(pos1);
	pos1 = Vector2f(120,300);
	pos.push_back(pos1);
	pos1 = Vector2f(600,100);
	pos.push_back(pos1);		
	pos1 = Vector2f(240,120);
	pos.push_back(pos1);		
	
	for(int i = 0 ; i< pos.size(); ++i)
	{
		Texture* t = loadImg("Image/asteroide.jpeg");

		//Création de l'objet obstacle
		Obstacle o(t,pos[i],65,24);

		//Ajout dans la map
		ajout(o);
			
	}
	
}

// Chargement des Robot dans la map
void Terrain::loadRobot(){

//Positions initiales des Robots

	vector<Vector2f> start_pt;
	Vector2f start1(100,50);
	Vector2f start2(200,200);
	start_pt.push_back(start1);
	start_pt.push_back(start2);

	Texture* texture;
	Robot* rob;

	for(int i = 0; i < 2 ; i++)
	{	
		// creation d'un Robot
		rob = new Robot(start_pt[i],"robot"+to_string(i+1),0,5,52,52);
		
		texture = loadImg("Image/robot"+to_string(i+1)+".png");
		rob->setIm(texture);
		rob->setImPos();

		//Ajout dans la map
		ajout(rob);
	}
}

