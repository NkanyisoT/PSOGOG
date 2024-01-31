#include <fstream>
#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdio.h>

using namespace std;

#include <GL/glut.h>
#include "point.h"
#include "ObjLoader.h"
#include "face.h"

ObjLoader::ObjLoader(string file)
{
     filename = file;
     (*this).loadObj();
     (*this).loadNormals();
     (*this).loadFaces();
}

ObjLoader::ObjLoader(string file, bool has)
{
      filename = file;
     (*this).loadObj();
     (*this).loadNormals();
     (*this).loadFacesWithTexture();
     (*this).loadTexture();

}

 void ObjLoader::loadObj()
{
   ifstream in(filename.c_str());
   if(in.fail()) cout << "File not openned" << endl;

   string line;

   while(getline(in, line))
   {

       if(line.substr(0, 2) == "v ") {

          istringstream str(line.substr(2));
          point v;
          str >> v.x; str >> v.y; str >> v.z;
          (vertices).push_back(v);
       }
   }
   in.close();
}

void ObjLoader::loadTexture()
{
   ifstream in(filename.c_str());
   if(in.fail()) cout << "File not openned" << endl;

   string line;

   while(getline(in, line))
   {

       if(line.substr(0, 2) == "vt") {

          istringstream str(line.substr(2));
          point v;
          str >> v.x; str >> v.y;
          v.z = 0;
          texture.push_back(v);
       }
   }
   in.close();
}

void ObjLoader::loadNormals()
{
   ifstream in(filename.c_str());
   if(in.fail()) cout << "File not openned" << endl;

   string line;

   while(getline(in, line))
   {

       if(line.substr(0, 2) == "vn") {

          istringstream str(line.substr(2));
          point v;
          str >> v.x; str >> v.y; str >> v.z;
          normals.push_back(v);
       }
   }
   in.close();
}

void ObjLoader::loadFaces()
{
    ifstream in(filename.c_str());
    if(in.fail()) cout << "File not openned" << endl;

   string line;

   while(getline(in, line))
   {

     if(line.substr(0, 2) == "f ")
     {
       int a,b,c,d,e;

       sscanf(line.c_str(), "f %d//%d %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b, &e, &b);
       face f(a, b, c, d, e);
       faces.push_back(f);
     }
   }
}

void ObjLoader::loadFacesWithTexture()
{
    ifstream in(filename.c_str());
    if(in.fail()) cout << "File not openned" << endl;

   string line;

   while(getline(in, line))
   {

     if(line.substr(0, 2) == "f ")
     {
       int a,b,c,d,e,f;

       sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &a, &f, &b, &c, &f, &b, &d, &f, &b, &e, &f, &b);
       face f1(a, b, c, d, e, f);
       faces.push_back(f1);
     }
   }
}

void ObjLoader::useThisFunctionToDrawObj()
{

     for(unsigned int i = 0; i < faces.size(); i++) {
        glBegin(GL_QUADS);
          glNormal3f(normals[faces[i].b -1].x, normals[faces[i].b -1].y, normals[faces[i].b -1].z);
          glVertex3f(vertices[faces[i].a - 1].x,vertices[faces[i].a - 1].y, vertices[faces[i].a - 1].z);
          glVertex3f(vertices[faces[i].c - 1].x,vertices[faces[i].c - 1].y, vertices[faces[i].c - 1].z);
          glVertex3f(vertices[faces[i].d- 1].x,vertices[faces[i].d- 1].y, vertices[faces[i].d - 1].z);
          glVertex3f(vertices[faces[i].e- 1].x,vertices[faces[i].e - 1].y, vertices[faces[i].e - 1].z);
       glEnd();
       }
}

void ObjLoader::useThisFunctionToDrawObjWithTexture()
{

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

     for(unsigned int i = 0; i < faces.size(); i++) {
        glBegin(GL_QUADS);
          glTexCoord2f(texture[faces[i].f - 1].x, texture[faces[i].f - 1].y);
          glNormal3f(normals[faces[i].b -1].x, normals[faces[i].b -1].y, normals[faces[i].b -1].z);
          glVertex3f(vertices[faces[i].a - 1].x,vertices[faces[i].a - 1].y, vertices[faces[i].a - 1].z);
          glVertex3f(vertices[faces[i].c - 1].x,vertices[faces[i].c - 1].y, vertices[faces[i].c - 1].z);
          glVertex3f(vertices[faces[i].d- 1].x,vertices[faces[i].d- 1].y, vertices[faces[i].d - 1].z);
          glVertex3f(vertices[faces[i].e- 1].x,vertices[faces[i].e - 1].y, vertices[faces[i].e - 1].z);
       glEnd();
       }
    glDisable(GL_TEXTURE_2D);
}

ObjLoader::~ObjLoader()
{
    //dtor
}
