#include "players.h"

#include <iostream>
#include <vector>

using namespace std;

//default constructor
players::players(){
    for(int i = 0; i < 5; i++){
        players_.push_back("");
        fullness_.push_back(50);
        weapons_.push_back("");
    }
}

//setters
/*
Algorithm:
1. Prompt player to enter their name
    add their name to the beggining of the players vector
2. Prompt player to enter their traveling companions' names
    add their names to the rest of the vector
*/
void players::enterPlayerNames(){
    string players;
    cout << "Welcome to Dungeon Escape!" << endl;
    cout << "Please enter your name:" << endl;
    cin >> players;
    players_[0] = players;
    cout << "Please enter the names of your other four traveling companions:" << endl;
    for(int i = 1; i < 5; i++){
        cout << "Companion #" << i << ":" << endl;
        cin >> players;
        players_[i] = players;
    }
}
void players::setPlayerFullness(int index, int value){
        fullness_[index] = value;
}
void players::removePlayer(int i){
    fullness_.erase(fullness_.begin() + i);
    weapons_.erase(weapons_.begin() + i);
    players_.erase(players_.begin() + i);
}
void players::setWeaponsArray(int i, string weapon){
    weapons_[i] = weapon;
}
//getters
string players::getPlayerNames(int i){
    return players_[i];
}
int players::getPlayerFullness(int i){
    return fullness_[i];
}
int players::getNumPlayers(){
    return fullness_.size();
}
string players::getWeaponsArray(int i){
    return weapons_[i];
}