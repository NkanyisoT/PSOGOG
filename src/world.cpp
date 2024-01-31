#include "world.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <cmath>
#include <iostream>
#include "imageloader.h"

using namespace std;

GLuint roofTexture,brickTexture,cloudsTexture,grassTexture,stoneTexture,windowTexture,landTexture;

World::World(){
    loadPlanes();
    //ctor
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);               //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);    //Tell OpenGL which texture to edit

	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                 //Always GL_TEXTURE_2D
				 0,                             //0
				 GL_RGB,                        //Format OpenGL uses for image
				 image->width, image->height,   //Width and height
				 0,                             //The border of the image
				 GL_RGB,                        //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE,              //GL_UNSIGNED_BYTE, because pixels are stored as unsigned numbers
				 image->pixels);                //The actual pixel data
	return textureId;                           //Returns the id of the texture
}

void World::initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* brick = loadBMP("brick.bmp");
	brickTexture = loadTexture(brick);
	delete brick;

	Image* roof = loadBMP("roof.bmp");
	roofTexture = loadTexture(roof);
	delete roof;

	Image* clouds = loadBMP("mountClouds.bmp");
	cloudsTexture = loadTexture(clouds);
	delete clouds;

	Image* grass = loadBMP("grass2.bmp");
	grassTexture = loadTexture(grass);
	delete grass;

	Image* stone = loadBMP("stones.bmp");
	stoneTexture = loadTexture(stone);
	delete stone;

	Image* window = loadBMP("window.bmp");
    windowTexture = loadTexture(window);
	delete window;

	Image* mountains = loadBMP("mountains.bmp");
    landTexture = loadTexture(mountains);
	delete mountains;
}

