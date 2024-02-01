#ifndef MERCHANTMENU_H
#define MERCHANTMENU_H

#include <iostream>
#include "inventory.h"
#include "map.h"
#include "players.h"

using namespace std;

class merchantMenu
{
private:
double ceramic_pot_price; //price of a ceramic pot in gold
double frying_pan_price; //price of a frying pan in gold
double cauldron_price; //price of a cauldron in gold

double club_price; //price of a club in gold
double spear_price; //price of a spear in gold
double rapier_price; //price of a rapier in gold
double battle_axe_price; //price of a battle axe in gold
double longsword_price; // price of a longsword in gold

double ingredients_price; // price of ingredients per kg

double armour_price; //price of armour

double silver_ring_price; //price of a silver ring
double ruby_necklaces_price; //price of a ruby necklace
double emerald_bracelets_price; //price of an emerald bracelet
double diamond_circlets_price; //price of a diamond circlet
double gem_encrusted_goblets_price; //price of a gem encrusted goblet

public:
merchantMenu();
void displayMerchantMenu(inventory &i, Map &m, players &p); //displays the merchant menu
};

#endif