#include "face.h"

face::face(int a, int b, int c, int d, int e)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->e = e;
}

face::face(int a, int b, int c, int d, int e, int f)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->f = f;
  this->e = e;
  //four = false;
}

face::~face()
{
    //dtor
}
