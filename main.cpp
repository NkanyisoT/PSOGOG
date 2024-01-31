#include <windows.h>                            // for MS Windows
#include <GL/glut.h>                            // GLUT, include glu.h and gl.h
#include <cmath>
#include <iostream>
#include "world.h"
#include "Light.h"
#include "Charecter.h"
#include "mouse.h"
#include <thread>
#include "ObjLoader.h"
#include "animation.h"
#include <mmsystem.h>
#include "Canon.h"
#include "item.h"
#include "collision.h"
#include "helperCollision.h"
#include "Bullet.h"
#include "AnimeConrolla.h"
#include "Charecter.h"
#include "score.h"

using namespace std;

#include <string>

World land;                                     //WorldGame land;
Light light;                                    //Light
mouse mover;
Score score;                                  //Movement mover;

vector<Item> items;
vector<plane> planes;
vector<Canon> canonVector;

vector<Sphere*> spheres;
vector<Bullet*> bulletVector;
vector<animation*> animationVector;
vector<Charecter*> charecterVector;
Bullet* bullet = new Bullet();

ObjLoader key("key.obj");

AnimeConrolla animeControlla;


ObjLoader obj("Man.obj");
Charecter charecter = Charecter(obj);

void initGL(){
    glClearColor(1, 1, 1, 1);                   // Black
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);                    // turns on hidden surface removal so that objects behind other objects do not get displayed

    light.initLight(GL_LIGHT0);
    light.setLight( GL_LIGHT0 , GL_POSITION , 1.0 , 1.0 , 0.0 , 0.0 );
    light.setLightColor(GL_LIGHT0 , GL_DIFFUSE , 0.60 , 0.63 , 0.28 );

    light.initLight(GL_LIGHT1);
    light.setLight( GL_LIGHT1 , GL_POSITION , -1.0 , 0.0 , 0.0 , 0.0 );
    light.setLightColor(GL_LIGHT1 , GL_DIFFUSE , 0.60 , 0.63 , 0.28 );

    light.initLight(GL_LIGHT2);
    light.setLight( GL_LIGHT2 , GL_POSITION , 0.0 , 0.0 , 1.0 , 0.0 );
    light.setLightColor(GL_LIGHT2 , GL_DIFFUSE , 0.0 , 0.0 , 0.0 );

    light.initLight(GL_LIGHT2);
    light.setLight( GL_LIGHT2 , GL_POSITION , 0.0 , 1.0 , 0.0 , 1.0 );
    light.setLightColor(GL_LIGHT2 , GL_DIFFUSE , 0.59 , 0.59 , 0.59 );

    items.push_back(Item(38,-1,20));            //stage one
    items.push_back(Item(1,-1,20));             //stage two
    items.push_back(Item(-40.5,-1,2.5));        //stage three

   for(int i=0; i<20; i++){
        charecterVector.push_back(new Charecter(obj,1));
   }

    animeControlla.initAnime(&animationVector);
}

void render(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(score.gameOver)
       mover.init();
    mover.camera();
                                // Set the camera

    land.render();
                                    //world
    planes = land.getPlanes();

    mover.mover(planes);

    animeControlla.drawAnime(animationVector,mover,charecterVector);

    //drawing items
    for(unsigned int i=0;i<items.size();i++){
        items[i].drawItem();
    }


    for(unsigned int i=0;i<items.size();i++){
        if(items[i].getState()){
            items.erase(items.begin() + i);
            break;
        }
    }


    //**************************///////
    for(Charecter* elements : charecterVector)
        if(elements->isCollidingSpheres(mover.returnSphere())){
            if(!elements->get_isDead())
                score.gameOver = true;
        }


    /******* Shooting Command **************/

    point from(mover.getX(),mover.getY(),mover.getZ());
    point to(mover.getX() + mover.getLookAtX(), mover.getY() + mover.getLookAtY() ,mover.getZ() + mover.getLookAtZ());
    point dir(to.x-from.x, to.y, to.z-from.z);

    if(!(bullet->get_isDead())){
        bulletVector.push_back(new Bullet(to,dir));
        bullet->set_isDead(true);
    }

    for(Bullet* element : bulletVector){
        element->set_isDead(false);

        if(element->checkCollisionWithPlane(planes))
            element->set_isDead(true);

        if(element->checkCollisionWithCharecters(&charecterVector)){
             element->set_isDead(true);
             score.addEnemyKills();
             score.addScorePoints(13);
        }

         element->drawBullet();
    }

    for(unsigned int i=0;i<bulletVector.size();i++){
        if(bulletVector[i]->get_isDead()){
            bulletVector.erase(bulletVector.begin()+i);
            i--;
        }
    }

    glutSwapBuffers();
}

