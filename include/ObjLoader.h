#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <string>
#include <vector>
#include "point.h"
#include "face.h"

using namespace std;

class ObjLoader
{
    public:
        string filename;
        ObjLoader(std:: string file);
        ObjLoader(std::string file, bool hasTex);
        void loadObj();
        void loadNormals();
        void loadTexture();
        void loadFaces();
        void loadFacesWithTexture();
        void useThisFunctionToDrawObj();
        void useThisFunctionToDrawObjWithTexture();
        virtual ~ObjLoader();

    protected:

    private:
        bool hasTex = false;
        vector<point> vertices;
        vector<point> normals;
        vector<face> faces;
        vector<point> texture;
};

#endif // OBJLOADER_H
