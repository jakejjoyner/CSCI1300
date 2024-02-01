#include <iostream>
#include <ctime>
#include <cstdlib>

#include "monsters.h"
#include "map.h"
#include "inventory.h"
#include "players.h"

using namespace std;

//default constructor
monsters::monsters()
{
    monster_name_ = "";
    challenge_rating_ = 0;
}
//parametized constructor
monsters::monsters(string monster_name, int challenge_rating)
{
    monster_name_ = monster_name;
    challenge_rating_ = challenge_rating;
}
//getters
int monsters::getChallengeRating()
{
    return challenge_rating_;
}

string monsters::getMonsterName()
{
    return monster_name_;
}
//setters
void monsters::setChallengeRating(int challenge_rating)
{
    challenge_rating_ = challenge_rating;
}

void monsters::setMonsterName(string monster_name)
{
    monster_name_ = monster_name;
}
