#include "AnimeConrolla.h"
#include "animation.h"
#include "mouse.h"
#include <GL/freeglut.h>
#include <vector>
#include <iostream>

mouse moverPos;

AnimeConrolla :: AnimeConrolla()
{
}

void AnimeConrolla ::  initAnime(vector<animation*>* animeVector)
{
               // Characters In Stage One
    animeVector->push_back(new animation ( 22.0 , 48.0 , -2.0 , -20.0 , 1.4 ) ); // 0
    animeVector->push_back( new animation ( 48.0 , 22.0 , -2.0 , -15.0 , 1.8 ) ); // 1
    animeVector->push_back( new animation ( 22.0 , 48.0 , -2.0 , -10.0 , 1.2 ) ); // 2
    animeVector->push_back( new animation ( 48.0 , 22.0 , -2.0 , -5.0 , 1.4 ) ); // 3
    animeVector->push_back( new animation ( 22.0 , 48.0 , -2.0 , 0.0 , 1.6 ) ); // 4
    animeVector->push_back( new animation ( 48.0 , 22.0 , -2.0 , 5.0 , 1.7 ) ); // 5
    animeVector->push_back( new animation ( 22.0 , 48.0 , -2.0 , 10.0 , 1.3 ) ); // 6
    animeVector->push_back( new animation ( 48.0 , 22.0 , -2.0 , 15.0 , 1.5 ) ); // 7


    // Characters In Stage Two
    animeVector->push_back( new animation ( -13.0 , 13.0 , -2.0 , -18.0 , 2.7) ); // 9
    animeVector->push_back( new animation ( 13.0 , -13.0 , -2.0 , -14.0 , 2.5 ) ); // 10
    animeVector->push_back( new animation ( -13.0 , 13.0 , -2.0 , -10.0 , 2.6 ) ); //11
    animeVector->push_back( new animation ( 13.0 , -13.0 , -2.0 , -6.0 , 2.4 ) ); // 12
    animeVector->push_back( new animation ( -13.0 , 13.0 , -2.0 , -2.0 , 2.5 ) ); //13
    animeVector->push_back( new animation ( 13.0 , -13.0 , -2.0 , 2.0 , 2.3 ) ); //14
    animeVector->push_back( new animation ( -13.0 , 13.0 , -2.0 , 6.0 , 2.4 ) ); //15
    animeVector->push_back( new animation ( 13.0 , -13.0 , -2.0 , 10.0 , 2.7 ) ); //16
    animeVector->push_back( new animation ( -13.0 , 13.0 , -2.0 , 14.0 , 2.8 ) ); //17
    animeVector->push_back( new animation ( 13.0 , -13.0 , -2.0 , 14.0 , 2.2 ) ); //18

    // Characters In Stage Three
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , -17.0 , 3.5) ); // 19
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , -14.0 , 3.1) ); // 20
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , -11.0 , 3.5) ); // 21
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , -8.0 , 3.1) ); // 22
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , -5.0 , 3.5) ); // 23
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , -2.0 , 3.1) ); // 24
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , 1.0 , 3.5) ); // 25
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , 4.0 , 3.1) ); // 26
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , 7.0 , 3.5) ); // 27
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , 10.0 , 3.1) ); // 28
    animeVector->push_back( new animation ( -34.0 , -48.0 , -2.0 , 13.0 , 3.5) ); // 29
    animeVector->push_back( new animation ( -48.0 , -34.0 , -2.0 , 16.0 , 3.1) ); // 30


}

