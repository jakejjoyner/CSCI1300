#ifndef STATUSUPDATE_H

#include <iostream>
#include "inventory.h"
#include "map.h"
#include "players.h"

using namespace std;

class statusUpdate
{
private:

public:
void displayStatusUpdate(inventory &i, Map &m, players &p);
};

#endif