#include "animation.h"

animation::animation( float initX , float endX , float initY , float initZ , float speed  ){
    stop = false ;
    x = initX ;

    this -> initX = initX ;
    this -> initY = initY ;
    this -> initZ = initZ ;
    this -> endX = endX ;
    this -> newY = newY ;
    this -> speed = speed ;
}

 void animation::animate( float*initX , float*endX , float*initY , float*initZ , float speed ) {

     if ( x < *initX )
        stop = true ;
     if ( x > *endX )
        stop = false ;

     if ( stop )
         x+=(speed * 0.1);
     if ( !stop )
        x-=(speed * 0.1);
}

point animation :: getPosition(){

    return point(x,initY,initZ);
}


 void animation::animateLeft( float*initX , float*endX , float*initY , float*initZ , float speed ) {

     if ( x > *initX )
        stop = false ;
     if ( x < *endX )
        stop = true ;

     if ( stop )
         x+=(speed * 0.1);
     if ( !stop )
        x-=(speed * 0.1);
}
