#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "point.h"

class myVector: public point
{
    public:
        myVector();
        myVector(float x, float y, float z);
        //float getX();
        //float getY();
        //float getZ();
        myVector normal();
        float dotp(myVector v);
        myVector cross(myVector v);
        virtual ~myVector();

    protected:
    private:
        float x, y, z;
};

#endif // MYVECTOR_H
