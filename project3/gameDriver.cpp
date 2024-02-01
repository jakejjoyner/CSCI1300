#include <iostream>

#include "game.h"

using namespace std;

int main(){

//create game object and initialize to default constructor
game g = game();

//start the game
g.startGame();

//if the player gives up, end the game
if(g.giveUp() == 1)
{
    g.gameEnd();
    return 0;
}

//infinitely loop new turns until the player gives up, loses, or wins
for(;;)
{
    g.newTurn();
    if(g.giveUp() == 1)
    {
        g.gameEnd();
        return 0;
    }
    if(g.giveUp() == 2){
        g.youWon();
        return 0;
    }
}

}