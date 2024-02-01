#include "statusUpdate.h"
#include "inventory.h"

#include <iostream>

using namespace std;

/*
Algorithm:
1. Display the # Rooms cleared, keys found and anger level.
2. Display the inventory
3. Display the party members and their fullness levels
*/
void statusUpdate::displayStatusUpdate(inventory &i, Map &m, players &p){
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << 5-m.getRoomCount() << " | Keys: " << i.getNumKeysFound() << " | Anger Level: " << i.getAngerLevel() << endl;
   i.displayInventory();
   cout << "+-------------+" << endl;
   cout << "| PARTY       |" << endl;
   cout << "+-------------+" << endl;
    for(int i = 0; i < p.getNumPlayers(); i++){
        cout << "| " << p.getPlayerNames(i) << " | Fullness: " << p.getPlayerFullness(i) << endl;
    }
   cout << "+-------------+" << endl;
}