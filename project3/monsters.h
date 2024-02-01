#include <iostream>

#include "map.h"
#include "inventory.h"

using namespace std;

class monsters
{
    private:
        string monster_name_; //stores the monsterss' names
        int challenge_rating_; //stores the monsters' challenge ratings
    public:
        //default constructor
        monsters();
        //paramatized constructor
        monsters(string monster_name, int challenge_rating);
        //getters
        string getMonsterName();
        int getChallengeRating();
        //setters
        void setMonsterName(string monster_name);
        void setChallengeRating(int challenge_rating);
};