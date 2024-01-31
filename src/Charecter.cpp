#include "Charecter.h"
#include "ObjLoader.h"
#include <windows.h>
#include <GL/glut.h>
#include "animation.h"
#include <string>
#include "ObjLoader.h"

using namespace std ;


Charecter::Charecter(ObjLoader o )
:obj(o)
{
   isDead = false ;
}

Charecter::Charecter(ObjLoader o,float x, float y, float z):Sphere(x,y,z),obj(o)
{
    isDead = false ;
}
Charecter::Charecter(ObjLoader o,float r, float x, float y, float z) :Sphere(r,x,y,z),obj(o)
{
    isDead = false ;
}
Charecter::Charecter(ObjLoader o,float r) : Sphere(r),obj(o)
{
    isDead = false ;
}

bool Charecter :: get_isDead()
{
    return isDead;
}

void Charecter :: set_isDead(bool isDead)
{
    this -> isDead = isDead;
}


 void Charecter::drawCharecter( string who ){

     if ( who.compare("E") == 0 ){
            glColor3f( 1.0 , 0.0 , 0.0 );
       obj.useThisFunctionToDrawObj();
     }
     else if ( who.compare("C") == 0 ){
            glColor3f( 0.0 , 0.0 , 1.0 );
       obj.useThisFunctionToDrawObj();
     }
      else if ( who.compare("M") == 0 ){
            glColor3f( 0.0 , 1.0 , 0.0 );
       obj.useThisFunctionToDrawObj();
     }

}

void Charecter::setCharCord( float x , float y , float z )
{
     Sphere:: changeCoodinates(x,y+1,z);
}
