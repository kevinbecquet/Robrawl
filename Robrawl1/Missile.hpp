#ifndef MISSILE_H
#define MISSILE_H

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "MovingElt.hpp"
#include "Terrain.hpp"


class Missile : public MovingElt
{

    private:
        int dmg;
    
    public:
        
        void deplace(Terrain& map);
        bool isColliding(MovingElt& e);

        void displayInWindow(SFMLManager&);
};

#endif