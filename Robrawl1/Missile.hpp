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
        Missile(Vector2f p, string n, float o, int h, int w, int d):
        MovingElt(p,n,o,1,h,w),
        dmg(d){};

        void damage(MovingElt& elt);
        void deplace(Terrain& map);
        bool isColliding(MovingElt& e);

        void displayInWindow(SFMLManager&);
};

#endif