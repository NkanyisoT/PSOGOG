#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <cmath>
#include <iostream>
#include "gameworld.h"
#include "charecter.h"

using namespace std;

GameWorld::GameWorld()
{

}

void GameWorld::drawWorld()
{
    glColor3ub((byte) 64, (byte) 64, (byte) 0); // green
    glBegin(GL_QUADS);
    glVertex3f(-50.0f, -0.5f, -30.0f);
    glVertex3f(-50.0f, -0.5f,  30.0f);
    glVertex3f( 50.0f, -0.5f,  30.0f);
    glVertex3f( 50.0f, -0.5f, -30.0f);
    glEnd();

    glColor3ub((byte) 30, (byte) 30, (byte) 0);
    glutSolidCube(1);

    //front edge
   glPushMatrix();
   glTranslatef(44.5,0.0,3.0);
   glScalef(1,1,44);
   glutSolidCube(1);
   glPopMatrix();

    //back edge
   glPushMatrix();
   glTranslatef(-44.5,0.0,-3.0);
   glScalef(1,1,44);
   glutSolidCube(1);
   glPopMatrix();

   //left edge
   glPushMatrix();
   glTranslatef(0.0,0.0,24.5);
   glScalef(90,1,1);
   glutSolidCube(1);
   glPopMatrix();

   //right edge
   glPushMatrix();
   glTranslatef(0.0,0.0,-24.5);
   glScalef(90,1,1);
   glutSolidCube(1);
   glPopMatrix();

   // inner wall
   /*
   *
   *
   *
   */

   glPushMatrix();
   glTranslatef(30,0.0,-5.0);
   glScalef(1,1,40);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(10,0.0,5.0);
   glScalef(1,1,40);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-10,0.0,-5.0);
   glScalef(1,1,40);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-30,0.0,5.0);
   glScalef(1,1,40);
   glutSolidCube(1);
   glPopMatrix();


}


void GameWorld::render()
{
    drawWorld();
}
GameWorld::~GameWorld()
{
    //dtor
}
