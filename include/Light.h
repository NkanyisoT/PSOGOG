#ifndef LIGHT_H
#define LIGHT_H

#include<GL/glut.h>


class Light
{
    public:
        Light();
        void initLight( GLenum name );
        void setLight( GLenum face , GLenum paramName , float x , float y , float z , float w );
        void setLightColor( GLenum type , GLenum paramName , float x , float y , float z );
        void setLightType( GLenum type , float x , float y , float z );
    protected:

    private:
};

#endif // LIGHT_H
