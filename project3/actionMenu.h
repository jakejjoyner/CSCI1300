#ifndef ACTIONMENU_H

#include <iostream>
#include "inventory.h"
#include "map.h"

using namespace std;

class actionMenu
{
public:
//investigate current space
    void investigate(inventory &i, Map &m);
};

#endif