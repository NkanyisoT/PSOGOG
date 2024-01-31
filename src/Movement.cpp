//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>

using namespace std;

#include "Movement.h"
/*
create an object in your main class , in the method you

*/

    Movement :: Movement() {     // Initialize Everything
     init();
    }

void Movement::init(){

      eyeX = 45 ;
      eyeY = 0;
      eyeZ = -30 ;
      scaleFactor = 0.5 ;
      rotateFactor = 0.0 ;
      lookAtX = 45 ;
      lookAtY =0;
      lookAtZ = -25 ;
      speed=1;


}

void Movement :: camera () {     // Camera Work

       gluLookAt( eyeX, eyeY, eyeZ,
                  lookAtX, lookAtY, lookAtZ,
                  0,1,0
                  );
}

void Movement:: mousePressed(int button, int state, int x, int y)
{
    //only start motion if left button is clicked
    if(button == GLUT_LEFT_BUTTON)
    {
        // when the button is released
        if(state == GLUT_UP)
        {
            xOrigin = -1;
           //angle -= deltaAngle;
        }

        else { // button is down
            xOrigin = x;
        }
    }
}

void Movement::mouseMove(int x, int y)
{
    if(xOrigin >= 0)
    {
        deltaAngle = (x - xOrigin) * 0.0001f;

        ourAngle += deltaAngle;

        lookAtX = radius() * sin(ourAngle);
        lookAtZ = radius() *cos(ourAngle);


    }
   // glutPostRedisplay();
}
// Returns the distance from the lookAt point to the position of the camera
float Movement::radius()
{
    float radius = (eyeX - lookAtX)*(eyeX - lookAtX) +
             (eyeY - lookAtY)*(eyeY - lookAtY) + (eyeZ - lookAtZ)*(eyeZ - lookAtZ);

    if(radius >= 0)
        return sqrt(radius);

    else return
       sqrt(-radius);
}

void Movement::processSpecialKey( int key, int x, int y) {         // Key Events

     switch(key)
    {
        case GLUT_KEY_LEFT: // angle++;
                   eyeX += speed;

                   lookAtX += speed;
                   break;
        case GLUT_KEY_RIGHT: eyeX -= speed;
                             lookAtX -= speed;
                                break;
        case GLUT_KEY_DOWN:  eyeX -= speed * sin(ourAngle);
                             eyeZ -= speed * cos(ourAngle);
                             lookAtZ -= speed;
                                break;
        case GLUT_KEY_UP: eyeZ += speed * cos(ourAngle);
                          eyeX += speed * sin(ourAngle);
                          lookAtZ += speed;
                            break;
    }
cout << "lookAtX : " << lookAtX << " lookAtZ : " << lookAtZ <<" EYEX  "<< eyeX<< " EYEZ"<< eyeZ<<endl;
    glutPostRedisplay();
}
