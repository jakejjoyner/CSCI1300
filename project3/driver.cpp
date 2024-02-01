#include <iostream>
#include <cassert>

#include "actionMenu.h"
#include "statusUpdate.h"
#include "players.h"
#include "inventory.h"
#include "merchantMenu.h"
#include "map.h"

using namespace std;

int main(){
    inventory i = inventory();
    //testing inventory getters
    assert(i.getNumGold() == 100);
    assert(i.getNumIngredients() == 0);
    assert(i.getNumCeramicPots() == 0);
    assert(i.getNumFryingPans() == 0);
    assert(i.getNumCauldrons() == 0);
    assert(i.getNumClubs() == 0);
    assert(i.getNumSpears() == 0);
    assert(i.getNumRapiers() == 0);
    assert(i.getNumBattleAxes() == 0);
    assert(i.getNumLongswords() == 0);
    assert(i.getNumArmour() == 0);
    assert(i.getNumSilverRings() == 0);
    assert(i.getNumRubyNecklaces() == 0);
    assert(i.getNumEmeraldBracelets() == 0);
    assert(i.getNumDiamondCirclets() == 0);
    assert(i.getNumGemEncrustedGoblets() == 0);

    //testing inventory setters
    i.setNumArmour(1);
    i.setNumBattleAxes(1);
    i.setNumCauldrons(1);
    i.setNumCeramicPots(1);
    i.setNumClubs(1);
    i.setNumDiamondCirclets(1);
    i.setNumEmeraldBracelets(1);
    i.setNumFryingPans(1);
    i.setNumGemEncrustedGoblets(1);
    i.setNumGold(1);
    i.setNumIngredients(1);
    i.setNumLongswords(1);
    i.setNumRapiers(1);
    i.setNumSpears(1);
    i.setNumSilverRings(1);
    i.setNumRubyNecklaces(1);

    assert(i.getNumGold() == 1);
    assert(i.getNumIngredients() == 1);
    assert(i.getNumCeramicPots() == 1);
    assert(i.getNumFryingPans() == 1);
    assert(i.getNumCauldrons() == 1);
    assert(i.getNumClubs() == 1);
    assert(i.getNumSpears() == 1);
    assert(i.getNumRapiers() == 1);
    assert(i.getNumBattleAxes() == 1);
    assert(i.getNumLongswords() == 1);
    assert(i.getNumArmour() == 1);
    assert(i.getNumSilverRings() == 1);
    assert(i.getNumRubyNecklaces() == 1);
    assert(i.getNumEmeraldBracelets() == 1);
    assert(i.getNumDiamondCirclets() == 1);
    assert(i.getNumGemEncrustedGoblets() == 1);

//testing displayInventory function
i.displayInventory();

//testing player setters and getters
players p = players();

p.enterPlayerNames();
p.getPlayerNames(0);

}