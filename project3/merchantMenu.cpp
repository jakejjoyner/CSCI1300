                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #include "merchantMenu.h"

#include <iostream>
#include <fstream>

using namespace std;

merchantMenu::merchantMenu(){
ceramic_pot_price = 2; //price of a ceramic pot in gold
frying_pan_price = 10; //price of a frying pan in gold
cauldron_price = 20; //price of a cauldron in gold
                                                      
club_price = 2; //price of a club in gold
spear_price = 2; //price of a spear in gold
rapier_price = 5; //price of a rapier in gold
battle_axe_price = 15; //price of a battle axe in gold
longsword_price = 50; // price of a longsword in gold

ingredients_price = 1; //price of ingredients per kg

armour_price = 5; //price of a set of armor

silver_ring_price = 10; //price of a silver ring
ruby_necklaces_price = 20; //price of a ruby necklace
emerald_bracelets_price = 30; //price of an emerald bracelet
diamond_circlets_price = 40; //price of a diamond circlet
gem_encrusted_goblets_price = 50; //price of a gem encrusted goblet

}

/*
Algorithm:
1. Greet the players
2. Display the Inventory
3. Display the options for what the player can purchase
4. Present the player with information about possible purchases
5. Ask the player for inputs depending on which purchase they are making
6. Add the data to the inventory class
*/
void merchantMenu::displayMerchantMenu(inventory &i, Map &m, players &p){
cout << "If you're looking to get supplies, you've come to the right place." << endl;
cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
ofstream fout;
fout.open("armor.txt");
for(;;){
string choice;
int cpp = ceramic_pot_price * (0.25 * (5-m.getRoomCount()));
ceramic_pot_price += cpp;
int fpp = frying_pan_price * (0.25 * (5-m.getRoomCount()));
frying_pan_price += fpp;
int cp = cauldron_price * (0.25 * (5-m.getRoomCount()));
cauldron_price += cp;

int clp = club_price * (0.25 * (5-m.getRoomCount()));
club_price += clp;
int sp = spear_price * (0.25 * (5-m.getRoomCount()));
spear_price += sp;
int rp = rapier_price * (0.25 * (5-m.getRoomCount()));
rapier_price += rp;
int bap = battle_axe_price * (0.25 * (5-m.getRoomCount()));
battle_axe_price += bap;
int lsp = longsword_price * (0.25 * (5-m.getRoomCount()));
longsword_price += lsp;

int ip = ingredients_price * (0.25 * (5-m.getRoomCount()));
ingredients_price += ip;

int ap = armour_price * (0.25 * (5-m.getRoomCount()));
armour_price += ap;

i.displayInventory();
cout << "Choose one of the following:" << endl;
cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
cout << "> ";
cin >> choice;
cout << endl;
if(choice == "2"){
    int user_input;
    cout << "I have a several types of cookware, which one would you like?" << endl;
    cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
    cout << endl;
    cout << "Choose one of the following:" << endl;
    cout << " 1. (25%) Ceramic Pot [" << ceramic_pot_price << " Gold]" << endl;
    cout << " 2. (10%) Frying Pan [" << frying_pan_price << " Gold]" << endl;
    cout << " 3. ( 2%) Cauldron ["  << cauldron_price << " Gold]" << endl;
    cout << " 4. Cancel" << endl;
    cout << "> ";
    cin >> user_input;
        while(user_input > 4 || user_input < 1){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> user_input;
        }
        if(user_input == 1){
            int user_input1;
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cout << "> ";
            cin >> user_input1;
                while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
                if(user_input1 == 0){
     
                }
                if(user_input1*ceramic_pot_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
          
                }
                if(user_input1 != 0 && !(user_input1*ceramic_pot_price > i.getNumGold())){
                    string user_input2;
                    cout << "You want to buy " << user_input1 << " Ceramic Pot(s) for " << ceramic_pot_price*user_input1 << " Gold? (y/n)" << endl;
                    cout << "> ";
                    cin >> user_input2;
                    while(user_input2 != "y" && user_input2 != "n"){
                        cout << "Please enter a valid input." << endl;
                        cout << "> ";
                        cin >> user_input2;
                    }
                    if(user_input2 == "y"){
                        i.setNumCeramicPots(i.getNumCeramicPots() + user_input1);
                        double num_gold = i.getNumGold()-(ceramic_pot_price*user_input1);
                        i.setNumGold(num_gold);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    if(user_input2 == "n"){
                        cout << "No problem! Is there anything else you were looking for?" << endl;
                    }
                }
        }
        if(user_input == 2){
            int user_input1;
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cout << "> ";
            cin >> user_input1;
                while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
                if(user_input1 == 0){

                }
                if(user_input1*frying_pan_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
  
                }
                if(user_input1 != 0 && !(user_input1*frying_pan_price > i.getNumGold())){
                    string user_input2;
                    cout << "You want to buy " << user_input1 << " Frying pan(s) for " << frying_pan_price*user_input1 << " Gold? (y/n)" << endl;
                    cout << "> ";
                    cin >> user_input2;
                    while(user_input2 != "y" && user_input2 != "n"){
                        cout << "Please enter a valid input." << endl;
                        cout << "> ";
                        cin >> user_input2;
                    }
                    if(user_input2 == "y"){
                        i.setNumFryingPans(i.getNumFryingPans() + user_input1);
                        double num_gold = i.getNumGold()-(frying_pan_price*user_input1);
                        i.setNumGold(num_gold);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    if(user_input2 == "n"){
                        cout << "No problem! Is there anything else you were looking for?" << endl;
                    }
                }
        }
        if(user_input == 3){
            int user_input1;
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cout << "> ";
            cin >> user_input1;
                while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
                if(user_input1*cauldron_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
                if(user_input1 != 0 && !(user_input1*cauldron_price > i.getNumGold())){
                    string user_input2;
                    cout << "You want to buy " << user_input1 << " Cauldron(s) for " << cauldron_price*user_input1 << " Gold? (y/n)" << endl;
                    cout << "> ";
                    cin >> user_input2;
                    while(user_input2 != "y" && user_input2 != "n"){
                        cout << "Please enter a valid input." << endl;
                        cout << "> ";
                        cin >> user_input2;
                    }
                    if(user_input2 == "y"){
                        i.setNumCauldrons(i.getNumCauldrons() + user_input1);
                        double num_gold = i.getNumGold()-(cauldron_price*user_input1);
                        i.setNumGold(num_gold);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    if(user_input2 == "n"){
                        cout << "No problem! Is there anything else you were looking for?" << endl;
                    }
                }
        }
        if(user_input == 4){
            cout << "Don't waste my time again 👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹" << endl;
        }
}
if(choice == "1"){
    int user_input;
    cout << "How many kg of ingredients do you need [" << ingredients_price << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
    cout << "> ";
    cin >> user_input;
    while(user_input < 0 && user_input % 5){
        cout << "Please enter a positive mulitple of 5." << endl;
        cout << "> ";
        cin >> user_input;
    }
    if(user_input > i.getNumGold()){
        cout << "You don't have enough gold to buy these ingredients!" << endl;
    }
    if(user_input != 0 && !(user_input*ingredients_price > i.getNumGold()) && !(user_input % 5)){
        string user_input1;
        cout << "You want to buy " << user_input << " kg of ingredients for " << user_input*ingredients_price << " Gold? (y/n)" << endl;
        cout << "> ";
        cin >> user_input1;
        while(user_input1 != "y" && user_input1 != "n"){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> user_input1;
        }
        if(user_input1 == "y"){
            double num_gold = i.getNumGold() - (user_input*ingredients_price);
            i.setNumGold(num_gold);
            i.setNumIngredients(i.getNumIngredients() + user_input);
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
        }
        if(user_input1 == "n"){
            cout << "No problem! Is there anything else that I can get for you?" << endl;
        }
    }
}
if(choice == "3"){
    int user_input;
    cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
    cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
    cout << endl;
    cout << "Choose one of the following:" << endl;
    cout << " 1. Stone Club [" << club_price << " Gold]" << endl;
    cout << " 2. Iron Spear [" << spear_price << " Gold]" << endl;
    cout << " 3. (+1) Mythril Rapier [" << rapier_price << " Gold]" << endl;
    cout << " 4. (+2) Flaming Battle-Axe [" << battle_axe_price << " Gold]" << endl;
    cout << " 5. (+3) Vorpal Longsword [" << longsword_price << " Gold]" << endl;
    cout << " 6. Cancel" << endl;

    cout << "> ";
    cin >> user_input;

    while(user_input > 6 || user_input < 1){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> user_input;
        }

    if(user_input == 1){
        int user_input1;
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1*club_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
        if(user_input1 == 0){

        }
        if(i.getNumWeapons()+user_input1 > p.getNumPlayers()){
            cout << "You have reached the maximum amount of weapons that can be purchased! Each party member is only allowed to carry one weapon." << endl;
        }
        if(user_input1 != 0 && !(user_input1*club_price > i.getNumGold()) && (i.getNumWeapons() + user_input1 <= p.getNumPlayers())){
            string user_input2;
            cout << "You want to buy " << user_input1 << " Stone Club(s) for " << user_input1*club_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumClubs(i.getNumClubs() + user_input1);
                double num_gold = i.getNumGold()-(club_price*user_input1);
                i.setNumGold(num_gold);
                p.setWeaponsArray(i.getNumWeapons(),"club");
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }
    }
    if(user_input == 2){
        int user_input1;
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1*spear_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
        if(user_input1 == 0){

        }
        if(i.getNumWeapons()+user_input1 > p.getNumPlayers()){
            cout << "You have reached the maximum amount of weapons that can be purchased! Each party member is only allowed to carry one weapon." << endl;
        }
        if(user_input1 != 0 && !(user_input1*spear_price > i.getNumGold()) && (i.getNumWeapons()+user_input1 <= p.getNumPlayers())){
            string user_input2;
            cout << "You want to buy " << user_input1 << " Iron Spear(s) for " << user_input1*spear_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumSpears(i.getNumSpears() + user_input1);
                double num_gold = i.getNumGold()-(spear_price*user_input1);
                i.setNumGold(num_gold);
                p.setWeaponsArray(i.getNumWeapons(),"spear");
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }
    }
    if(user_input == 3){
        int user_input1;
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1*rapier_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
        if(user_input1 == 0){

        }
        if(i.getNumWeapons() + user_input1 > p.getNumPlayers()){
            cout << "You have reached the maximum amount of weapons that can be purchased! Each party member is only allowed to carry one weapon." << endl;
        }
        if(user_input1 != 0 && !(user_input1*rapier_price > i.getNumGold()) && (i.getNumWeapons() + user_input1 <= p.getNumPlayers())){
            string user_input2;
            cout << "You want to buy " << user_input1 << " (+1) Mythril Rapier(s) for " << user_input1*rapier_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumRapiers(i.getNumRapiers() + user_input1);
                double num_gold = i.getNumGold()-(rapier_price*user_input1);
                i.setNumGold(num_gold);
                p.setWeaponsArray(i.getNumWeapons(),"rapier");
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }
    }
    if(user_input == 4){
        int user_input1;
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1*battle_axe_price > i.getNumGold() && (i.getNumWeapons() < p.getNumPlayers())){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
        if(user_input1 == 0){

        }
        if(i.getNumWeapons() + user_input1 > p.getNumPlayers()){
            cout << "You have reached the maximum amount of weapons that can be purchased! Each party member is only allowed to carry one weapon." << endl;
        }
        if(user_input1 != 0 && !(user_input1*battle_axe_price > i.getNumGold()) && (i.getNumWeapons() + user_input1 <= p.getNumPlayers())){
            string user_input2;
            cout << "You want to buy " << user_input1 << " (+2) Flaming Battle-Axe(s) for " << user_input1*battle_axe_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumBattleAxes(i.getNumBattleAxes() + user_input1);
                double num_gold = i.getNumGold()-(battle_axe_price*user_input1);
                i.setNumGold(num_gold);
                p.setWeaponsArray(i.getNumWeapons(),"axe");
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }
    }
    if(user_input == 5){
        int user_input1;
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1*longsword_price > i.getNumGold()){
                    cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
                }
        if(user_input1 == 0){

        }
        if(i.getNumWeapons() + user_input1 > p.getNumPlayers()){
            cout << "You have reached the maximum amount of weapons that can be purchased! Each party member is only allowed to carry one weapon." << endl;
        }
        if(user_input1 != 0 && !(user_input1*longsword_price > i.getNumGold()) && (i.getNumWeapons() + user_input1 <= p.getNumPlayers())){
            string user_input2;
            cout << "You want to buy " << user_input1 << " (+3) Vorpal Longsword(s) for " << user_input1*longsword_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumLongswords(i.getNumLongswords() + user_input1);
                double num_gold = i.getNumGold()-(longsword_price*user_input1);
                i.setNumGold(num_gold);
                p.setWeaponsArray(i.getNumWeapons(),"longsword");
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }    
    }
    if(user_input == 6){
        cout << "Don't waste my time again 👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹" << endl;
    }
}
if(choice == "4"){
    int user_input1;
    cout << "How many suits of armor can I get you? [5 gold per suit] (Enter a positive integer, or 0 to cancel)" << endl;
    cout << "> ";
    cin >> user_input1;
    while(user_input1 < 0){
        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;
    }
    if(user_input1*armour_price > i.getNumGold()){
        cout << "Oops! You don't have enough gold to buy this item! That's embarrassing!" << endl;
    }
    if(user_input1 != 0 && !(user_input1*armour_price > i.getNumGold())){
        string user_input2;
        cout << "You want to buy " << user_input1 << " suit(s) of armour for " << user_input1*armour_price << " Gold? (y/n)" << endl;
        cout << "> ";
        cin >> user_input2;
        while(user_input2 != "y" && user_input2 != "n"){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> user_input2;
                }
        if(user_input2 == "y"){
            i.setNumArmour(i.getNumArmour() + user_input1);
            double num_gold = i.getNumGold()-(armour_price*user_input1);
            i.setNumGold(num_gold);
            for(int i = 0; i < user_input1; i++){
                fout << "1" << endl;
            }
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                }
        if(user_input2 == "n"){
            cout << "No problem! Is there anything else you were looking for?" << endl;
                }

        }    
}
if(choice == "5"){
cout << "Which treasure would you like to sell?" << endl;
int user_input;
    cout << endl;
    cout << "Choose one of the following:" << endl;
    cout << " 1. Silver Ring - 10 gold pieces each" << endl;
    cout << " 2. Ruby Necklace - 20 gold pieces each" << endl;
    cout << " 3. Emerald Bracelet - 30 gold pieces each" << endl;
    cout << " 4. Diamond Circlet - 40 gold pieces each" << endl;
    cout << " 5. Gem-encrusted Goblet - 50 gold pieces each" << endl;
    cout << " 6. Cancel" << endl;
    cout << "> ";
    cin >> user_input;
    while(user_input > 6 || user_input < 1){
            cout << "Please enter a valid input." << endl;
            cout << "> ";
            cin >> user_input;
        }
    if(user_input == 1){
  int user_input1;
        cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1 > i.getNumSilverRings()){
                    cout << "Oops! You don't own the amount of silver rings that you are attempting to sell!" << endl;
                }
        if(user_input1 == 0){

        }
        if(user_input1 != 0 && !(user_input1 > i.getNumSilverRings())){
            string user_input2;
            cout << "You want to sell " << user_input1 << " Silver Ring(s) for " << user_input1*silver_ring_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumSilverRings(i.getNumSilverRings() - user_input1);
                double num_gold = i.getNumGold() + user_input1 * silver_ring_price;
                i.setNumGold(num_gold);
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }    
    }
    if(user_input == 2){
  int user_input1;
        cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1 > i.getNumRubyNecklaces()){
                    cout << "Oops! You don't own the amount of silver rings that you are attempting to sell!" << endl;
                }
        if(user_input1 == 0){

        }
        if(user_input1 != 0 && !(user_input1 > i.getNumRubyNecklaces())){
            string user_input2;
            cout << "You want to sell " << user_input1 << " Silver Ring(s) for " << user_input1*ruby_necklaces_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumRubyNecklaces(i.getNumRubyNecklaces() - user_input1);
                double num_gold = i.getNumGold() + user_input1*ruby_necklaces_price;
                i.setNumGold(num_gold);
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }   
    }
    if(user_input == 3){
  int user_input1;
        cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1 > i.getNumEmeraldBracelets()){
                    cout << "Oops! You don't own the amount of silver rings that you are attempting to sell!" << endl;
                }
        if(user_input1 == 0){

        }
        if(user_input1 != 0  && !(user_input1 > i.getNumEmeraldBracelets())){
            string user_input2;
            cout << "You want to sell " << user_input1 << " Silver Ring(s) for " << user_input1*emerald_bracelets_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumEmeraldBracelets(i.getNumEmeraldBracelets() - user_input1);
                double num_gold = i.getNumGold() + user_input1*emerald_bracelets_price;
                i.setNumGold(num_gold);
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }   
    }
    if(user_input == 4){
  int user_input1;
        cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1 > i.getNumDiamondCirclets()){
                    cout << "Oops! You don't own the amount of silver rings that you are attempting to sell!" << endl;
                }
        if(user_input1 == 0){

        }
        if(user_input1 != 0  && !(user_input1 > i.getNumDiamondCirclets())){
            string user_input2;
            cout << "You want to sell " << user_input1 << " Silver Ring(s) for " << user_input1*diamond_circlets_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumDiamondCirclets(i.getNumDiamondCirclets() - user_input1);
                double num_gold = i.getNumGold() + user_input1*diamond_circlets_price;
                i.setNumGold(num_gold);
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }   
    }
    if(user_input == 5){
  int user_input1;
        cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
        cout << "> ";
        cin >> user_input1;

        while(user_input1 < 0){
                        cout << "Please enter a valid input (positive integer, or 0 to cancel)" << endl;
                        cout << "> ";
                        cin >> user_input1;
                    }
        if(user_input1 > i.getNumGemEncrustedGoblets()){
                    cout << "Oops! You don't own the amount of silver rings that you are attempting to sell!" << endl;
                }
        if(user_input1 == 0){

        }
        if(user_input1 != 0  && !(user_input1 > i.getNumGemEncrustedGoblets())){
            string user_input2;
            cout << "You want to sell " << user_input1 << " Silver Ring(s) for " << user_input1*gem_encrusted_goblets_price << " Gold? (y/n)" << endl;
            cout << "> ";
            cin >> user_input2;
            while(user_input2 != "y" && user_input2 != "n"){
                cout << "Please enter a valid input." << endl;
                cout << "> ";
                cin >> user_input2;
                    }
            if(user_input2 == "y"){
                i.setNumGemEncrustedGoblets(i.getNumGemEncrustedGoblets() - user_input1);
                double num_gold = i.getNumGold() + user_input1*gem_encrusted_goblets_price;
                i.setNumGold(num_gold);
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
            if(user_input2 == "n"){
                cout << "No problem! Is there anything else you were looking for?" << endl;
                    }

        }   
    }
    if(user_input == 6){
cout << "Don't waste my time again 👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹👹" << endl;
    }
}
if(choice == "6"){
    cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
    cout << "> ";
    string user_input;
    cin >> user_input;
    while(user_input != "y" && user_input != "n"){
        cout << "Please enter a valid input." << endl;
        cout << "> ";
        cin >> user_input;
             }
    if(user_input == "y"){
        break;
    }
    if(user_input == "n"){

    }
}
if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6"){
    cout << "Please enter a valid input." << endl;
    cout << endl;
}

}
}