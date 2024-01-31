#ifndef BULLET_H
#define BULLET_H

#include "Sphere.h"
#include "plane.h"
#include "helperCollision.h"

class Bullet : public Sphere
{
    public:
        Bullet(point cur, point dir);
        Bullet();
        void set_isDead(bool isDead);
        bool get_isDead();
        void setBulletPosition(float x, float y, float z);
        bool checkCollisionWithPlane(vector<plane> plane);
        bool checkCollisionWithCharecters(vector<Charecter*>* charecterVector);
        Sphere* checkCollisionWithSphere(vector<Sphere*> spheres);
        Sphere* CharactersBullets(vector<Charecter*> characters);
        void drawBullet();
        virtual ~Bullet();

    protected:

    private:
        point current;
        point dirrection;
        bool isDead = true;
        const float bulletSpeed = 0.7;
};

#endif // BULLET_H
