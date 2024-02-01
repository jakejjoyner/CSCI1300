#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "actionMenu.h"
#include "inventory.h"
#include "map.h"
#include "merchantMenu.h"
#include "players.h"
#include "start.h"
#include "statusUpdate.h"
#include "monsters.h"

using namespace std;

class game{

private:
    inventory i;
    players p;
    start s;
    statusUpdate su;
    actionMenu a;
    Map m;
    merchantMenu mm;
    monsters monsters_[21];
    int give_up;
    bool is_sorcerer_defeated;
    int explored_spaces;
    int turns_elapsed;
    int monsters_defeated;
public:
    //default constructor
    game();
    //other
    void startGame();
    bool fightMonster();
    void actionMenuDriver();
    void newTurn();
    int giveUp();
    void misfortune();
    void gameEnd();
    void youWon();
};

#endif