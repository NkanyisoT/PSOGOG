#ifndef SCORE_H
#define SCORE_H
#include <string>
#include <iostream>
using namespace std;
class Score
{
    public:
        Score();
        float getScorePoints();
        void checkPos();
        void addScorePoints(float points);
        void removeScorePoints(float points);
        void awardScore();
        void init();
        void addEnemyKills();
        void addCivilKills();
        string scoreBoard();
        virtual ~Score();
        bool gameOver =  false;

    protected:

    private:
        int scorePoints;
        int enemyKills=0;
        int civilKills=0;
};

#endif // SCORE_H
