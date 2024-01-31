#include "Canon.h"
#include <GL/freeglut.h>

Canon::Canon(){
    //ctor
}

void Canon::drawCanon(){
    glPushMatrix();
        glScalef(2,0.5,1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,0.5,0.0);
        glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.5,0.5,0.0);
        glRotatef(45,1,0,0);
        glScalef(4,1,1);

        glutSolidCube(0.2);
    glPopMatrix();
}

Canon::~Canon()
{
    //dtor
}
