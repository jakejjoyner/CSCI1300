#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game.h"
#include <fstream>

using namespace std;

//default constructor
game::game(){
    srand(time(0));
    m.resetMap();
    i = inventory();
    p = players();
    for(int i = 0; i < 21; i++){
        monsters_[i] = monsters();
    }
    give_up = 0;
    is_sorcerer_defeated = 0;
    turns_elapsed = 0;
    explored_spaces = 0;
    monsters_defeated = 0;
}

//return give_up
int game::giveUp(){
    return give_up;
}
//  he;;lp esaedkpjf elwkfjelkjwfncdewlrjkfh erwkjinfjerw fn  eiwsht  ha tghs4ngf 

// amy nam4e is jakob joynerrryyyrrrrrrrrrrrr  I like airplanbes and cars and i like my shitbox maza speeeeeeeeeeddddddddddddddd and i watch clarksons \ farm weith joshjua zayne berry and marcus david michel and thew farm goes brrrr and kaleb is a living fetus and geralds speaks northern in doneisan dialect .                 fi
/*
Algorithm:
1. Open file "results.txt"
2. Print remaining players and fullness levels to terminal and to file
3. Print # rooms cleared to terminal and file
4. Print # gold pieces remaining to terminal and file
5. Print treasure items in inventory to terminal and file
6. Print number of explored spaces to terminal and file
7. Print number of monsters defeated to terminal and file
8. Print number of turns elapsed to terminal and file
9. Print message expressing regret that the player didn't make it top the end of the dungeon to terminal and file
*/
void game::gameEnd(){
    cout << "Here are some stats from your game. They have also been printed to results.txt." << endl;
    ofstream fout;
    fout.open("results.txt");
    cout << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    for(int i = 0; i < p.getNumPlayers(); i++){
        cout << "| " << p.getPlayerNames(i) << " | Fullness: " << p.getPlayerFullness(i) << endl;
    }
    cout << "+-------------+" << endl;


    fout << endl;
    fout << "+-------------+" << endl;
    fout << "| PARTY       |" << endl;
    fout << "+-------------+" << endl;
    for(int i = 0; i < p.getNumPlayers(); i++){
        fout << "| " << p.getPlayerNames(i) << " | Fullness: " << p.getPlayerFullness(i) << endl;
    }
    fout << "+-------------+" << endl;

    cout << "Rooms Cleared: " << 5-m.getRoomCount() << endl;
    fout << "Rooms Cleared: " << 5-m.getRoomCount() << endl;

    cout << "Gold Pieces Remaining: " << i.getNumGold() << endl;
    fout << "Gold Pieces Remaining: " << i.getNumGold() << endl;

    cout << "Treasure items in inventory: " << i.getNumTreasures() << endl;
    fout << "Treasure items in inventory: " << i.getNumTreasures() << endl;

    cout << "Number of explored spaces: " << explored_spaces << endl;
    fout << "Number of explored spaces: " << explored_spaces << endl;

    cout << "Number of monsters defeated: " << monsters_defeated << endl;
    fout << "Number of monsters defeated: " << monsters_defeated << endl;

    cout << "Number of turns elapsed: " << turns_elapsed << endl;
    fout << "Number of turns elapsed: " << turns_elapsed << endl;

    cout << endl;
    fout << endl;

    cout << "Sorry to see you go, " << p.getPlayerNames(0) << "! Better luck next time!" << endl;
    fout << "Sorry to see you go, " << p.getPlayerNames(0) << "! Better luck next time!" << endl;
}
/*
Algorithm:
1. Open file "results.txt"
2. Print remaining players and fullness levels to terminal and to file
3. Print # rooms cleared to terminal and file
4. Print # gold pieces remaining to terminal and file
5. Print treasure items in inventory to terminal and file
6. Print number of explored spaces to terminal and file
7. Print number of monsters defeated to terminal and file
8. Print number of turns elapsed to terminal and file
*/
void game::youWon(){
    cout << "Here are some stats from your game. They have also been printed to results.txt." << endl;
    ofstream fout;
    fout.open("results.txt");
    cout << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    for(int i = 0; i < p.getNumPlayers(); i++){
        cout << "| " << p.getPlayerNames(i) << " | Fullness: " << p.getPlayerFullness(i) << endl;
    }
    cout << "+-------------+" << endl;


    fout << endl;
    fout << "+-------------+" << endl;
    fout << "| PARTY       |" << endl;
    fout << "+-------------+" << endl;
    for(int i = 0; i < p.getNumPlayers(); i++){
        fout << "| " << p.getPlayerNames(i) << " | Fullness: " << p.getPlayerFullness(i) << endl;
    }
    fout << "+-------------+" << endl;

    cout << "Rooms Cleared: " << 5-m.getRoomCount() << endl;
    fout << "Rooms Cleared: " << 5-m.getRoomCount() << endl;

    cout << "Gold Pieces Remaining: " << i.getNumGold() << endl;
    fout << "Gold Pieces Remaining: " << i.getNumGold() << endl;

    cout << "Treasure items in inventory: " << i.getNumTreasures() << endl;
    fout << "Treasure items in inventory: " << i.getNumTreasures() << endl;

    cout << "Number of explored spaces: " << explored_spaces << endl;
    fout << "Number of explored spaces: " << explored_spaces << endl;

    cout << "Number of monsters defeated: " << monsters_defeated << endl;
    fout << "Number of monsters defeated: " << monsters_defeated << endl;

    cout << "Number of turns elapsed: " << turns_elapsed << endl;
    fout << "Number of turns elapsed: " << turns_elapsed << endl;
}
/*
Algorithm:
1. Set random number generator starting point to the time at 0
2. Add rooms at random points in the map until max_rooms has been reached
3. Add NPC spaces at random points in the map until max_num_NPCs has been reached
4. Display the start menu
5. Display the merchant menu
6. Display the map
7. Display the action menu
*/
void game::startGame(){
    srand(time(0));
    for(int i = 0; i < 5; i++){
        m.addRoom(rand() % 11,rand() % 11);
    }
    for(int i = 0; i < 5; i++){
        m.addNPC(rand() % 11, rand() % 11);
    }
    s.displayStartMenu(p);
    mm.displayMerchantMenu(i,m,p);
    su.displayStatusUpdate(i,m,p);
    m.displayMap();
    actionMenuDriver();
}
/*
Algorithm:
1. Display status update
2. Display the ma
3. Display the action menu
*/
void game::newTurn(){
    su.displayStatusUpdate(i,m,p);
    m.displayMap();
    actionMenuDriver();
}

