#ifndef ANIMATION_H
#define ANIMATION_H

#include "point.h"
class animation
{
    public:
        animation( float initX , float endX , float initY , float initZ , float speed );
        float initX , initY , initZ , x ;
        float endX , newY , newZ ;
        float speed;
        bool stop ;
        void animate( float*initX , float*endX , float*initY , float*initZ , float speed );
        void animateLeft( float*initX , float*endX , float*initY , float*initZ , float speed );
        point getPosition();

    protected:

    private:
};

#endif // ANIMATION_H
