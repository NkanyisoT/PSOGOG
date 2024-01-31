#ifndef HELPERCOLLISION_H
#define HELPERCOLLISION_H

#include "Sphere.h"
#include "plane.h"
#include "Charecter.h"
#include <vector>

using namespace std;

class helperCollision
{
    public:
        helperCollision();
        static float spherePlaneDist(plane p, Sphere s);
        plane checkCollisionWithPlane(vector<plane> planes, Sphere object);
        plane checkWithDistance(vector<plane> planes, Sphere obj);
        Sphere* checkCollisionWithSphere(vector<Sphere*> spheres, Sphere s);
       // Sphere* CharactersBullets(vector<Charecter*> characters, Bullet bu);

        virtual ~helperCollision();

    protected:

    private:

};

#endif // HELPERCOLLISION_H
