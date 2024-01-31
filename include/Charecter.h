#ifndef CHARECTER_H
#define CHARECTER_H
#include "animation.h"
#include "ObjLoader.h"
#include "Sphere.h"
#include <string>

class Charecter : public Sphere
{
    public:
        Charecter(ObjLoader o);
        Charecter(ObjLoader o,float x, float y, float z);
        Charecter(ObjLoader o,float r, float x, float y, float z);
        Charecter(ObjLoader o,float r);
        bool get_isDead();
        void set_isDead(bool isDead);
        bool isEnemy;
        void drawCharecter( string who );
        void setCharCord( float x , float y , float z );

    protected:

    private:
        bool isDead;
        ObjLoader obj;
};

#endif // CHARECTER_H
