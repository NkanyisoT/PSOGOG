#ifndef COLLISION_H
#define COLLISION_H

#include "Sphere.h"
#include "plane.h"
#include "point.h"

class collision
{
    public:
        collision();
        bool collideSpheres(Sphere sp1, Sphere sp2);
        bool collideSpherePlane(Sphere sp, plane pln);
        virtual ~collision();
    protected:
    private:
            bool flag = 0;
};

#endif // COLLISION_H
