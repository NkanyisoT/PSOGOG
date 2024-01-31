#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"
#include "Collidable.h"
#include <vector>
#include <string>

using namespace std;

class Sphere: public Collidable
{
    public:
        Sphere();
        Sphere(float r, float x, float y, float z);
        Sphere(float x, float y, float z);
        Sphere(float r);
        bool getState();
        void changeCoodinates(float x, float y, float z);
        void moveSphere(int keyPressed);
        bool isCollidingSpheres(Sphere s);
        void drawSphere();
        virtual bool get_isDead(){};
        virtual void set_isDead(bool t){};
        virtual void drawCharecter(string who){};
        virtual void setCharCord(float* x , float* y , float* z){};
        Sphere* isCollidingSpheresArray(vector<Sphere> sphereVector);
        point getCenter();
        float getRadius();
        void setRadius(float r);
        float radius;
     private:
        float xCenter;
        float yCenter;
        float zCenter;


    // friend void changeNgaphakathi(Sphere &sphere , int keyPressed);
};

#endif // SPHERE_H
