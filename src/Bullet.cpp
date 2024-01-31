#include "Bullet.h"
#include "point.h"
#include <iostream>

#include "Sphere.h"
#include "plane.h"
#include "Charecter.h"
#include <vector>
using namespace std;

Bullet::Bullet(point cur, point dir) :Sphere(cur.x, cur.y, cur.z)
{
  current = cur;
  dirrection = dir;

}

Bullet::Bullet() :Sphere(0.0, 0.0, 0.0)
{
}

bool Bullet :: checkCollisionWithPlane(vector<plane> planes)
{
     helperCollision help;

    if((help.checkCollisionWithPlane(planes, (*this)).getState())){
        return true;
    }

    return false;
}

bool Bullet :: checkCollisionWithCharecters(vector<Charecter*>* charecterVector){

     if((*this).CharactersBullets(*charecterVector)->getState()){
        return true;
    }

    return false;
}


void Bullet :: setBulletPosition(float x, float y, float z)
{
    Sphere :: changeCoodinates(x,y,z);

}

void Bullet:: drawBullet()
{

    if(!(this->isDead)){
                Sphere ::drawSphere();

                current.x+=bulletSpeed*dirrection.x;
                // current.y+=0.003*dirrection.y;
                current.z+=bulletSpeed*dirrection.z;

                setBulletPosition(current.x, current.y, current.z);
    }

}
void Bullet :: set_isDead(bool isDead)
{
    this-> isDead = isDead;
}

bool Bullet :: get_isDead()
{
    return isDead;
}


Sphere* Bullet::checkCollisionWithSphere(vector<Sphere*> spheres)
{
    for(Sphere* s: spheres)
    {
        if((*this).isCollidingSpheres(*s))
            return s;
    }

    Sphere s;
    return &s;
}

Sphere* Bullet :: CharactersBullets(vector<Charecter*> characters)
{
    for(Charecter* chars: characters)
    {
        if(chars ->isCollidingSpheres((*this))) {
            chars->set_isDead(true);
            return chars;
        }
    }

    Sphere s;
    return &s;
}


Bullet::~Bullet()
{
    //dtor
}
