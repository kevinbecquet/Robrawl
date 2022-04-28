#ifndef TERRAIN
#define TERRAIN

#include "Joueur.hpp"
#include "Obstacle.hpp"


class Terrain
{
	private :
		vector<Obstacle> Obs;
		vector <Joueur> J;
		RenderWindow fenetre;
		
	
	public :
		Terrain(int l, int L, String title)
		{
			fenetre.create(VideoMode(l,L),title);
		}
		//fermetrure de la fenêtre -- correspond à la fin du jeu
		//demander à sauvegarder la partie si en cours ? 
		void endOfGame(Event e)
		{
			while(fenetre.pollEvent(e))
			{
				if(e.type == Event::Closed)
					fenetre.close();
			}
		}
		//Ce qu'un jeu en cours 
		bool jeuEnCours(){ return fenetre.isOpen();}
		//RenderWindow getFenetre(){ return fenetre;}
		//void pause(Keyboard::key p);
		void ajout(Obstacle o);
		void ajout(Joueur j);
		void affiche();
		
		

};

#endif 