void update(){

}

void processSpecialKey(int key, int x, int y) {

}

void processNormalKeys(unsigned char key, int xx, int yy){
    //mover.processNormalKeys(key,x,y);
   if(key == 'r')
        score.gameOver = false;
  if(!score.gameOver) {
    for(unsigned int i=0;i<items.size();i++){
        items[i].processNormalKeys(key,xx,yy,mover.getX(),mover.getZ());
    }

    switch(key){
    case '0' : bullet->set_isDead(false);
               glutPostRedisplay();
                break;
    }
}
}

void pressKey(int key, int xx, int yy){
  if(!score.gameOver)
    mover.pressKey(key, xx, yy);
}

void releaseKey(int key, int x, int y){
 if(!score.gameOver)
    mover.releaseKey(key, x, y);
}

void mouseMove(int x, int y){
   if(!score.gameOver)
    mover.mouseMove(x, y);
}

void mouseButton(int button, int state, int x, int y){
  if(!score.gameOver) {
  switch(button) {
    case GLUT_LEFT_BUTTON : mover.mouseButton(button, state,x, y); break;
    case GLUT_RIGHT_BUTTON : bullet->set_isDead(false);
                             glutPostRedisplay();
                             break;
  }
  }
}

void display(){
    render();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(int w, int h){
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)	h = 1;

    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(45, ratio, 0.01, 200);
    glMatrixMode(GL_MODELVIEW);
}

void idle(){
    glutPostRedisplay();
}

///*****For playing Sound ******
void playSong(){
    PlaySound(TEXT("Panda.wav"),NULL,SND_FILENAME);
}

