#ifndef ITEM_H
#define ITEM_H

#include "point.h"
#include "ObjLoader.h"

class Item
{
    public:
        Item(float x, float y,float z);
        Item(point pos);
        Item(float x, float y,float z,float retrivalRadius);
        Item(point pos,float retrivalRadius);
        point getPosition();
        float getRetrivalRadius();
        bool checkPosition(float pX,float pZ);
        void processNormalKeys(unsigned char key, int xx, int yy,float pX,float pZ);
        void drawItem();
        bool getState();
        virtual ~Item();

    protected:

    private:
       point position;
       float x,y,z;
       float retrivalRadius=5;
       bool state=false;
       ObjLoader key;
};

#endif // ITEM_H
