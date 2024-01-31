#ifndef WORLD_H
#define WORLD_H
#include "helperCollision.h"
#include "plane.h"
#include <vector>

class World
{
    public:
        World();
        void walls();
        void ground();
        void sky();
        void render();
        void initRendering();
        vector<plane> getPlanes();
        virtual ~World();
        bool loaded = false;
        vector<plane> planes;
        void loadPlanes();

    protected:
        void landscape();
        void drawHouse();
        void stageOne();
        void stageTwo();
        void stageThree();

    private:
};

#endif // WORLD_H
