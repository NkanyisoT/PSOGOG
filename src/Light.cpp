#include "Light.h"
#include<vector>

using namespace std ;

Light::Light(){

}

void Light::initLight( GLenum name ){
    glEnable(name);
}

void Light::setLight( GLenum face , GLenum paramName , float x , float y , float z , float w ){
    float pos [] = { x , y , z , w};
    glLightfv( face , paramName , pos );
}

void Light::setLightColor( GLenum face , GLenum paramName , float x , float y , float z ){
    float pos [] = { x , y , z , 1.0 };
    glLightfv( face , paramName , pos );
}

void Light::setLightType( GLenum type , float x , float y , float z ){
    float pos [] = { x , y , z , 1.0 };
    glLightModelfv( type , pos );
}