//split function
int split(string input_string, char separator, string arr[], int arr_size){
    int x = 0;//initialize variables
    int start_of_string = 0;
    int end_of_string = 0;
    int length;
if(input_string == ""){
    return 0;//test that function exists
}
int input_stringLength = input_string.length();
   while(end_of_string<=input_stringLength){//while loop to iterate through array and split it at instances of the separator
    if(x==arr_size){//return -1 if number of sep are equal to array size
               return -1;
          }
    if(end_of_string == input_stringLength){
        arr[x++] = input_string.substr(start_of_string,end_of_string);
        return x;
    }
    else if (input_string[end_of_string] == separator){
        length = end_of_string - start_of_string;//calculates length of the string that will be split
           if(x==arr_size){//return -1 if number of sep are equal to array size
               return -1;
          }
        arr[x++] = input_string.substr(start_of_string,length);//if the new array at x plus 1 equals the input string at the start
        end_of_string++;//increments the end of string variable by one and
        start_of_string=end_of_string;//set start = end
    }
    else{
        end_of_string++;//if does not encounter sep increment the end variable
     }
    }
    if(x == arr_size){
        return -1; //return -1 if number of sep are equal to array size
    }
    arr[x++] = input_string.substr(start_of_string,length);
    return x; //return number of splits
}

