#include "actionMenu.h"
#include <ctime>
#include <cstdlib>

#include <iostream>

using namespace std;

/*
Algorithm:
1. mark space as explored
2. 10% chance of finding a key
3. 20% chance of finding a treasure (kind of treasure depends on how many rooms cleared)
*/
void actionMenu::investigate(inventory &i, Map &m){
    m.exploreSpace(m.getPlayerRow(),m.getPlayerCol());
    srand(time(0));
    if (rand() % 100 < 10){
        i.setNumKeys(i.getNumKeysFound() + 1);
    }
    if(rand() %  100 < 20){
        if(m.getRoomCount() == 4){
            i.setNumSilverRings(i.getNumSilverRings() + 1);
        }
        if(m.getRoomCount() == 3){
            i.setNumRubyNecklaces(i.getNumRubyNecklaces() + 1);
        }
        if(m.getRoomCount() == 2){
            i.setNumEmeraldBracelets(i.getNumEmeraldBracelets() + 1);
        }
        if(m.getRoomCount() == 1){
            i.setNumDiamondCirclets(i.getNumDiamondCirclets() + 1);
        }
        if(m.getRoomCount() == 0){
            i.setNumGemEncrustedGoblets(i.getNumGemEncrustedGoblets() + 1);
        }
    }
}