void AnimeConrolla :: drawAnime(vector<animation*> animeVector,mouse mover,vector<Charecter*> charecterVector){
if(moverPos.STAGE == 1){
 if(!charecterVector[0]->get_isDead()) {
    glPushMatrix();
                animeVector[0]->animate( &animeVector[0]->initX , &animeVector[0]->endX , &animeVector[0]->initY , &animeVector[0]->initZ , animeVector[0]->speed );
                glTranslatef( animeVector[0]->x , animeVector[0]->initY , animeVector[0]->initZ  );
                glScaled(0.3,0.3,0.3);
                charecterVector[0]->setCharCord(  animeVector[0]->getPosition().getX() , animeVector[0]->getPosition().getY() , animeVector[0]->getPosition().getZ());
                charecterVector[0]->drawCharecter("E");
            glPopMatrix();
 }

 if(!charecterVector[1]->get_isDead()) {
    glPushMatrix();
        animeVector[1]->animateLeft( &animeVector[1]->initX , &animeVector[1]->endX , &animeVector[1]->initY , &animeVector[1]->initZ , animeVector[1]->speed );
        glTranslatef( animeVector[1]->x , animeVector[1]->initY , animeVector[1]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[1]->setCharCord(  animeVector[1]->getPosition().getX() , animeVector[1]->getPosition().getY() , animeVector[1]->getPosition().getZ());
        charecterVector[1]->drawCharecter("C");
    glPopMatrix();

 }

 if(!charecterVector[2]->get_isDead()) {
    glPushMatrix();
        animeVector[2]->animate( &animeVector[2]->initX , &animeVector[2]->endX , &animeVector[2]->initY , &animeVector[2]->initZ , animeVector[2]->speed );
        glTranslatef( animeVector[2]->x , animeVector[2]->initY , animeVector[2]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[2]->setCharCord(  animeVector[2]->getPosition().getX() , animeVector[2]->getPosition().getY() , animeVector[2]->getPosition().getZ());
        charecterVector[2]->drawCharecter("E");
    glPopMatrix();
 }
 if(!charecterVector[3]->get_isDead()) {
    glPushMatrix();
        animeVector[3]->animateLeft( &animeVector[3]->initX , &animeVector[3]->endX , &animeVector[3]->initY , &animeVector[3]->initZ , animeVector[3]->speed );
        glTranslatef( animeVector[3]->x , animeVector[3]->initY , animeVector[3]->initZ  );
        glScaled(0.3,0.3,0.3);
        charecterVector[3]->setCharCord(  animeVector[3]->getPosition().getX() , animeVector[3]->getPosition().getY() , animeVector[3]->getPosition().getZ());
        charecterVector[3]->drawCharecter("E");
    glPopMatrix();
 }
 if(!charecterVector[4]->get_isDead()) {
    glPushMatrix();
        animeVector[4]->animate( &animeVector[4]->initX , &animeVector[4]->endX , &animeVector[4]->initY , &animeVector[4]->initZ , animeVector[4]->speed );
        glTranslatef( animeVector[4]->x , animeVector[4]->initY , animeVector[4]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[4]->setCharCord(  animeVector[4]->getPosition().getX() , animeVector[4]->getPosition().getY() , animeVector[4]->getPosition().getZ());
        charecterVector[4]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[5]->get_isDead()) {
    glPushMatrix();
        animeVector[5]->animateLeft( &animeVector[5]->initX , &animeVector[5]->endX , &animeVector[5]->initY , &animeVector[5]->initZ , animeVector[5]->speed );
        glTranslatef( animeVector[5]->x , animeVector[5]->initY , animeVector[5]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[5]->setCharCord(  animeVector[5]->getPosition().getX() , animeVector[5]->getPosition().getY() , animeVector[5]->getPosition().getZ());
        charecterVector[5]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[6]->get_isDead()) {
    glPushMatrix();
        animeVector[6]->animate( &animeVector[6]->initX , &animeVector[6]->endX , &animeVector[6]->initY , &animeVector[6]->initZ , animeVector[6]->speed );
        glTranslatef( animeVector[6]->x , animeVector[6]->initY , animeVector[6]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[6]->setCharCord(  animeVector[6]->getPosition().getX() , animeVector[6]->getPosition().getY() , animeVector[6]->getPosition().getZ());
        charecterVector[6]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[7]->get_isDead()) {
    glPushMatrix();
        animeVector[7]->animateLeft( &animeVector[7]->initX , &animeVector[7]->endX , &animeVector[7]->initY , &animeVector[7]->initZ , animeVector[7]->speed );
        glTranslatef( animeVector[7]->x , animeVector[7]->initY , animeVector[7]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[7]->setCharCord(  animeVector[7]->getPosition().getX() , animeVector[7]->getPosition().getY() , animeVector[7]->getPosition().getZ());
        charecterVector[7]->drawCharecter("E");
    glPopMatrix();
 }
}

if (moverPos.STAGE == 2){
 if(!charecterVector[8]->get_isDead()) {
    glPushMatrix();
        animeVector[8]->animate( &animeVector[8]->initX , &animeVector[8]->endX , &animeVector[8]->initY , &animeVector[8]->initZ , animeVector[8]->speed );
        glTranslatef( animeVector[8]->x , animeVector[8]->initY , animeVector[8]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[8]->setCharCord(  animeVector[8]->getPosition().getX() , animeVector[8]->getPosition().getY() , animeVector[8]->getPosition().getZ());
        charecterVector[8]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[9]->get_isDead()) {
    glPushMatrix();
        animeVector[9]->animateLeft( &animeVector[9]->initX , &animeVector[9]->endX , &animeVector[9]->initY , &animeVector[9]->initZ , animeVector[9]->speed );
        glTranslatef( animeVector[9]->x , animeVector[9]->initY , animeVector[9]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[9]->setCharCord(  animeVector[9]->getPosition().getX() , animeVector[9]->getPosition().getY() , animeVector[9]->getPosition().getZ());
        charecterVector[9]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[10]->get_isDead()) {
    glPushMatrix();
        animeVector[10]->animate( &animeVector[10]->initX , &animeVector[10]->endX , &animeVector[10]->initY , &animeVector[10]->initZ , animeVector[10]->speed );
        glTranslatef( animeVector[10]->x , animeVector[10]->initY , animeVector[10]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[10]->setCharCord(  animeVector[10]->getPosition().getX() , animeVector[10]->getPosition().getY() , animeVector[10]->getPosition().getZ());
        charecterVector[10]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[11]->get_isDead()) {
    glPushMatrix();
        animeVector[11]->animateLeft( &animeVector[11]->initX , &animeVector[11]->endX , &animeVector[11]->initY , &animeVector[11]->initZ , animeVector[11]->speed );
        glTranslatef( animeVector[11]->x , animeVector[11]->initY , animeVector[11]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[11]->setCharCord(  animeVector[11]->getPosition().getX() , animeVector[11]->getPosition().getY() , animeVector[11]->getPosition().getZ());
        charecterVector[11]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[12]->get_isDead()) {
    glPushMatrix();
        animeVector[12]->animate( &animeVector[12]->initX , &animeVector[12]->endX , &animeVector[12]->initY , &animeVector[12]->initZ , animeVector[12]->speed );
        glTranslatef( animeVector[12]->x , animeVector[12]->initY , animeVector[12]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[12]->setCharCord(  animeVector[12]->getPosition().getX() , animeVector[12]->getPosition().getY() , animeVector[12]->getPosition().getZ());
        charecterVector[12]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[13]->get_isDead()) {
    glPushMatrix();
        animeVector[13]->animateLeft( &animeVector[13]->initX , &animeVector[13]->endX , &animeVector[13]->initY , &animeVector[13]->initZ , animeVector[13]->speed );
        glTranslatef( animeVector[13]->x , animeVector[13]->initY , animeVector[13]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[13]->setCharCord(  animeVector[13]->getPosition().getX() , animeVector[13]->getPosition().getY() , animeVector[13]->getPosition().getZ());
        charecterVector[13]->drawCharecter("E");
    glPopMatrix();
 }
 if(!charecterVector[14]->get_isDead()) {
    glPushMatrix();
        animeVector[14]->animate( &animeVector[14]->initX , &animeVector[14]->endX , &animeVector[14]->initY , &animeVector[14]->initZ , animeVector[14]->speed );
        glTranslatef( animeVector[14]->x , animeVector[14]->initY , animeVector[14]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[14]->setCharCord(  animeVector[14]->getPosition().getX() , animeVector[14]->getPosition().getY() , animeVector[14]->getPosition().getZ());
        charecterVector[14]->drawCharecter("E");
    glPopMatrix();
 }
 if(!charecterVector[15]->get_isDead()) {
    glPushMatrix();
        animeVector[15]->animateLeft( &animeVector[15]->initX , &animeVector[15]->endX , &animeVector[15]->initY , &animeVector[15]->initZ , animeVector[15]->speed );
        glTranslatef( animeVector[15]->x , animeVector[15]->initY , animeVector[15]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[15]->setCharCord(  animeVector[15]->getPosition().getX() , animeVector[15]->getPosition().getY() , animeVector[15]->getPosition().getZ());
        charecterVector[15]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[16]->get_isDead()) {
    glPushMatrix();
        animeVector[16]->animate( &animeVector[16]->initX , &animeVector[16]->endX , &animeVector[16]->initY , &animeVector[16]->initZ , animeVector[16]->speed );
        glTranslatef( animeVector[16]->x , animeVector[16]->initY , animeVector[16]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[16]->setCharCord(  animeVector[16]->getPosition().getX() , animeVector[16]->getPosition().getY() , animeVector[16]->getPosition().getZ());
        charecterVector[16]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[17]->get_isDead()) {
    glPushMatrix();
        animeVector[17]->animateLeft( &animeVector[17]->initX , &animeVector[17]->endX , &animeVector[17]->initY , &animeVector[17]->initZ , animeVector[17]->speed );
        glTranslatef( animeVector[17]->x , animeVector[17]->initY , animeVector[17]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[17]->setCharCord(  animeVector[17]->getPosition().getX() , animeVector[17]->getPosition().getY() , animeVector[17]->getPosition().getZ());
        charecterVector[17]->drawCharecter("E");
    glPopMatrix();
 }
}

else{
 if(!charecterVector[18]->get_isDead()) {
    glPushMatrix();
        animeVector[18]->animate( &animeVector[18]->initX , &animeVector[18]->endX , &animeVector[18]->initY , &animeVector[18]->initZ , animeVector[18]->speed );
        glTranslatef( animeVector[18]->x , animeVector[18]->initY , animeVector[18]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[18]->setCharCord(  animeVector[18]->getPosition().getX() , animeVector[18]->getPosition().getY() , animeVector[18]->getPosition().getZ());
        charecterVector[18]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[19]->get_isDead()) {
    glPushMatrix();
        animeVector[19]->animate( &animeVector[19]->initX , &animeVector[19]->endX , &animeVector[19]->initY , &animeVector[19]->initZ , animeVector[19]->speed );
        glTranslatef( animeVector[19]->x , animeVector[19]->initY , animeVector[19]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[19]->setCharCord(  animeVector[19]->getPosition().getX() , animeVector[19]->getPosition().getY() , animeVector[19]->getPosition().getZ());
        charecterVector[19]->drawCharecter("E");
    glPopMatrix();
 }
/*
 if(!charecterVector[20]->get_isDead()) {
    glPushMatrix();
        animeVector[20]->animate( &animeVector[20]->initX , &animeVector[20]->endX , &animeVector[20]->initY , &animeVector[20]->initZ , animeVector[20]->speed );
        glTranslatef( animeVector[20]->x , animeVector[20]->initY , animeVector[20]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[20]->setCharCord(  animeVector[20]->getPosition().getX() , animeVector[20]->getPosition().getY() , animeVector[20]->getPosition().getZ());
        charecterVector[20]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[21]->get_isDead()) {
    glPushMatrix();
        animeVector[21]->animate( &animeVector[21]->initX , &animeVector[21]->endX , &animeVector[21]->initY , &animeVector[21]->initZ , animeVector[21]->speed );
        glTranslatef( animeVector[21]->x , animeVector[21]->initY , animeVector[21]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[21]->setCharCord(  animeVector[21]->getPosition().getX() , animeVector[21]->getPosition().getY() , animeVector[21]->getPosition().getZ());
        charecterVector[21]->drawCharecter("E");
    glPopMatrix();
 }

 if(!charecterVector[22]->get_isDead()) {
    glPushMatrix();
        animeVector[22]->animate( &animeVector[22]->initX , &animeVector[22]->endX , &animeVector[22]->initY , &animeVector[22]->initZ , animeVector[22]->speed );
        glTranslatef( animeVector[22]->x , animeVector[22]->initY , animeVector[22]->initZ  );
        glScaled(0.3,0.3,0.3);
         charecterVector[22]->setCharCord(  animeVector[22]->getPosition().getX() , animeVector[22]->getPosition().getY() , animeVector[22]->getPosition().getZ());
        charecterVector[22]->drawCharecter("E");
    glPopMatrix();
 }*/
}
}
AnimeConrolla::~AnimeConrolla()
{
    //dtor
}