/*
Algorithm:
1. Store monsters in an aray of monster objects
2. Set random number generator starting point to the time at 0
3. Initialize and declare variables for calculating battle outcome
4. Check the amount of rooms that have been cleared, and set the challenge rating and monsters that the player will be fighting (which corresponds to the amount of rooms cleared)
5. Tell the player that there is a monster ahead and ask whether they would like to fight or surrender
6. If they surrender, remove a team member at random (excluding the player.) [There is also a 50% chance for the player and each team member to lose one fullness point]
7. If they chose to fight:
    If they win the fight (based on the calculation made), print a message saying that they won and the amount of gold/ingredients that 
    the monster dropped + set the gold/ing. to the apropriate amounts
        If they find a key, increment the number of keys they have and print a message saying that they found a key
        Set the challenge rating of the monster they fought to zero, so that they won't fight that monster again
    If the lose the fight (based on calculation made), print a message saying that they lost
        Check whether the player has any gold or more than 10kg of ingredients and take away 10kg of ingredients and 25% of their gold based on if they have any gold/ingredients
        Open the file that stores the amount of armor that the player owns
            If the players have armor on, they each indepentendly have a 5% chance of dying
            If they don't have armor on, they each have a 10% chance of dying
8. If they don't have enough weapons to fight, the team will automatically be surrendered, 
a team member will be removed at random, and there will be a 50% chance for each team member + the player to lose one fullness point
9. Return 1 if the player won and 0 if they lost
*/
bool game::fightMonster(){
    ifstream file_input;
    file_input.open("monsters.txt");
    string line = "";
    string arr[50];
    int index = 0;
    
    while(!file_input.eof()){
        getline(file_input,line);
        split(line, ',',arr,2);
        if(line.length() != 0){
            string monster_name = arr[0];
            int challenge_rating = stoi(arr[1]);
            monsters_[index] = monsters(monster_name, challenge_rating);
            index++;
        }
    }
file_input.close();

    srand(time(0));
    int num_weapons = i.getNumWeapons();
    int w = i.getNumWeapons();
    int d = 4;
    int a = i.getNumArmour()+1;
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;
    for(int j = 0; j < i.getNumWeapons(); j++){
        for(int k = 0; k < i.getNumWeapons() - 1; k++)
            if(p.getWeaponsArray(j) == p.getWeaponsArray(k) && j != k){
                d = 0;
            }
    }
    for(int j = 0; j < i.getNumWeapons(); j++){
        if(p.getWeaponsArray(j) == "longsword"){
            w += 3;
        }
        if(p.getWeaponsArray(j) == "axe"){
            w += 2;
        }
        if(p.getWeaponsArray(j) == "rapier"){
            w += 1;
        }
    }

    if(m.getRoomCount() == 5){
        int x = rand() % 3;
        while(monsters_[x].getChallengeRating() == 0){
            x = rand() % 3;
        }
        int c = 1;
        int f = (r1 * w + d) - ((r2 * c)/a);

            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }

    if(m.getRoomCount() == 4){
        int x = rand() % (8-4) + 4;
        while(monsters_[x].getChallengeRating() == 0){
            x = rand() % (8-4) + 4;
        }
        int c = 2;
        int f = (r1 * w + d) - ((r2 * c)/a);
            
            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }

    if(m.getRoomCount() == 3){
        int x = rand() % (12 - 8) + 8;
        while(monsters_[x].getChallengeRating() == 0){
            x = rand() % (12 - 8) + 8;
        }
        int c = 3;
        int f = (r1 * w + d) - ((r2 * c)/a);

            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }
    
    if(m.getRoomCount() == 2){
        int x = rand() % (16-12) + 12;
        while(monsters_[x].getChallengeRating() == 0){
            x = rand() % (16-12) + 12;
        }
        int c = 4;
        int f = (r1 * w + d) - ((r2 * c)/a);

            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }

    if(m.getRoomCount() == 1){
        int x = rand() % (20-16) + 16;
        while(monsters_[x].getChallengeRating() == 0){
            x = rand() % (20-16) + 16;
        }
        int c = 5;
        int f = (r1 * w + d) - ((r2 * c)/a);

            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }

    if(m.getRoomCount() >= 0){
        int x = 20;
        while(monsters_[x].getChallengeRating() == 0){
            x = 20;
        }
        int c = 6;
        int f = (r1 * w + d) - ((r2 * c)/a);

            cout << monsters_[x].getMonsterName() << " ahead! THEY LOOK HOSTILE!" << endl;
            string user_input;
                cout << "Would you like to fight, or surrender? (write fight to fight, and surrender to surrender)" << endl;
                cout << "> ";
                cin >> user_input;
                while(user_input != "surrender" && user_input != "fight"){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                if(user_input == "surrender"){
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(i.getNumWeapons() < 1){
                    cout << "You don't have enough weapons to fight! You will automatically surrender." << endl;
                    int y = rand() % (p.getNumPlayers() - 1) + 1;
                    p.removePlayer(y);
                    cout << p.getPlayerNames(y) << " has been slain by the " << monsters_[x].getMonsterName() << endl;
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                    return 0;
                }
                if(user_input == "fight" && i.getNumWeapons() >= 1){
                    if(f > 0){
                        cout << "You won! The " << monsters_[x].getMonsterName() << " dropped " << 10 * c << " gold pieces and " << 5 * c << " ingredients." << endl;
                        monsters_[x].setChallengeRating(0);
                        if((rand() % 100) < 10){
                            cout << "You also found a key!" << endl;
                            i.setNumKeys(i.getNumKeysFound() + 1);
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        i.setNumIngredients(5*c + i.getNumIngredients());
                        i.setNumGold(10*c + i.getNumGold());
                        return 1;
                    }
                    if(f <= 0){
                        cout << "You lost ;(." << endl;
                        int gold_taken = i.getNumGold()*0.25;
                        if(i.getNumIngredients() <= 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25); 
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() <= 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took 10kg of your ingredients." << endl;
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                        if(i.getNumIngredients() > 0 && i.getNumGold() > 0){
                            cout << "The " << monsters_[x].getMonsterName() << " took " << gold_taken << " gold from you and 10kg of your ingredients." << endl;
                            i.setNumGold(i.getNumGold() - i.getNumGold() * 0.25);
                            i.setNumIngredients(i.getNumIngredients() - 10);
                        }
                            ifstream file_input2;
                            file_input2.open("armor.txt");
                            string line = "";
                            int playerIndex = 1;
                            while(playerIndex < p.getNumPlayers() && !file_input2.eof()){
                            getline(file_input2,line);
                            if(line.length() != 0){
                            if(line == "1"){
                                    if(rand() % 100 < 5){
                                        cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                                        p.removePlayer(playerIndex);
                                    }
                                }
                            }
                            playerIndex++;
                        }
                        while(playerIndex < p.getNumPlayers()){
                            if(rand() % 100 < 10){
                            cout << p.getPlayerNames(playerIndex) << " has been slain by the " << monsters_[x].getMonsterName() << "!" << endl;
                            p.removePlayer(playerIndex);
                            }
                            playerIndex++;
                        }
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            if(rand() % 100 < 50){
                                p.setPlayerFullness(j,p.getPlayerFullness(j)-1);
                            }
                        }
                        return 0;
                    }
            }
    }
return 0;
}

/*
Algorithm:
1. Set random number generator starting point to the time at 0
2. Increment the number of turns elapsed
3. Infinite loop
    If the player's or any of the team members' fullness levels drop below 5, print a message letting the player know
    if any of the team members' fullness drops to 0
        print a message telling them that they died of starvation
    If the player dies from hunger
        print a message letting them know and set give_up to 1, so that the gameEnd menu can be displayed
        return
    If all of the player's team members die
        print a message saying that the player must have at least one team mate, and set give_up to 1 to display the gameEnd menu
        return
    If the space that the player is currently on is not marked as explored, increment the sorcerer's anger level
    If the sorcerer's anger level reaches 100, print a message letting the player know what happened, set give_up to 1, and return
    If the player is on a 'free space':
        Print a menu (for free space actions) asking the player what they would like to do
        Ask for user inputs, depending on which option the player picked
        When the player is done giving inputs, return
    If the player is on an 'NPC space':
        Print a menu (for NPC space actions) asking the player what they would like to do
        Ask for user inputs, depending on which option the player picked
        When the player is done giving inputs, return
    If the player is on a 'room space':
        Print a menu (for room space actions) asking the player what they would like to do
        Ask for user inputs, depending on which option the player picked
        When the player is done giving inputs, return
    If the player is at the dungeon exit and has cleared all 5 rooms:
        Print a message saying that they won, and set give_up to 2 so that youWon will be displayed
    If the player is at the dungeon exit but hasn't cleared all 5 rooms
        Print a message saying that they should come back when they've cleared all five rooms
        Display the move menu
*/
void game::actionMenuDriver(){
    turns_elapsed++;
    for(;;){
    srand(time(0));
    for(int j = 1; j < p.getNumPlayers(); j++){
        if(p.getPlayerFullness(j) <= 5){
            cout << "Warning: " << p.getPlayerNames(j) << " is on the brink of starvation!" << endl;
            cout << "You should cook and eat some food!" << endl;
        }
        if(p.getPlayerFullness(j) == 0){
            cout << "Oh No! " << p.getPlayerNames(j) << " has died of hunger!" << endl;
            p.removePlayer(j);
            cout << "Your party size has been reduced to " << p.getNumPlayers() << " players." << endl;
        }
    }
    if(p.getPlayerFullness(0) <= 5){
        cout << "Warning: You are on the brink of starvation!" << endl;
        cout << "You should cook some food!" << endl;
    }
    if(p.getPlayerFullness(0) == 0){
        cout << "You died from hunger!" << endl;
        give_up = 1;
        return;
    }
    if(p.getNumPlayers() <= 1){
        cout << "All of your traveling companions have died! You can't continue the journey alone!" << endl;
        cout << "Better luck next time!" << endl;
        cout << endl;
        give_up = 1;
        return;
    }
    if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
        if(is_sorcerer_defeated == 0){
            i.setAngerLevel(i.getAngerLevel() + 1);
        }
    }
    if(i.getAngerLevel() >= 100){
        cout << "The sorcerer has destroyed the entire dungeon, with your party trapped inside!" << endl;
        cout << "You lose! (Next time don't let the sorcerer's anger level reach 100 ;))" << endl;
        give_up = 1;
        return;
    }
    if(m.isFreeSpace(m.getPlayerRow(),m.getPlayerCol())){
        string choice;
        cout << "Select One:" << endl;
        cout << "1. Move" << endl;
        cout << "2. Investigate" << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat" << endl;
        cout << "5. Give up" << endl;
        cout << "> ";
        cin >> choice;

        while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5"){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> choice;
        }

        if(choice == "1"){
            char user_input;
            cout << "Use w, a, s, and d to move" << endl;
            cout << "Press 0 to exit the move menu." << endl;
            for(;;){
            srand(time(0));
            cout << "> "; 
            cin >> user_input;
            while(user_input != 'w' && user_input != 'a' && user_input != 's' && user_input != 'd' && user_input != '0'){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input;
            }
            if(user_input == '0'){
                return;
            }
            m.move(user_input);
            m.displayMap();
            for(int j = 0; j < p.getNumPlayers(); j++){
                if(rand() % 100 < 20){
                    p.setPlayerFullness(j,p.getPlayerFullness(j) - 1);
                }
            }
    if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
        if(is_sorcerer_defeated == 0){
            i.setAngerLevel(i.getAngerLevel() + 1);
        }
    }
        }
        }
        if(choice == "2"){
            if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
                a.investigate(i,m);
                explored_spaces++;
                if(rand() % 100 < 20){
                    if(is_sorcerer_defeated == 0){
                        if(fightMonster()){
                            monsters_defeated++;
                        }
                        return;
                    }
                }
                for(int j = 0; j < p.getNumPlayers(); j++){
                if(rand() % 100 < 50){
                    p.setPlayerFullness(j,p.getPlayerFullness(j) - 1);
                }
            }
            return;
            }
            if(m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
                cout << "This space has already been explored. Please pick a different option." << endl;
            }
        }
        if(choice == "3"){
            if(is_sorcerer_defeated == 0){
                if(fightMonster()){
                    monsters_defeated++;
                }
                return;
            }
            if(is_sorcerer_defeated == 1){
                cout << "You've already defeated the sorcerer! You can't fight monsters anymore." << endl;
                return;
            }
        }
        if(choice == "4"){
            string user_input;
            cout << "Which cookware item would you like to use?" << endl;
            cout << "1. Ceramic Pot [25% chance of breaking]" << endl;
            cout << "2. Frying Pan [10% chance of breaking]" << endl;
            cout << "3. Cauldron [2% chance of breaking]" << endl;
            cout << "> ";
            cin >> user_input;
            int user_input2;
            cout << "How many ingredients would you like to use? (enter in increments of 5kg)" << endl;
            cout << "> ";
            cin >> user_input2;
            while((user_input2 % 5) && user_input2 <= 0){
                cout << "Please enter a valid input" << endl;
                cout << "> ";
                cin >> user_input2;
            }
            while(user_input != "1" && user_input != "2" && user_input != "3"){
                cout << "Plese enter a valid input." << endl;
                cout << "> ";
                cin >> user_input;
            }
            if(user_input == "1" && !(user_input2 % 5) && user_input2 > 0){
                if(i.getNumCeramicPots() > 0 && i.getNumIngredients() > 0){
                    if(rand() % 100 < 25){
                        cout << "Oh no! Your ceramic pot broke!" << endl;
                        i.setNumCeramicPots(i.getNumCeramicPots() - 1);
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                    }
                    else{
                        int FullnessPerPlayer = user_input2 / p.getNumPlayers();
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            p.setPlayerFullness(j,p.getPlayerFullness(j) + FullnessPerPlayer);
                        }
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                        cout << "Your cook was succesful!" << endl;
                    }
                    return;
                }
                else if(i.getNumCeramicPots() <= 0 && i.getNumIngredients() >= user_input2){
                    cout << "You don't own any Ceramic Pots!" << endl;
                    return;
                }
                else if(i.getNumIngredients() < user_input2 && i.getNumCeramicPots() > 0){
                    cout << "You don't have enough ingredients!"<< endl;
                    return;
                }
                else if(i.getNumIngredients() < user_input2 && i.getNumCeramicPots() <= 0){
                    cout << "You don't enough ingredients or ceramic pots!" << endl;
                    return;
                }
            }
            if(user_input == "2" && !(user_input2 % 5) && user_input2 > 0){
                if(i.getNumFryingPans() > 0 && i.getNumIngredients() > 0){
                    if(rand() % 100 < 10){
                        cout << "Oh no! Your frying pan broke!" << endl;
                        i.setNumFryingPans(i.getNumFryingPans() - 1);
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                    }
                    else{
                        int FullnessPerPlayer = user_input2 / p.getNumPlayers();
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            p.setPlayerFullness(j,p.getPlayerFullness(j) + FullnessPerPlayer);
                        }
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                        cout << "Your cook was succesful!" << endl;
                    }
                    return;
                }
                else if(i.getNumFryingPans() <= 0 && i.getNumIngredients() > 0){
                    cout << "You don't own any frying pans!" << endl;
                    return;
                }
                else if(i.getNumIngredients() <= 0 && i.getNumFryingPans() > 0){
                    cout << "You don't have any ingredients!"<< endl;
                    return;
                }
                else if(i.getNumIngredients() <= 0 && i.getNumFryingPans() <= 0){
                    cout << "You don't have any ingredients or frying pans!" << endl;
                    return;
                }
            }
            if(user_input == "3" && !(user_input2 % 5) && user_input2 > 0){
                if(i.getNumCauldrons() > 0 && i.getNumIngredients() > 0){
                    if(rand() % 100 < 2){
                        cout << "Oh no! Your frying pan broke!" << endl;
                        i.setNumCauldrons(i.getNumCauldrons() - 1);
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                    }
                    else{
                        int FullnessPerPlayer = user_input2 / p.getNumPlayers();
                        for(int j = 0; j < p.getNumPlayers(); j++){
                            p.setPlayerFullness(j,p.getPlayerFullness(j) + FullnessPerPlayer);
                        }
                        i.setNumIngredients(i.getNumIngredients() - user_input2);
                        cout << "Your cook was succesful!" << endl;
                    }
                    return;
                }
                else if(i.getNumCauldrons() <= 0 && i.getNumIngredients() > 0){
                    cout << "You don't own any frying pans!" << endl;
                    return;
                }
                else if(i.getNumIngredients() <= 0 && i.getNumCauldrons() > 0){
                    cout << "You don't have any ingredients!"<< endl;
                    return;
                }
                else if(i.getNumIngredients() <= 0 && i.getNumCauldrons() <= 0){
                    cout << "You don't have any ingredients or frying pans!" << endl;
                    return;
                }
            }
        }
        if(choice == "5"){
            give_up = 1;
            return;
        }
    }
    if(m.isNPCLocation(m.getPlayerRow(),m.getPlayerCol())){
        string choice;
        cout << "Select One:" << endl;
        cout << "1. Move" << endl;
        cout << "2. Speak to NPC" << endl;
        cout << "3. Give Up" << endl;
        cout << "> ";
        cin >> choice;

        while(choice != "1" && choice != "2" && choice != "3"){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> choice;
        }
        if(choice == "1"){
            char user_input;
            cout << "Use w, a, s, and d to move" << endl;
            cout << "Press 0 to exit the move menu." << endl;
            for(;;){
            srand(time(0));
            cout << "> "; 
            cin >> user_input;
            while(user_input != 'w' && user_input != 'a' && user_input != 's' && user_input != 'd' && user_input != '0'){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input;
            }
            if(user_input == '0'){
                return;
            }
            m.move(user_input);
            m.displayMap();
            for(int j = 0; j < p.getNumPlayers(); j++){
                if(rand() % 100 < 20){
                    p.setPlayerFullness(j,p.getPlayerFullness(j) - 1);
                }
            }
    if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
        if(is_sorcerer_defeated == 0){
            i.setAngerLevel(i.getAngerLevel() + 1);
        }
    }
        }
        }
        if(choice == "2"){
            cout << "You must solve this riddle if you want to talk with me." << endl;
            string user_input;
            ifstream file_input;
            string arr[50];
            file_input.open("riddles.txt");
            string line = "";
            int riddleIndex = (rand() % 19);
            int answerIndex = riddleIndex + 1;
            int index = 0;
            while(!file_input.eof()){
                getline(file_input,line);
                split(line,'~',arr,2);
                if(index == riddleIndex){
                    cout << arr[0] << endl;
                    cout << "> ";
                    cin >> user_input;
                    string user_input1;
                    string ans = arr[1].substr(0,arr[1].length()-1);
                    if(user_input != ans){
                        if(is_sorcerer_defeated == 0){
                            cout << "Incorrect! This monster will teach you not to waste my time in the future!" << endl;
                            if(fightMonster() == 1){
                                monsters_defeated++;
                            }
                        }
                        if(is_sorcerer_defeated == 1){
                            cout << "Incorrect!" << endl;
                        }
                        m.exploreSpace(m.getPlayerRow(),m.getPlayerCol());
                        explored_spaces++;
                        return;
                            }
                    if(user_input == ans){
                        cout << "Nice job!" << endl;
                        cout << "Do you wish to buy some goods from me? (0 for yes, and 1 for no)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                        while(user_input1 != "0" && user_input1 != "1"){
                            cout << "Please enter a valid input." << endl;
                            cout << "> ";
                            cin >> user_input1;
                        }
                        if(user_input1 == "0"){
                            mm.displayMerchantMenu(i,m,p);
                            m.exploreSpace(m.getPlayerRow(),m.getPlayerCol());
                            explored_spaces++;
                            return;
                        }
                        if(user_input1 == "1"){
                            cout << "Goodbye!" << endl;
                            m.exploreSpace(m.getPlayerRow(),m.getPlayerCol());
                            explored_spaces++;
                            return;
                        }
                    }
                    }
                index++;
        }
    }
        if(choice == "3"){
            give_up = 1;
            return;
        }
    }
    if(m.isRoomLocation(m.getPlayerRow(),m.getPlayerCol())){
        string choice;
        cout << "Select One:" << endl;
        cout << "1. Move" << endl;
        cout << "2. Open the Door" << endl;
        cout << "3. Give Up" << endl;
        cout << "> ";
        cin >> choice;

        while(choice != "1" && choice != "2" && choice != "3"){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> choice;
        }
        if(choice == "1"){
            char user_input;
            cout << "Use w, a, s, and d to move" << endl;
            cout << "Press 0 to exit the move menu." << endl;
            for(;;){
            srand(time(0));
            cout << "> "; 
            cin >> user_input;
            while(user_input != 'w' && user_input != 'a' && user_input != 's' && user_input != 'd' && user_input != '0'){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input;
            }
            if(user_input == '0'){
                return;
            }
            m.move(user_input);
            m.displayMap();
            for(int j = 0; j < p.getNumPlayers(); j++){
                if(rand() % 100 < 20){
                    p.setPlayerFullness(j,p.getPlayerFullness(j) - 1);
                }
            }
    if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
        if(is_sorcerer_defeated == 0){
            i.setAngerLevel(i.getAngerLevel() + 1);
        }
    }
        }
        }
        if(choice == "2"){
            for(;;){
            if(i.getNumKeysFound() > 0){
                m.setRoomCount(m.getRoomCount() - 1);
                if(!fightMonster()){
                    m.setRoomCount(m.getRoomCount() + 1);
                    i.setNumKeys(i.getNumKeysFound()-1);
                    if(rand() % 100 < 40){
                        misfortune();
                        if(rand() % 100 < 30){
                            int player = rand() % (p.getNumPlayers() - 1) + 1;
                            cout << "Oh No! Your teammate " << p.getPlayerNames(player) << " is trapped in the previous room and is unable to get through! You must continue without them." << endl;
                            cout << endl;
                            p.removePlayer(player);
                            if(p.getNumPlayers() == 1){
                                cout << "You don't have enough players to complete the journey!" << endl;
                                cout << "Better luck next time!" << endl;
                                give_up = 1;
                            }
                            else{
                                cout << "Your party size has been reduced to " << p.getNumPlayers() << " members." << endl;
                            }
                        }
                    }
                return;
                }
                else{
                    monsters_defeated++;
                    i.setNumKeys(i.getNumKeysFound() - 1);
                    if(rand() % 100 < 60){
                        misfortune();
                        if(rand() % 100 < 30){
                            int player = rand() % (p.getNumPlayers() - 1) + 1;
                            cout << "Oh No! Your teammate " << p.getPlayerNames(player) << " is trapped in the previous room and is unable to get through! You must continue without them." << endl;
                            cout << endl;
                            p.removePlayer(player);
                            if(p.getNumPlayers() == 1){
                                cout << "You don't have enough players to complete the journey!" << endl;
                                cout << "Better luck next time!" << endl;
                                give_up = 1;
                            }
                            else{
                            cout << "Your party size has been reduced to " << p.getNumPlayers() << " members." << endl;
                            cout << endl;
                            }
                        }
                    }
                    m.setRoomCount(m.getRoomCount() + 1);
                    m.removeRoom(m.getPlayerRow(),m.getPlayerCol());
                    if(m.getRoomCount() == 0){
                        cout << "You defeated the sorcerer!" << endl;
                        cout << "There will be no additional monster encounters and the sorcerer's anger will no longer increase." << endl;
                        is_sorcerer_defeated = 1;
                    }
                    return;
                }
                return;
            }
            if(i.getNumKeysFound() <= 0){
                cout << "You don't have a key to this room!" << endl;
                cout << "If you can solve my puzzle, I'll let you through. If you can't solve it in three tries, I'll take one of your own!!" << endl;
                cout << endl;
                cout << "We will be playing a game of Boulder/Parchment/Shears." << endl;
                int remainingTries = 3;
                for(;;){
                cout << "Pick one of the following:" << endl;
                cout << "1. Boulder" << endl;
                cout << "2. Parchment" << endl;
                cout << "3. Shears" << endl;
                int user_input;
                cout << "> ";
                cin >> user_input;
                while(user_input > 3 && user_input < 1){
                    cout << "Please enter a valid input." << endl;
                    cout << "> ";
                    cin >> user_input;
                }
                int x = rand() % 3 + 1;
                if(x == user_input){
                    cout << "We tied!" << endl;
                    cout << "Let's play again." << endl;
                }
                if(remainingTries == 0){
                    int player = rand() % (p.getNumPlayers() - 1) + 1;
                    cout << "You're out of tries! " << p.getPlayerNames(player) << " is mine!!" << endl;
                    p.removePlayer(player);
                    return;
                }
                if(x == 2 && user_input == 1){
                    cout << "You lost! You have " << remainingTries << " remaining tries to beat me." << endl;
                    remainingTries--;
                }
                if(x == 1 && user_input == 3){
                    cout << "You lost! You have " << remainingTries << " remaining tries to beat me." << endl;
                    remainingTries--;
                }
                if(x == 3 && user_input == 2){
                    cout << "You lost! You have " << remainingTries << " remaining tries to beat me." << endl;
                    remainingTries--;
                }
                if(x == 1 && user_input == 2){
                    cout << "You Won!" << endl;
                    i.setNumKeys(1);
                    break;
                }
                if(x == 3 && user_input == 1){
                    cout << "You Won!" << endl;
                    i.setNumKeys(1);
                    break;
                }
                if(x == 2 && user_input == 3){
                    cout << "You Won!" << endl;
                    i.setNumKeys(1);
                    break;
                }
            }
            }
        }
        return;
    }
        if(choice == "3"){
            give_up = 1;
            return;
        }
    }

    if(m.isDungeonExit(m.getPlayerRow(),m.getPlayerCol()) && m.getRoomCount() == 0)
    {
        cout << "You won!" << endl;
        cout << endl;
            give_up = 2;
            return;
    }
    if(m.isDungeonExit(m.getPlayerRow(),m.getPlayerCol()))
    {
        cout << "You haven't cleared all five rooms yet! Come back when you have defeated the sorcerer and cleared all five rooms." << endl;
            char user_input;
            cout << "Use w, a, s, and d to move" << endl;
            cout << "Press 0 to exit the move menu." << endl;
            for(;;){
            srand(time(0));
            cout << "> "; 
            cin >> user_input;
            while(user_input != 'w' && user_input != 'a' && user_input != 's' && user_input != 'd' && user_input != '0'){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input;
            }
            if(user_input == '0'){
                return;
            }
            m.move(user_input);
            m.displayMap();
            for(int j = 0; j < p.getNumPlayers(); j++){
                if(rand() % 100 < 20){
                    p.setPlayerFullness(j,p.getPlayerFullness(j) - 1);
                }
            }
            if(!m.isExplored(m.getPlayerRow(),m.getPlayerCol())){
                if(is_sorcerer_defeated == 0){
                    i.setAngerLevel(i.getAngerLevel() + 1);
        }
    }
}

        }
    }
}

