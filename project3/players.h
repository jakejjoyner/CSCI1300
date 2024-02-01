#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <vector>
#include "inventory.h"

using namespace std;

class players
{
private:
vector<string> players_; //stores player names
vector<int> fullness_; // stores player fullness levels
vector<string> weapons_; //stores weapons by player
public:
//default constructor
players();
//setters
void enterPlayerNames();
void setPlayerFullness(int index, int value);
void removePlayer(int i);
void setWeaponsArray(int i, string weapon);
//getters
string getPlayerNames(int i);
int getPlayerFullness(int i);
int getNumPlayers();
string getWeaponsArray(int i);
};

#endif