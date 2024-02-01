#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>

using namespace std;

class inventory
{
private:
    //gold/ingredients
    int num_gold_; //stores the amount of gold the player has
    int num_ingredients_; //stores the amount of ingredients the player has

    //cookware
    int num_ceramic_pots_; //stores the amount of ceramic pots a player owns
    int num_frying_pans_; //stores the amount of frying pans a player owns
    int num_cauldrons_; //stores the amount of cauldrons a player owns

    //weapons
    int num_clubs_; //stores the amount of clubs the player owns
    int num_spears_; //stores the amount of spears the player owns
    int num_rapiers_; //stores the amount of rapiers the player owns
    int num_battle_axes_; //stores the amount of battle axes the player owns
    int num_longswords_; //stores the amount of longswords the player owns
    int num_weapons_; //stores the number of weapons owned

    //armour
    int num_armour_; //stores the amount of armour sets that the player owns

    //Treasures
    int num_silver_rings_; //stores the amount of silver rings that the player owns
    int num_ruby_necklaces_; //stores the amount of ruby necklaces that the player owns
    int num_emerald_bracelets_; //stores the amount of emerald bracelets that the player owns
    int num_diamond_circlets_; //stores the amount of diamond circlets that the player owns
    int num_gem_encrusted_goblets_; //stores the amount of gem-encrusted goblets that the player owns

    //status update
    int num_keys_found; //stores number of keys found
    int anger_level; //stores the sorcerer's anger level
public:
    //default constructor
    inventory();
    
    //getters
    int getNumCookware();
    int getNumGold();
    int getNumIngredients();

    int getNumCeramicPots();
    int getNumFryingPans();
    int getNumCauldrons();

    int getNumClubs();
    int getNumSpears();
    int getNumRapiers();
    int getNumBattleAxes();
    int getNumLongswords();

    int getNumArmour();

    int getNumTreasures();
    int getNumSilverRings();
    int getNumRubyNecklaces();
    int getNumEmeraldBracelets();
    int getNumDiamondCirclets();
    int getNumGemEncrustedGoblets();

    int getNumKeysFound();
    int getAngerLevel();

    int getNumWeapons();
    //setters
    void setNumGold(int num_gold);
    void setNumIngredients(int num_ingredients);

    void setNumCeramicPots(int num_ceramic_pots);
    void setNumFryingPans(int num_frying_pans);
    void setNumCauldrons(int num_cauldrons);

    void setNumClubs(int num_clubs);
    void setNumSpears(int num_spears);
    void setNumRapiers(int num_rapiers);
    void setNumBattleAxes(int num_battle_axes);
    void setNumLongswords(int num_longswords);

    void setNumArmour(int num_armour);

    void setNumSilverRings(int num_silver_rings);
    void setNumRubyNecklaces(int num_ruby_necklaces);
    void setNumEmeraldBracelets(int num_emerald_bracelets);
    void setNumDiamondCirclets(int num_diamond_circlets);
    void setNumGemEncrustedGoblets(int num_gem_encrusted_goblets);

    void setNumKeys(int num_keys_found);
    void setAngerLevel(int anger_level);

    void setNumWeapons(int num_weapons);
    //other
    void displayInventory();
};

#endif