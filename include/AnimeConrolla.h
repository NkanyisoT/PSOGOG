#ifndef ANIMECONROLLA_H
#define ANIMECONROLLA_H
#include "animation.h"
#include "Charecter.h"
#include "mouse.h"
#include <vector>

class AnimeConrolla
{
    public:
        AnimeConrolla();
        void drawAnime(vector<animation*> animeVector,mouse mover,vector<Charecter*> charecterVector);
        void initAnime(vector<animation*>* animationVector);
        virtual ~AnimeConrolla();

    protected:

    private:

};

#endif // ANIMECONROLLA_H
