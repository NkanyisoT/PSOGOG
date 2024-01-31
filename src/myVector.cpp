#include "myVector.h"

#include <math.h>

using namespace std;

myVector::myVector() : point()
{
    //ctor
}
myVector::myVector(float x1, float y2, float z2) : point(x1, y2, z2)
{
    x = x1;
    y = y2;
    z = z2;
}

float myVector::dotp(myVector v)
{
    double product = x*v.getX() + y*v.getY() + z*getZ();
    return product;
}

myVector myVector::cross(myVector u)
{
    float x1, y1,z1;
    x1 = y*u.getZ() - z*u.getY();
    y1 = z*u.getX() - x*u.getZ();
    z1 = x*u.getY() - y*u.getX();
    myVector v(x1, y1, z1);
    return v;
}

myVector myVector:: normal()
{
    float x1 = x;
    float y1 = y;
    float z1 = z;

    float radSquare = 1/sqrt(x*x + y*y +z*z);
    x1 *= radSquare;
    y1 *= radSquare;
    z1 *= radSquare;
    myVector v(x1, y1, z1);
    return v;
}

myVector::~myVector()
{
    //dtor
}
