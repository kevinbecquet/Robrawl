#ifndef MOVING_MovingElt
#define MOVING_MovingElt

#include "SFMLManager.hpp"
#include <memory>
#define ScaleFactor 0.3

using namespace std;
using namespace sf;

//Un objet mobile est un robot ou un missile
//Ils ont tous les deux une position - un nom - orientation - position et image
class MovingElt{

	protected :
		Sprite im;
		Vector2f position;
		string nom;
		float orientation;
		int vie;
		int height;
		int width;
		int vitesse;
		
	public :
		MovingElt(){}
		
		MovingElt(Vector2f p, string n, float o,int v,int h, int w,int vit): 
					position(p), 
					nom(n), 
					orientation(o),
					vie(v),
					height(h),
					width(w),
					vitesse(vit){};

		virtual ~MovingElt();
		
		int getVie();

		Vector2f getPosition();
		float getVitesse();
		float getOrientation();
		
		int getHeight();
		int getWidth();
		
		Sprite getIm();

		void setVie(int hp);
		

		virtual void deplace(Terrain& map) = 0;
		virtual void reoriente(int) = 0;
		virtual void attaque(Terrain& map) = 0;
		
		void setIm(Texture* t);

		void setImPos();
		void setImPos(Vector2f init_pos);
		
		virtual void displayInWindow(SFMLManager&) =0;
		string getNom();
};

#endif
