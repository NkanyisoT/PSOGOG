#ifndef MOUSE_H
#define MOUSE_H

#include "point.h"
#include "Sphere.h"
#include "score.h"
#include <vector>
#include "plane.h"
#include "helperCollision.h"
//#include "Shooting.h"

class mouse
{
    public:
        mouse();
        void camera();
        void computePos(float deltaMove, vector<plane> p);
        void processNormalKeys(unsigned char key, int xx, int yy);
        void pressKey(int key, int xx, int yy);
        void releaseKey(int key, int x, int y);
        void mouseMove(int x, int y);
        void mouseButton(int button, int state, int x, int y);
        float getDeltaMove();
        float getX();
        float getLx();
        float getLz();
        float getZ();
        void setDeltaMove();
        void init();
        void mover(vector<plane> p);
        float getAngle();
        point getLookAt();
        point getPos();
        float speed=0.01;
        float getY();

        int STAGE = 1;

        float getLookAtX();
        float getLookAtY();
        float getLookAtZ();

        Sphere returnSphere();
       // void deltaMove();
        virtual ~mouse();

    protected:

    private:

// angle of rotation for the camera direction
        float angle = 0.0f;

// actual vector representing the camera's direction
        float lx=0.0f,ly=0.0,lz=-1.0f;

// XZ position of the camera
        float x=0.0f,y=-1.0f, z=5.0f;
// the key states. These variables will be zero
//when no key is being presses
        float deltaAngle = 0.0f;
        float deltaMove = 0;
        int xOrigin = -1;

        Sphere cam;
        helperCollision help;
        Score score;
};

#endif // MOUSE_H
