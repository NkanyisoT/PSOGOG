#include "score.h"
#include <string>
#include <iostream>
using namespace std;

Score::Score()
{

}

void Score::init()
{
    scorePoints=0;
}
void Score::checkPos()
{

}

float Score::getScorePoints()
{
    return scorePoints;
}

void Score::addScorePoints(float points)
{
    scorePoints+=points;
}
void Score::removeScorePoints(float points)
{
    scorePoints-=points;
}

void Score::addCivilKills()
{
    civilKills++;
}

void Score::addEnemyKills()
{
    enemyKills++;
}

std::string Score::scoreBoard()
{
  std::string scoreDetials;
    scoreDetials = "_____________CURRENT SCORE_______________ \n enemy kills " + (enemyKills);
    scoreDetials += "\n civilian kills " +(civilKills);
    scoreDetials +="\n Total Kills " +(enemyKills + civilKills);
    scoreDetials +="\n Total Point " +(scorePoints);
              return scoreDetials;
}
Score::~Score()
{
    //dtor
}
