#include "inventory.h"
#include <iostream>

using namespace std;

//default constructor
inventory::inventory(){
    //gold/ingredients
    num_gold_ = 100; //stores the amount of gold the player has
    num_ingredients_ = 0; //stores the amount of ingredients the player has

    //cookware
    num_ceramic_pots_ = 0; //stores the amount of ceramic pots a player owns
    num_frying_pans_ = 0; //stores the amount of frying pans a player owns
    num_cauldrons_ = 0; //stores the amount of cauldrons a player owns

    //weapons
    num_clubs_ = 0; //stores the amount of clubs the player owns
    num_spears_ = 0; //stores the amount of spears the player owns
    num_rapiers_ = 0; //stores the amount of rapiers the player owns
    num_battle_axes_ = 0; //stores the amount of battle axes the player owns
    num_longswords_ = 0; //stores the amount of longswords the player owns

    //armour
    num_armour_ = 0; //stores the amount of armour sets that the player owns

    //Treasures
    num_silver_rings_ = 0; //stores the amount of silver rings that the player owns
    num_ruby_necklaces_ = 0; //stores the amount of ruby necklaces that the player owns
    num_emerald_bracelets_ = 0; //stores the amount of emerald bracelets that the player owns
    num_diamond_circlets_ = 0; //stores the amount of diamond circlets that the player owns
    num_gem_encrusted_goblets_ = 0; //stores the amount of gem-encrusted goblets that the player owns

    num_keys_found = 0; //stores the amount of keys that have been found

    anger_level = 0; //stores the sorcerer's anger level

    num_weapons_ = getNumSpears() + getNumBattleAxes() + getNumClubs() + getNumLongswords() + getNumRapiers();
}
//getters
int inventory::getNumGold(){
    return num_gold_;
}

int inventory::getNumWeapons(){
    return getNumSpears() + getNumBattleAxes() + getNumClubs() + getNumLongswords() + getNumRapiers();
}

int inventory::getNumCookware(){
    return getNumCeramicPots() + getNumFryingPans() + getNumCauldrons();
}

int inventory::getNumTreasures(){
    return getNumSilverRings() + getNumRubyNecklaces() + getNumEmeraldBracelets() + getNumDiamondCirclets() + getNumGemEncrustedGoblets();
}

//get number of ingredients
int inventory::getNumIngredients(){
    return num_ingredients_;
}

//get number of ceramic pots
int inventory::getNumCeramicPots(){
    return num_ceramic_pots_;
}

//get number of frying pans
int inventory::getNumFryingPans(){
    return num_frying_pans_;
}

//get number of cauldrons
int inventory::getNumCauldrons(){
    return num_cauldrons_;
}

//get number of clubs
int inventory::getNumClubs(){
    return num_clubs_;
}

//get number of spears
int inventory::getNumSpears(){
    return num_spears_;
}

//get number of rapiers
int inventory::getNumRapiers(){
    return num_rapiers_;
}

//get number of battle axes
int inventory::getNumBattleAxes(){
    return num_battle_axes_;
}

//get number of Longswords
int inventory::getNumLongswords(){
    return num_longswords_;
}

//get number of armour sets
int inventory::getNumArmour(){
    return num_armour_;
}

int inventory::getNumSilverRings(){
    return num_silver_rings_;
}
int inventory::getNumRubyNecklaces(){
    return num_ruby_necklaces_;
}
int inventory::getNumEmeraldBracelets(){
    return num_emerald_bracelets_;
}
int inventory::getNumDiamondCirclets(){
    return num_diamond_circlets_;
}
int inventory::getNumGemEncrustedGoblets(){
    return num_gem_encrusted_goblets_;
}
int inventory::getAngerLevel(){
    return anger_level;
}

int inventory::getNumKeysFound(){
    return num_keys_found;
}

//setters
void inventory::setNumGold(int num_gold){
    num_gold_ = num_gold;
}
void inventory::setNumIngredients(int num_ingredients){
    num_ingredients_ = num_ingredients;
}

void inventory::setNumCeramicPots(int num_ceramic_pots){
    num_ceramic_pots_ = num_ceramic_pots;
}
void inventory::setNumFryingPans(int num_frying_pans){
    num_frying_pans_ = num_frying_pans;
}
void inventory::setNumCauldrons(int num_cauldrons){
    num_cauldrons_ = num_cauldrons;
}
void inventory::setNumWeapons(int num_weapons){
    num_weapons_ = num_weapons;
}
void inventory::setNumClubs(int num_clubs){
    num_clubs_ = num_clubs;
}
void inventory::setNumSpears(int num_spears){
    num_spears_ = num_spears;
}
void inventory::setNumRapiers(int num_rapiers){
    num_rapiers_ = num_rapiers;
}
void inventory::setNumBattleAxes(int num_battle_axes){
    num_battle_axes_ = num_battle_axes;
}
void inventory::setNumLongswords(int num_longswords){
    num_longswords_ = num_longswords;
}

void inventory::setNumArmour(int num_armour){
    num_armour_ = num_armour;
}

void inventory::setNumSilverRings(int num_silver_rings){
    num_silver_rings_ = num_silver_rings;
}
void inventory::setNumRubyNecklaces(int num_ruby_necklaces){
    num_ruby_necklaces_ = num_ruby_necklaces;
}
void inventory::setNumEmeraldBracelets(int num_emerald_bracelets){
    num_emerald_bracelets_ = num_emerald_bracelets;
}
void inventory::setNumDiamondCirclets(int num_diamond_circlets){
    num_diamond_circlets_ = num_diamond_circlets;
}
void inventory::setNumGemEncrustedGoblets(int num_gem_encrusted_goblets){
    num_gem_encrusted_goblets_ = num_gem_encrusted_goblets;
}

void inventory::setNumKeys(int num_keys_found_){
    num_keys_found = num_keys_found_;
}

void inventory::setAngerLevel(int anger_level_){
    anger_level = anger_level_;
}
//other
void inventory::displayInventory(){
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << getNumGold() << endl;
    cout << "| Ingredients | " << getNumIngredients() << endl;
    //*******************************************************************
    cout << "| Cookware    | " << "Pots: " << getNumCeramicPots() <<
     " | Frying Pans: " << getNumFryingPans() << " | Cauldrons: " << getNumCauldrons() << endl;
    //*************************************************************************************
    cout << "| Weapons     | " << "Clubs: " << getNumClubs() <<
     " | Spears: " << getNumSpears() << " | Rapiers: " << getNumRapiers() << " | Battle Axes: " << getNumBattleAxes()
     << " | Long Swords: " << getNumLongswords() << endl;
    //*************************************************************************************
    cout << "| Armor       | " << getNumArmour() << endl;
    //**************************************************************************************
    cout << "| Treasures   | " << "Silver Rings: " << getNumSilverRings() << " | Ruby Necklaces: "
     << getNumRubyNecklaces() << " | Emerald Bracelets: " << getNumEmeraldBracelets() << " | Diamond Circlets: " << getNumDiamondCirclets()
      << " | Gem Encrusted Goblets: " << getNumGemEncrustedGoblets() << endl;
    cout << endl;
}