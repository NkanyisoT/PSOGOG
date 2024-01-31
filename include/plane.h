#ifndef PLANE_H
#define PLANE_H

#include <vector>
using namespace std;

#include "point.h"
#include "myVector.h"
#include "Collidable.h"

class plane: public Collidable
{
    public:
        plane();
        plane(point leftUp, point leftDown, point rightUp, point rightDown);
        myVector getNormal();
        float getD();
        bool getState();
        float getArea();
        bool isPointOnPlane(point p);
       // bool getState();
        bool absoluteDiff(int a, int b);

        virtual ~plane();
    protected:
    private:
    bool horizontal(point p);

    float d;
    point leftUp;
    point leftDown;
    point rightUp;
    point rightDown;
    myVector normal;
    myVector vecOnPlane;
    vector<point> pointsOfQuad;
};

#endif // PLANE_H
