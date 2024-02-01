------------------------
HOW TO COMPILE AND RUN
------------------------
IMPORTANT: Compile using 'gameDriver.cpp', NOT 'driver.cpp'
Compile: g++ -std=c++17 actionMenu.cpp game.cpp inventory.cpp map.cpp merchantMenu.cpp players.cpp start.cpp statusUpdate.cpp monsters.cpp gameDriver.cpp
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
actionMenu.h, game.h, inventory.h, map.h, merchantMenu.h, monsters.h, players.h, start.h, statusUpdate.h must be in the
same directory as the .cpp files in order to compile
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Jake Joyner
Recitation: 202 – Christopher Ojukwu
Date: Dec 1st, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This game takes inspiration from the game Dungeons and Dragons. In Dungeons and Dragons,
each run through is different from the previous one. The game consists of a party of players
making their way through a dungeon, fighting monsters, solving puzzles, and talking to NPCs.
In 'Dungeon Escape', an evil Sorcerer has captured a group of 5 players and trapped them in a
dungeon. The objective of the game is to make it out of the dungeon with as many party members
as possible. Each turn, the players hunger levels drop, and there are possibilitiesa of various
misfortunes happening. You are able to fight monsters, speak to NPCs, explore, etc., although
if you don't make it out of the dungeon before the sorcerer's anger level reaches 100, the sorcerer
will destroy the dungeon and everyone inside of it.