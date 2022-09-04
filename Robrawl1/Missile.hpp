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
        string launcher; 
    
    public:
        Missile(Vector2f p, string n, float o, int h, int w, int d, string l):
        MovingElt(p,n,o,1,h,w,3),
        dmg(d),
        launcher(l){};

        void damage(MovingElt& elt);
        void deplace(Terrain& map);
        bool isColliding(MovingElt& e);
        bool isColliding(Obstacle& obs);

        void displayInWindow(SFMLManager& render);

        void attaque(Terrain&map){};
        void reoriente(int){};
};

#endif