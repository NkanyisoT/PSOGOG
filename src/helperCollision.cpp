#include "helperCollision.h"
#include "point.h"
#include "plane.h"
#include "Sphere.h"
#include "Bullet.h"
#include <vector>
#include <math.h>

using namespace std;
//#include <cstddef>

helperCollision::helperCollision()
{

}

plane helperCollision::checkCollisionWithPlane(vector<plane> planes, Sphere obj)
{
    for(unsigned int i = 0; i < planes.size(); i++)
        if(planes[i].isPointOnPlane(obj.getCenter()))
            return planes[i];
   plane p;
   return p;
}

plane helperCollision::checkWithDistance(vector<plane> planes, Sphere object)
{
    for(unsigned int i = 0; i < planes.size(); i++)
        if(spherePlaneDist(planes[i], object) <= object.getRadius()/4)
            return planes[i];

    plane p;
    return p;
}

float helperCollision::spherePlaneDist(plane p, Sphere s)
{
    float d = p.getD();
    float vecSize = sqrt(pow(p.getNormal().getX(),2) + pow(p.getNormal().getY(),2) +  pow(p.getNormal().getZ(),2));
    myVector v(s.getCenter().x, s.getCenter().y, s.getCenter().z);
    float dot = p.getNormal().dotp(v);
    return (dot - d)/vecSize;
}




helperCollision::~helperCollision()
{
    //dtor
}
