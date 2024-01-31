#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;

//#include <cstddef>
#include "Sphere.h"
#include "point.h"

Sphere::Sphere(float r, float x, float y, float z)
{
    radius = r;
    xCenter = x;
    yCenter = y;
    zCenter = z;
    exist = true;
}
Sphere::Sphere(float x, float y, float z)
{
    radius = 0.05;
    xCenter = x;
    yCenter = y;
    zCenter = z;
    exist = true;
}
Sphere::Sphere()
{
  exist = false;
}

Sphere::Sphere(float r)
{
    radius = r;
    xCenter = 0.0;
    yCenter = 0.0;
    zCenter = 0.0;
    exist = true;
}
point Sphere::getCenter()
{
    point p(xCenter, yCenter, zCenter);
    return p;
}
void Sphere :: changeCoodinates(float x, float y, float z)
{
    (*this).xCenter = x;
    (*this).yCenter = y;
    (*this).zCenter = z;
}
void Sphere :: setRadius(float r)
{
    (*this).radius = r;
}
void Sphere ::  drawSphere()
{

    glPushMatrix();
    glTranslatef(xCenter,yCenter,zCenter);

    glColor3f(1.0,1.0,1.0);
    glutSolidSphere(radius,20,20);
    glPopMatrix();

        glutPostRedisplay();
}

float Sphere::getRadius()
{
    return radius;
}

bool Sphere :: isCollidingSpheres(Sphere s)
{

    return ((xCenter-s.xCenter)*(xCenter-s.xCenter)+(yCenter-s.yCenter)*(yCenter-s.yCenter)
            +(zCenter-s.zCenter)*(zCenter-s.zCenter)) -(radius*radius+s.radius*s.radius) <= 0;
}

bool Sphere::getState()
{
    return exist;
}

Sphere* Sphere :: isCollidingSpheresArray(vector<Sphere> sphereVector){
    for(unsigned int i =0; i<sphereVector.size(); i++) // Travesing the vector(List of sphere)
        if((*this).isCollidingSpheres(sphereVector[i])) // Making sure its not checking itself & checking if collide with onother
            return &sphereVector[i];
    Sphere* p;
    return p;
}

void Sphere :: moveSphere(int keyPressed)
{
    switch( keyPressed ) {
case GLUT_KEY_LEFT :
    xCenter-=0.5;
        break ;

case GLUT_KEY_RIGHT :
    xCenter+=0.5;
        break ;

case GLUT_KEY_UP :
    zCenter+=0.5;
        break ;

case GLUT_KEY_DOWN:
    yCenter-=0.5;
        break ;

    }
    glutPostRedisplay();
}
