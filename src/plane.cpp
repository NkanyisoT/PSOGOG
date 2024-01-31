#include <vector>
#include <iostream>
#include <cmath>
//#include <cstddef>

using namespace std;

#include "mouse.h"
#include "plane.h"
#include "Sphere.h"
#include "myVector.h"
#include "helperCollision.h"

plane::plane()
{
    //cout << "Now why would you create a plane like this? \ncome on! You don't have a normal vector! " << endl;
    exist = false;
}

plane::plane(point leftUp2, point leftDown2, point rightUp2, point rightDown2)
{
    leftDown = leftDown2;
    leftUp = leftUp2;
    rightDown = rightDown2;
    rightUp = rightUp2;

    pointsOfQuad.push_back(leftDown);
    pointsOfQuad.push_back(leftUp);
    pointsOfQuad.push_back(rightDown);
    pointsOfQuad.push_back(rightUp);

    normal = getNormal();

     //vector on the plane
    myVector v1(leftUp.x - leftDown.x, leftUp.y - leftDown.y, leftUp.z - leftDown.z);
    myVector v2(v1.getX() - rightUp.getX(), v1.getY() - rightUp.getY(), v1.getZ() - rightUp.getZ());
    vecOnPlane = v1;
    //constant for the plane equation: vector(dot)normal = d
    myVector thepoint(leftUp.getX(), leftUp.getY(), leftUp.getZ());
    d = thepoint.dotp(normal);

    exist = true;
}

myVector plane::getNormal()
{
    myVector v1(leftUp.x - leftDown.x, leftUp.y - leftDown.y, leftUp.z - leftDown.z);
    myVector v2(rightUp.x - leftUp.x, rightUp.y - leftUp.y, rightUp.z - leftUp.z);

    return v1.cross(v2);//.normal();
}

bool plane::absoluteDiff(int d, int constant)
{
   int diff = d - constant;
   if(diff < 0)
        diff = -diff;
   return diff <= 100;
}

bool plane::isPointOnPlane(point p)
{
   // myVector vec(vecOnPlane.getX() - p.getX(), vecOnPlane.getY() - p.getY(), vecOnPlane.getZ() - p.getZ());
    myVector thispoint(p.getX(), p.getY(), p.getZ());
    float constant = thispoint.dotp(normal);
    //cout << (int)d << " " << (int)constant << endl;
    mouse speedster;
    Sphere sp(0.2, p.x, p.y, p.z);
    helperCollision help;

    if(horizontal(p))
        return true;

    if(abs(help.spherePlaneDist((*this), sp)) <= speedster.speed/2)
    {

     for(unsigned int i = 0; i < pointsOfQuad.size() - 1; i++)
     {
        if(leftUp.x == rightUp.x && leftUp.x == rightDown.x)
        {
            if(pointsOfQuad[i].y == pointsOfQuad[i+1].y)
            {
                if(pointsOfQuad[i].z > pointsOfQuad[i+1].z)
                {
                    cout << "1st " << endl;
                    return ((p.z >= pointsOfQuad[i+1].z ) && (p.z <= pointsOfQuad[i].z));
                }
                else {
                        cout << "2nd " << endl;
                    return ((p.z >= pointsOfQuad[i].z) && (p.z <= pointsOfQuad[i+1].z));
                }
            }
        }

        else
        {
             if(pointsOfQuad[i].y == pointsOfQuad[i+1].y);
             {
                  if(pointsOfQuad[i].x > pointsOfQuad[i+1].x)
                {
                    cout << "3rd " << endl;
                    return ((p.x >= pointsOfQuad[i+1].x ) && (p.x <= pointsOfQuad[i].x));
                }
                else {
                        cout << "4th " << endl;
                    return ((p.x >= pointsOfQuad[i].x) && (p.x <= pointsOfQuad[i+1].x));
                }
            }
        }
    }
  }
  return false;
}

float plane::getD()
{
    return d;
}
bool plane::getState()
{
    return exist;
}
float plane:: getArea()
{
    float area = (leftDown.getX() - leftUp.getX()) * (rightDown.getX() - rightUp.getX());

    if(area >= 0)
       return area;

    else
       return -area;
}
//The planes of the houses are transformed. this method gets the new points
bool plane::horizontal(point p)
{
    if(p.z >= 29.0f || p.z <= -29.0f)
        return true;
    if(p.z == -19)
        if((p.x >= -6 && p.x <= -2) || (p.x >= 0 && p.x <= 4) || (p.x >= -29 && p.x <= -25) ||
                 (p.x >= -23 && p.x <= -19) || (p.x >= -51 && p.x <= -47) || (p.x >= -45 && p.x <= -41))
                 return true;
    if(p.z == 19)
        if((p.x >= 32 && p.x <= 36) || (p.x >= 26 && p.x <= 30))
          return true;
    if(p.z == -29)
        if((p.x >= -29 && p.x <= -19) || (p.x >= -51 && p.x <= -41))
           return true;
    if(p.z == -28 && p.x >= -6 && p.x <= 4)
        return true;
    if(p.z == 2 && p.x >= -55 && p.x <= -45)
        return true;
    if(p.z == 12 && p.x >= -55 && p.x <= -45)
        return true;
    if(p.z == -6 && p.x >= -30 && p.x <= -20)
        return true;
    if(p.z == -12 && p.x >= -30 && p.x <= -20)
        return true;

    return false;
}

plane::~plane()
{

}
