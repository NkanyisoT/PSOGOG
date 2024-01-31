#include "mouse.h"

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
*/
mouse::mouse() : cam(0.5, 0, 0, -5)
{
 init();
}

void mouse::init(){

        this->angle = 0.0f;

// actual vector representing the camera's direction
    this->lx=0.0f;
    this->lz=1.0f;

// XZ position of the camera
    this->x=45.0f;
    this->z=-28.0f;

// the key states. These variables will be zero
//when no key is being presses
    this->deltaAngle = 90.0f;
    this->deltaMove = 0;
    this->xOrigin = -1;
    this->speed=2.0;
    cam.changeCoodinates(x, y, z);
}

Sphere mouse :: returnSphere()
{
    return cam;
}

void mouse::camera(){

    gluLookAt(	x, y, z,
			x+lx, -1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);
}


float mouse::getDeltaMove()
{
    return deltaMove;
}

void mouse::computePos(float deltaMove, vector<plane> planes) {

    if(!(help.checkCollisionWithPlane(planes, cam).getState())){
    	x += deltaMove * lx * 0.1f;
	    z += deltaMove * lz * 0.1f;
	    cam.changeCoodinates(x, y, z);

        if(x <= 50 && x >=20)
            STAGE = 1;
        if(x <= 15 && x >=-15)
            STAGE = 2;
        if(x<=-20 && x >= -50)
            STAGE = 3;
    }

    else {
        float var = deltaMove;
        //if(deltaMove == -speed)
         // var = -deltaMove;

        x += (-(var) * lx * 0.5f);
        z += (-(var) * lz * 0.5f);
        cam.changeCoodinates(x, y, z);

        //return;
    }
    glutPostRedisplay();
}

void mouse::mover(vector<plane> planes)
{
    computePos(deltaMove, planes);
}

void mouse::processNormalKeys(unsigned char key, int xx, int yy) {

        if (key == 27)
              exit(0);
}

void mouse::pressKey(int key, int xx, int yy) {

       switch (key) {
             case GLUT_KEY_UP : deltaMove = speed; break;
            // case GLUT_KEY_DOWN : deltaMove = -speed; break;
       }
}

void mouse::releaseKey(int key, int x, int y) {

        switch (key) {
             case GLUT_KEY_UP : deltaMove = 0;break;
             //case GLUT_KEY_DOWN : deltaMove = 0;break;
        }
}

void mouse::mouseMove(int x, int y) {

         // this will only be true when the left button is down
         if (xOrigin >= 0)
        {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle +15);
	}

	glutPostRedisplay();
}

void mouse::mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

float mouse::getAngle()
{
    return angle;
}

point mouse::getLookAt()
{
    point p(x + lx, 0.0f, z + lz);
    return p;
}

point mouse::getPos()
{
    point p(x, y, z);
    return p;
}

float mouse::getX()
{
    return x;
}

float mouse::getLx()
{
    return lx;
}

float mouse::getLz()
{
    return lz;
}

float mouse::getZ()
{
    return z;
}

float mouse :: getY(){
    return y;
}
float mouse :: getLookAtX(){
    return  lx;
}
float mouse :: getLookAtZ(){
    return lz;
}
float mouse :: getLookAtY(){
    return  ly;
}

mouse::~mouse()
{
    //dtor
}
