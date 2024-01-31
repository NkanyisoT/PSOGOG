//#include "point.h"
#include "myVector.h"

  using namespace std;
point::point()
{
   x = y = z = 12.0;
}

point::point(float x, float y, float z)
{
   this->x = x;
   this->y = y;
   this->z = z;
}

   point point::getPoint() {

      return (*this);
  }

  void point::setX(float x) {
    this->x = x;
  }
  void point::setY(float y) {
    this->y = y;
  }

  void point::setZ(float z) {
    this->z = z;
  }

  float point::getX() {
   return x;
  }

  float point::getY() {
    return y;
  }
  float point::getZ() {
    return z;
  }

point::~point()
{
    //dtor
}
