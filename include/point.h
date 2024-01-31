#ifndef POINT_H
#define POINT_H
//#include <iostream>
//#include "myVector.h"

class point
{
    public:
        float x, y, z;
        point();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        point(float x, float y, float z);
        point getPoint();
        virtual float getX();
        virtual float getY();
        virtual float getZ();
        virtual ~point();

    protected:

    private:
};

#endif // POINT_H
