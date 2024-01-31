#include "Collidable.h"

Collidable::Collidable()
{

}

bool Collidable::getState()
{
    return exist;
}

void Collidable::setState(bool state)
{
    exist = state;
}
Collidable::~Collidable()
{
    //dtor
}
