#ifndef MISSILE
#define MISSILE

#include "SFMLManager.hpp"
#include "Robot.hpp"

class Missile : public MovingElt
{
	
	public: 
	
		Missile();
		void displayInWindow(SFMLManager& render);
		void deplace();
		bool inWindow();
		//Initialise la position
		void InitImPos(Robot* r);
};


#endif
