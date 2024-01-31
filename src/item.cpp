#include "item.h"
#include <math.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

Item::Item(float x, float y,float z) : key("key.obj")
{
    this->x=x;
    this->y=y;
    this->z=z;

    //this->retrivalRadius=2.0f;
}

Item::Item(point pos) : key("key.obj")
{
    this->position=pos;
    this->retrivalRadius=1.0f;
}

Item::Item(float x, float y,float z,float retrivalRadius) : key("key.obj")
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->retrivalRadius=retrivalRadius;
}

Item::Item(point pos,float retrivalRadius) : key("key.obj")
{
    this->position=pos;
    this->retrivalRadius=retrivalRadius;
}
point Item::getPosition()
{
    return position;
}

float Item::getRetrivalRadius()
{
    return retrivalRadius;
}
bool Item::checkPosition(float pX,float pZ)
{
    float playerDistance = sqrt(pow(x- pX,2) + pow(z- pZ,2));

    return playerDistance<retrivalRadius;
}

void Item::drawItem()
{   //cout<< " X "<<x<<" Y : "<<y<<" Z : "<<z<<endl;
    glPushMatrix();
    glColor3f(1,0,0);
   // glTranslated(position.getX(),position.getY(),position.getZ());
    glTranslated(x,y,z);
    glScaled(0.1, 0.1, 0.1);
    key.useThisFunctionToDrawObj();
    glPopMatrix();
   // cout<<".........................................................." <<state<<endl;

   // cout<< " X "<<position.getX()<<" Y : "<<position.getY()<<" Z : "<<position.getZ()<<endl;

}

    void Item::processNormalKeys(unsigned char key, int xx, int yy ,float pX,float pZ)
{
 switch(key)
    {
    case 'e' : state = checkPosition(pX,pZ);
        break;
    }
   // cout<<".........................................................." <<state<<" X : "<< pX<<" Z : "<<pZ<<endl;
}
    bool Item::getState()
    {
        //cout<<".........................................................." <<state<<endl;
        return state;
    }

Item::~Item()
{
    //dtor
}