void World::walls(){
    glColor3f(30.0, 30.0, 0.0); // green

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stoneTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    //left wall
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(50.0f, 8.f, -20.0f);
        glTexCoord2f(10.0f, 0.0f);
        glVertex3f(50.0f, 8.0f, 30.0f);
        glTexCoord2f(10.0f, 5.0f);
        glVertex3f(50.0f, -2.0f, 30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(50.0f, -2.0f, -20.0f);
    glEnd();

    //back wall
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(50.0f, 8.f, 30.0f);
        glTexCoord2f(10.0f, 0.0f);
        glVertex3f(-50.0f, 8.0f, 30.0f);
        glTexCoord2f(10.0f, 5.0f);
        glVertex3f(-50.0f, -2.0f, 30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(50.0f, -2.0f, 30.0f);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-50.0f, 8.f, 20.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f(-50.0f, 8.0f, -30.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f(-50.0f, -2.0f, -30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(-50.0f, -2.0f, 20.0f);
    glEnd();

    //front wall
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(50.0f, 8.f, -30.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f(-50.0f, 8.0f, -30.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f(-50.0f, -2.0f, -30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(50.0f, -2.0f, -30.0f);
    glEnd();

    //wall 1
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 20.0f, 8.0f, 20.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f( 20.0f, 8.0f, -30.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f( 20.0f, -2.0f, -30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f( 20.0f, -2.0f,  20.0f);
    glEnd();

        //wall  2
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 15.0, 8.0f, -20.0);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f( 15.0, 8.0f,  30.0);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f( 15.0, -2.0f,  30.0);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f( 15.0, -2.0f, -20.0);
    glEnd();

    //wall 3
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f( -15.0f, 8.0f, 20.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f( -15.0f, 8.0f, -30.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f( -15.0f, -2.0f, -30.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f( -15.0f, -2.0f,  20.0f);
    glEnd();

    //wall 4
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f( -20.0, 8.0f, -20.0);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f( -20.0, 8.0f,  30.0);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f( -20.0, -2.0f,  30.0);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f( -20.0, -2.0f, -20.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void World::ground(){
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grassTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    //left wall
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-80.0f, -2.0f, 60.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f(80.0f, -2.0f, 60.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f(80.0f, -2.0f, -60.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(-80.0f, -2.0f, -60.0f);
    glEnd();


    glDisable(GL_TEXTURE_2D);
}

void World::sky(){
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cloudsTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0,1.0,1.0);

    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-100.0f, 35.f, -200.0f);
        glTexCoord2f(5.0f, 0.0f);
        glVertex3f(-100.0f, 35.0f, 200.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f(100.0f, 35.0f, 200.0f);
        glTexCoord2f(0.0f, 5.0f);
        glVertex3f(100.0f, 35.0f, -200.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void World::landscape(){
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, landTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-90.0f, 35.f, 60.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(90.0f, 35.0f, 60.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(90.0f, -2.0f, 60.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-90.0f, -2.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-90.0f, 35.f, -60.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(90.0f, 35.0f, -60.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(90.0f, -2.0f, -60.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-90.0f, -2.0f, -60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(80.0f, 35.f, -70.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(80.0f, 35.0f, 70.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(80.0f, -2.0f, 70.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(80.0f, -2.0f, -70.0f);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-80.0f, 35.f, -70.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-80.0f, 35.0f, 70.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-80.0f, -2.0f, 70.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-80.0f, -2.0f, -70.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void World::drawHouse(){

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, brickTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Side Panel - right
    glBegin( GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(5.0f, -2.0f, -5.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(5.0f, -2.0f, 5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(5.0f, 4.0f, 5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(5.0f, 4.0f, -5.0f);
    glEnd();

    // Back Panel
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(5.0f, -2.0f, 5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(5.0f, 4.0f, 5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-5.0f, 4.0f, 5.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-5.0f, -2.0f, 5.0f);
    glEnd();

    // Side Panel - left
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-5.0f, -2.0f, -5.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-5.0f, -2.0f, 5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-5.0f, 4.0f, 5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-5.0f, 4.0f, -5.0f);
    glEnd();

    // Front Left Panel
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(5.0f, -2.0f, -5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(5.0f, 4.0f, -5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 4.0f, -5.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(1.0f, -2.0f, -5.0f);
    glEnd();

    // Front Right Panel
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-5.0f, -2.0f, -5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-5.0f, 4.0f, -5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1.0f, 4.0f, -5.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, -2.0f, -5.0f);
    glEnd();

    // Panel Above The Door
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.675f, 0.675f);
        glVertex3f(1.0f, 4.0f, -5.0f);
        glTexCoord2f(0.5f, 0.675f);
        glVertex3f(1.0f, 3.0f, -5.0f);
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(-1.0f, 3.0f, -5.0f);
        glTexCoord2f(0.675f, 0.5f);
        glVertex3f(-1.0f, 4.0f, -5.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, roofTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Front Roof
    glBegin( GL_TRIANGLES );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, -5.0f);
        glTexCoord2f(5.0f, 5.0f);
        glVertex3f(6.5f, 4.0f, -5.0f);
        glTexCoord2f(10.0f, 0.0f);
        glVertex3f(-6.5f, 4.0f, -5.0f);
    glEnd();

    // Back Roof
    glBegin( GL_TRIANGLES );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, 5.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(6.5f, 4.0f, 5.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-6.5f, 4.0f, 5.0f);
    glEnd();

    //Top Right Panel
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, -6.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, 6.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-6.5f, 4.0f, 6.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-6.5f, 4.0f, -6.0f);
    glEnd();

    // Top Left Panel
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, -6.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.0f, 7.0f, 6.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(6.5f, 4.0f, 6.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(6.5f, 4.0f, -6.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, windowTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Right Window
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-2.5f, 3.0f, -5.01f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-2.5f, 1.0f, -5.01f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-4.0f, 1.0f, -5.01f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-4.0f, 3.0f, -5.01f);
    glEnd();

    // Left Window
    glPushMatrix();
    glBegin( GL_QUADS );
        glNormal3f(0.0, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(4.0f, 3.0f, -5.01f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4.0f, 1.0f, -5.01f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(2.5f, 1.0f, -5.01f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(2.5f, 3.0f, -5.01f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void World::loadPlanes()
{
        //left wall
        point p1(50.0f, 8.f, -20.0f);
        point p2(50.0f, 8.0f, 30.0f);
        point p3(50.0f, -2.0f, 30.0f);
        point p4(50.0f, -2.0f, -20.0f);
        plane plane1(p1, p2, p3, p4);
        planes.push_back(plane1);

        //back wall
        point p5(50.0f, 8.f, 30.0f);
        point p6(-50.0f, 8.0f, 30.0f);
        point p7(-50.0f, -2.0f, 30.0f);
        point p8(50.0f, -2.0f, 30.0f);
        plane plane2(p5, p6, p7, p8);
        planes.push_back(plane2);

        //right wall
        point p11(-50.0f, 8.f, 20.0f);
        point p22(-50.0f, 8.0f, -30.0f);
        point p33(-50.0f, -2.0f, -30.0f);
        point p44(-50.0f, -2.0f, 20.0f);
        plane plane3(p11, p22, p33, p44);
        planes.push_back(plane3);

        //front wall
        point p55(50.0f, 8.f, -30.0f);
        point p66(-50.0f, 8.0f, -30.0f);
        point p77(-50.0f, -2.0f, -30.0f);
        point p88(50.0f, -2.0f, -30.0f);
        plane plane4(p55, p66, p77, p88);
        planes.push_back(plane4);

        //wall 4
        point p19(15.0, 10.0f, -20.0);
        point p20(15.0, 10.0f,  30.0);
        point p21(15.0, -2.0f,  30.0);
        point p23(15.0, -2.0f, -20.0);
        plane plane7(p19, p20, p21, p23);
        planes.push_back(plane7);

         //wall 3
        point p15(-15.0f, 8.0f, 20.0f);
        point p16(-15.0f, 8.0f, -30.0f);
        point p17(-15.0f, -2.0f, -30.0f);
        point p18(-15.0f, -2.0f,  20.0f);
        plane plane6(p15, p16, p17, p18);
        planes.push_back(plane6);

        //wall 2
        point pp( -20.0, 8.0f, -20.0);
        point ppp(-20.0, 8.0f,  30.0);
        point pppp(-20.0, -2.0f,  30.0);
        point ppppp(-20.0, -2.0f, -20.0);
        plane planep(pp, ppp, pppp, ppppp);
        planes.push_back(planep);

        //wall 1
        point p9(20.0f, 10.0f, 20.0f);
        point p10(20.0f, 10.0f, -30.0f);
        point p13(20.0f, -2.0f, -30.0f);
        point p14( 20.0f, -2.0f,  20.0f);
        plane plane5(p9, p10, p13, p14);
        planes.push_back(plane5);

        ///*STAGE ONE*///
            //right side
        point p80(36, -2.0, 19.0);
        point p81(36, 4.0, 19.0);
        point p82(36, 4.0, 29.0);
        point p83(36, -2.0, 29.0);
        plane plane80(p80, p81, p82, p83);
        planes.push_back(plane80);

            //left side
        point p85(26.0, -2.0, 29.0);
        point p86(26.0, 4.0,  29.0);
        point p87(26.0, 4.0,  19.0);
        point p89(26.0, -2.0, 19.0);
        plane plane84(p85, p86, p87, p89);
        planes.push_back(plane84);

        //back
        /*/point p91(36.0, -2.0, 29.0);
        point p92(36.0, 4.0,  29.0);
        point p93(26.0, 4.0,  29.0);
        point p94(26.0, -2.0, 29.0);
        plane plane90(p91, p92, p93, p94);
        planes.push_back(plane90);*/

        //front right
        /*point pp81(32.0, -2.0, 19.0);
        point pp82(32.0, 4.0, 19.0);
        point pp83(36.0, 4.0, 19.0);
        point pp84(36.0, -2.0, 19.0);
        plane planep80(pp81, pp82, pp83, pp84);
        planes.push_back(planep80);*/

        //front left
        /*point pp91(30, -2.0, 19.0);
        point pp92(30, 4.0,  19.0);
        point pp93(26.0, 4.0,  19.0);
        point pp94(26.0, -2.0, 19.0);
        plane planep90(pp91, pp92, pp93, pp94);
        planes.push_back(planep90);*/
        ///*STAGE ONE*///

        ///*STAGE TWO*///
            //right side
        point r80(6, -2.0, 19.0);
        point r81(6, 4.0, 19.0);
        point r82(6, 4.0, 29.0);
        point r83(6, -2.0, 29.0);
        plane rlane80(r80, r81, r82, r83);
        planes.push_back(rlane80);

            //left side
        point r85(-4.0, -2.0, 29.0);
        point r86(-4.0, 4.0,  29.0);
        point r87(-4.0, 4.0,  19.0);
        point r89(-4.0, -2.0, 19.0);
        plane rlane84(r85, r86, r87, r89);
        planes.push_back(rlane84);

        //back
        /*/point r91(6.0, -2.0, 29.0);
        point r92(6.0, 4.0,  29.0);
        point r93(-4.0, 4.0,  29.0);
        point r94(-4.0, -2.0, 29.0);
        plane rlane90(r91, r92, r93, r94);
        planes.push_back(rlane90);*/

        //front right
        /*point rp81(32.0, -2.0, 19.0);
        point rp82(32.0, 4.0, 19.0);
        point rp83(36.0, 4.0, 19.0);
        point rp84(36.0, -2.0, 19.0);
        plane rlanep80(rp81, rp82, rp83, rp84);
        planes.push_back(rlanep80);*/

        //front left
        /*point rp91(30, -2.0, 19.0);
        point rp92(30, 4.0,  19.0);
        point rp93(26.0, 4.0,  19.0);
        point rp94(26.0, -2.0, 19.0);
        plane rlanep90(rp91, rp92, rp93, rp94);
        planes.push_back(rlanep90);*/

        ///

            //right side
        point t80(-6, -2.0, -19.0);
        point t81(-6, 4.0, -19.0);
        point t82(-6, 4.0, -29.0);
        point t83(-6, -2.0, -29.0);
        plane tlane80(t80, t81, t82, t83);
        planes.push_back(tlane80);

            //left side
        point t85(4.0, -2.0, -29.0);
        point t86(4.0, 4.0,  -29.0);
        point t87(4.0, 4.0,  -19.0);
        point t89(4.0, -2.0, -19.0);
        plane tlane84(t85, t86, t87, t89);
        planes.push_back(tlane84);

        //back
        /*/point t91(-6.0, -2.0, -28.0);
        point t92(-6.0, 4.0,  -28.0);
        point t93(4.0, 4.0,  -28.0);
        point t94(4.0, -2.0, -28.0);
        plane tlane90(t91, t92, t93, t94);
        planes.push_back(tlane90);*/

        //front right
        /*point tp81(-6.0, -2.0, -19.0);
        point tp82(-6.0, 4.0, -19.0);
        point tp83(-2.0, 4.0, -19.0);
        point tp84(-2.0, -2.0, -19.0);
        plane tlanep80(tp81, tp82, tp83, tp84);
        planes.push_back(tlanep80);*/

        //front left
        /*point tp91(4.0, -2.0, -19.0);
        point tp92(4.0, 4.0,  -19.0);
        point tp93(0.0, 4.0,  -19.0);
        point tp94(0.0, -2.0, -19.0);
        plane tlanep90(tp91, tp92, tp93, tp94);
        planes.push_back(tlanep90);*/
        ///*STAGE TWO*///

        ///*STAGE THREE*///
            ///house one
            //right side
        point q80(-29, -2.0, 19.0);
        point q81(-29, 4.0, 19.0);
        point q82(-29, 4.0, 29.0);
        point q83(-29, -2.0, 29.0);
        plane qlane80(q80, q81, q82, q83);
        planes.push_back(qlane80);

            //left side
        point q85(-19, -2.0, 19.0);
        point q86(-19, 4.0,  19.0);
        point q87(-19, 4.0,  29.0);
        point q89(-19, -2.0, 29.0);
        plane qlane84(q85, q86, q87, q89);
        planes.push_back(qlane84);

        //back
        /*/point q91(-29.0, -2.0, -29.0);
        point q92(-29.0, 4.0,  -29.0);
        point q93(-19.0, 4.0,  -29.0);
        point q94(-19.0, -2.0, -29.0);
        plane qlane90(q91, q92, q93, q94);
        planes.push_back(qlane90);*/

        //front right
        /*point qp81(-29.0, -2.0, -19.0);
        point qp82(-29.0, 4.0, -19.0);
        point qp83(-25.0, 4.0, -19.0);
        point qp84(-25.0, -2.0, -19.0);
        plane qlanep80(qp81, qp82, qp83, qp84);
        planes.push_back(qlanep80);*/

        //front left
        /*point qp91(-19, -2.0, -19.0);
        point qp92(-19, 4.0,  -19.0);
        point qp93(-23.0, 4.0,  -19.0);
        point qp94(-23.0, -2.0, -19.0);
        plane qlanep90(qp91, qp92, qp93, qp94);
        planes.push_back(qlanep90);*/

        /// house two
            //right side
        point b80(-41, -2.0, -19.0);
        point b81(-41, 4.0, -19.0);
        point b82(-41, 4.0, -29.0);
        point b83(-41, -2.0, -29.0);
        plane blane80(b80, b81, b82, b83);
        planes.push_back(blane80);

            //left side
        point b85(-51, -2.0, -19.0);
        point b86(-51, 4.0,  -19.0);
        point b87(-51, 4.0,  -29.0);
        point b89(-51, -2.0, -29.0);
        plane blane84(b85, b86, b87, b89);
        planes.push_back(blane84);

        //back
        /*/point b91(-51.0, -2.0, -29.0);
        point b92(-51.0, 4.0,  -29.0);
        point b93(-41.0, 4.0,  -29.0);
        point b94(-41.0, -2.0, -29.0);
        plane blane90(b91, b92, b93, b94);
        planes.push_back(blane90);*/

        //front right
        /*point bp81(-51.0, -2.0, -19.0);
        point bp82(-51.0, 4.0, -19.0);
        point bp83(-47.0, 4.0, -19.0);
        point bp84(-47.0, -2.0, -19.0);
        plane blanep80(bp81, bp82, bp83, bp84);
        planes.push_back(blanep80);*/

        //front left
        /*point bp91(-41, -2.0, -19.0);
        point bp92(-41, 4.0,  -19.0);
        point bp93(-45.0, 4.0,  -19.0);
        point bp94(-45.0, -2.0, -19.0);
        plane blanep90(bp91, bp92, bp93, bp94);
        planes.push_back(blanep90);*/

        /// house three
        //right side
        /*point m80(-45, -2.0, 2.0);
        point m81(-45, 4.0, 2.0);
        point m82(-55, 4.0, 2.0);
        point m83(-55, -2.0, 2.0);
        plane mlane80(m80, m81, m82, m83);
        planes.push_back(mlane80);*/

        //left side
        /*point m85(-45, -2.0, 12.0);
        point m86(-45, 4.0,  12.0);
        point m87(-55, 4.0,  12.0);
        point m89(-55, -2.0, 12.0);
        plane mlane84(m85, m86, m87, m89);
        planes.push_back(mlane84);*/

        //back
        point m91(-55.0, -2.0, 12.0);
        point m92(-55.0, 4.0,  12.0);
        point m93(-55.0, 4.0,  2.0);
        point m94(-55.0, -2.0, 2.0);
        plane mlane90(m91, m92, m93, m94);
        planes.push_back(mlane90);

        //front right
        point mp81(-45.0, -2.0, 12.0);
        point mp82(-45.0, 4.0, 12.0);
        point mp83(-45.0, 4.0, 8.0);
        point mp84(-45.0, -2.0, 8.0);
        plane mlanep80(mp81, mp82, mp83, mp84);
        planes.push_back(mlanep80);

        //front left
        point mp91(-39, -2.0, 2.0);
        point mp92(-39, 4.0,  2.0);
        point mp93(-39.0, 4.0,  6.0);
        point mp94(-39.0, -2.0, 6.0);
        plane mlanep90(mp91, mp92, mp93, mp94);
        planes.push_back(mlanep90);

        /// house four
        //right side
        /*point s80(-20.0, -2.0, -6.0);
        point s81(-20.0, 4.0, -6.0);
        point s82(-30.0, 4.0, -6.0);
        point s83(-30.0, -2.0, -6.0);
        plane slane80(s80, s81, s82, s83);
        planes.push_back(slane80);*/

        //left side
        /*point s85(-20.0, -2.0, -12.0);
        point s86(-20.0, 4.0,  -12.0);
        point s87(-30.0, 4.0,  -12.0);
        point s89(-30.0, -2.0, -12.0);
        plane slane84(s85, s86, s87, s89);
        planes.push_back(slane84);*/

        //back
        point s91(-20.0, -2.0, -6.0);
        point s92(-20.0, 4.0,  -6.0);
        point s93(-20.0, 4.0,  -12.0);
        point s94(-20.0, -2.0, -12.0);
        plane slane90(s91, s92, s93, s94);
        planes.push_back(slane90);

        //front left
        point sp81(-30, -2.0, -6.0);
        point sp82(-30, 4.0, -6.0);
        point sp83(-30, 4.0, -2.0);
        point sp84(-30, -2.0, -2.0);
        plane slanep80(sp81, sp82, sp83, sp84);
        planes.push_back(slanep80);

        //front right
        point sp91(-35, -2.0, -8.0);
        point sp92(-35, 4.0,  -8.0);
        point sp93(-35, 4.0,  -12.0);
        point sp94(-35, -2.0, -12.0);
        plane slanep90(sp91, sp92, sp93, sp94);
        planes.push_back(slanep90);

        ///*STAGE THREE*///
}

void World::stageOne(){
        //NORTH
    glPushMatrix();
        glTranslatef(35, -2, 24);
        drawHouse();
    glPopMatrix();
}

void World::stageTwo(){
        //NORTH NORTH-WEST
    glPushMatrix();
        glTranslatef(5, -2, 24);
        drawHouse();
    glPopMatrix();

        //SOUTH
    glPushMatrix();
        glRotatef(180,0,1,0);
        glTranslatef(5, -2, 24);
        drawHouse();
    glPopMatrix();
}

void World::stageThree(){
        //NORTH NORTH-WEST
    glPushMatrix();
        glTranslatef(-30, -2, 24);
        drawHouse();
    glPopMatrix();

        //EAST
    glPushMatrix();
        glRotatef(-90,0,1,0);
        glTranslatef(6.5, -2, 44);
        drawHouse();
    glPopMatrix();

        //WEST
    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(6.5, -2, -26.5);
        drawHouse();
    glPopMatrix();

        //SOUTH SOUTH-EAST
    glPushMatrix();
        glRotatef(180,0,1,0);
        glTranslatef(40, -2, 24);
        drawHouse();
    glPopMatrix();
}

void World::render(){
    sky();
    ground();
    walls();
    landscape();
    stageOne();
    stageTwo();
    stageThree();
}

vector<plane> World::getPlanes(){
    return planes;
}

World::~World(){
    //dtor
}
