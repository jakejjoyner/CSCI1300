#include "start.h"
#include "players.h"
#include <iostream>
#include <vector>

using namespace std;

/*
Algorithm:
1. Prompt the player to enter their name and traveling companion's names
2. Present the player with information about the game
*/
void start::displayStartMenu(players &p){
    p.enterPlayerNames();
    cout << endl;
    cout << "Between the 5 of you, you will have 100 gold pieces." << endl;
    cout << "You can spend your money on any of the following items:" << endl;
    cout << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
}