/*
Algorithm:
1. Set random number generator starting point to the time at 0
2. There is a 30% chance of the team being robbed by dungeon bandits
3. 10% chance of one of the team's weapons breaking
4. 30% chance of a player getting food poisoning and losing 10 fullness points
*/
void game::misfortune(){
    srand(time(0));
    if(rand() % 100 < 30){
        cout << "Oh No! Your team was robbed by dungeon bandits!" << endl;
        cout << endl;
        int x = rand() % 3 + 1;
        if(i.getNumCookware() <= 0){
            x = 2;
        }
        if(i.getNumIngredients() < 10){
            x = 3;
        }
        if(i.getNumArmour() <= 0){
            x = 1;
        }
        if(x == 1 && i.getNumCookware() > 0){
            int y = rand() % 3 + 1;
            if(i.getNumCeramicPots() <= 0){
                y = 2;
            }
            if(i.getNumFryingPans() <= 0){
                y = 3;
            }
            if(y == 1 && i.getNumCeramicPots() > 0){
                cout << "You lost one ceramic pot!" << endl;
                cout << endl;
                i.setNumCeramicPots(i.getNumCeramicPots() - 1);
            }
            if(y == 2 && i.getNumFryingPans() > 0){
                cout << "You lost one frying pan!" << endl;
                cout << endl;
                i.setNumFryingPans(i.getNumFryingPans() - 1);
            }
            if(y == 3 && i.getNumCauldrons() > 0){
                cout << "You lost one cauldron!" << endl;
                cout << endl;
                i.setNumCauldrons(i.getNumCauldrons() - 1);
            }
        }
        if(x == 2 && i.getNumIngredients() >= 10){
            i.setNumIngredients(i.getNumIngredients() - 10);
            cout << "You lost 10kg of ingredients." << endl;
            cout << endl;
        }
        if(x == 3 && i.getNumArmour() > 0){
            i.setNumArmour(i.getNumArmour() - 1);
            cout << "You lost 1 set of armor!" << endl;
            cout << endl;
        }
    }
    if(rand() % 100 < 10){
        int x = rand() % 2 + 1;
        if(i.getNumWeapons() <= 0){
            x = 2;
        }
        if(i.getNumArmour() <= 0){
            x = 1;
        }
        if(x == 1 && i.getNumWeapons() > 0){
            int y = rand() % 5 + 1;
            if(i.getNumClubs() <= 0){
                y = 2;
            }
            if(i.getNumSpears() <= 0){
                y = 3;
            }
            if(i.getNumRapiers() <= 0){
                y = 4;
            }
            if(i.getNumBattleAxes() <= 0){
                y = 5;
            }
            if(i.getNumLongswords() <= 0){
                y = 1;
            }
            if(y == 1 && i.getNumClubs() > 0){
                i.setNumClubs(i.getNumClubs() - 1);
                cout << "Oh No! Your Club broke!" << endl;
                cout << endl;
            }
            if(y == 2 && i.getNumSpears() > 0){
                i.setNumSpears(i.getNumSpears() - 1);
                cout << "Oh No! Your Spear broke!" << endl;
                cout << endl;
            }
            if(y == 3 && i.getNumRapiers() > 0){
                i.setNumRapiers(i.getNumRapiers() - 1);
                cout << "Oh No! Your (+1) Rapier broke!" << endl;
                cout << endl;
            }
            if(y == 4 && i.getNumBattleAxes() > 0){
                i.setNumBattleAxes(i.getNumBattleAxes() - 1);
                cout << "Oh No! Your (+2) Battle Axe broke!" << endl;
                cout << endl;
            }
            if(y == 5 && i.getNumLongswords() > 0){
                i.setNumLongswords(i.getNumLongswords() - 1);
                cout << "Oh No! Your (+3) Longsword broke!" << endl;
                cout << endl;
            }
        }
        if(x == 2 && i.getNumArmour() > 0){
            i.setNumArmour(i.getNumArmour() - 1);
            cout << "Oh No! You lost a set of armor!" << endl;
            cout << endl;
        }
    }
    if(rand() % 100 < 30){
        int player = rand() % (p.getNumPlayers() - 1) + 1;
        p.setPlayerFullness(player, p.getPlayerFullness(player) - 10);
        if(p.getPlayerFullness(player) <= 0){
            cout << p.getPlayerNames(player) << " has died from starvation!" << endl;
            cout << endl;
            p.removePlayer(player);
        }
        else{
        cout << p.getPlayerNames(player) << " has food poisoning! He/She has lost 10 fullness points!" << endl;
        cout << endl;
        }
    }
}