int main(int argc, char** argv){

   //std::thread myThread(playSong);
   //myThread.detach();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize(800, 800);

    glutInitWindowPosition(500, 50);
    glutCreateWindow("THE CABAL");
    //glutFullScreen();

    land.initRendering();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();

    glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
///







/*
//stage one
animation anime11 = animation ( 48.0 , 22.0 , -2.0 , -20.0 , 0.4 );          // one
animation anime12 = animation ( 22.0 , 48.0 , -2.0, -15.0 , 0.8 );           // two
animation anime13 = animation ( 48.0 , 22.0 , -2.0 , -10.0 , 0.2 );          // three
animation anime14 = animation ( 22.0 , 48.0 , -2.0, -5.0 , 0.4 );            // four
animation anime15 = animation ( 48.0 , 22.0 , -2.0, -0.0 , 0.6 );            // four

//stage two
animation anime21 = animation ( -13.0 , 13.0 , -2.0 , -18.0 , 2.7 );          // one
animation anime22 = animation ( 13.0 , -13.0 , -2.0 , -12.0 , 2.5 );          // two
animation anime23 = animation ( -13.0 , 13.0 , -2.0 , -10.0 , 2.6 );          // three
animation anime24 = animation ( 13.0 , -13.0 , -2.0 , -6.0 , 2.4 );           // four
animation anime25 = animation ( -13.0 , 13.0 , -2.0 , -2.0 , 2.5 );           // five
animation anime26 = animation ( 13.0 , -13.0 , -2.0 , 2.0 , 2.3 );            // six
animation anime27 = animation ( -13.0 , 13.0 , -2.0 , 6.0 , 2.4 );            // seven
animation anime28 = animation ( 13.0 , -13.0 , -2.0 , 10.0 , 2.4 );            // eight

//stage three
animation anime31 = animation ( -22.0 , -32.0 , -2.0 , -17.0 , 1.7 );          // one going left
*/

/*
    if(mover.STAGE == 1) {
        glPushMatrix();
            anime11.animateLeft( &anime11.initX , &anime11.endX , &anime11.initY , &anime11.initZ , anime11.speed );
            glTranslatef( anime11.x , anime11.initY , anime11.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

        glPushMatrix();
            anime12.animate( &anime12.initX , &anime12.endX , &anime12.initY , &anime12.initZ , anime12.speed );
            glTranslatef( anime12.x , anime12.initY , anime12.initZ );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime13.animateLeft( &anime13.initX , &anime13.endX , &anime13.initY , &anime13.initZ , anime13.speed );
            glTranslatef( anime13.x , anime13.initY , anime13.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

        glPushMatrix();
            anime14.animate( &anime14.initX , &anime14.endX , &anime14.initY , &anime14.initZ , anime14.speed );
            glTranslatef( anime14.x , anime14.initY , anime14.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime15.animateLeft( &anime15.initX , &anime15.endX , &anime15.initY , &anime15.initZ , anime15.speed );
            glTranslatef( anime15.x , anime15.initY , anime15.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

  }

  else if(mover.STAGE == 2) {

        glPushMatrix();
            anime21.animate( &anime21.initX , &anime21.endX , &anime21.initY , &anime21.initZ , anime21.speed );
            glTranslatef( anime21.x , anime21.initY , anime21.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime22.animateLeft( &anime22.initX , &anime22.endX , &anime22.initY , &anime22.initZ , anime22.speed );
            glTranslatef( anime22.x , anime22.initY , anime22.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

        glPushMatrix();
            anime23.animate( &anime23.initX , &anime23.endX , &anime23.initY , &anime23.initZ , anime23.speed );
            glTranslatef( anime23.x , anime23.initY , anime23.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime24.animateLeft( &anime24.initX , &anime24.endX , &anime24.initY , &anime24.initZ , anime24.speed );
            glTranslatef( anime24.x , anime24.initY , anime24.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

        glPushMatrix();
            anime25.animate( &anime25.initX , &anime25.endX , &anime25.initY , &anime25.initZ , anime25.speed );
            glTranslatef( anime25.x , anime25.initY , anime25.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime26.animateLeft( &anime26.initX , &anime26.endX , &anime26.initY , &anime26.initZ , anime26.speed );
            glTranslatef( anime26.x , anime26.initY , anime26.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();

        glPushMatrix();
            anime27.animate( &anime27.initX , &anime27.endX , &anime27.initY , &anime27.initZ , anime27.speed );
            glTranslatef( anime27.x , anime27.initY , anime27.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("E");
        glPopMatrix();

        glPushMatrix();
            anime28.animateLeft( &anime28.initX , &anime28.endX , &anime28.initY , &anime28.initZ , anime28.speed );
            glTranslatef( anime28.x , anime28.initY , anime28.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();
    }

    else{
        glPushMatrix();
            anime31.animateLeft( &anime31.initX , &anime31.endX , &anime31.initY , &anime31.initZ , anime31.speed );
            glTranslatef( anime31.x , anime31.initY , anime31.initZ  );
            glScaled(0.3,0.3,0.3);
            charecter.drawCharecter("C");
        glPopMatrix();
    }


    //Main character
    glPushMatrix();
        glTranslated(mover.getX()+ mover.getLx(),-1.7,mover.getZ()+ mover.getLz());
        glScaled(0.2,0.2,0.2);
        charecter.drawCharecter("M");
    glPopMatrix();
*/
