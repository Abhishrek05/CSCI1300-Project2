/*
Tile.cpp Pseudocode:
Make a board class. 
Set lane 1 - generate the tiles with the lanes, position, and calculate the total tiles
Do the same thing with lane 2
Set positions
Put these in a private
In public
Generate the lanes in the game
*/
#include "Tile.h"
#include <iostream>

using namespace std;

char Tile::getColor() {
    return color;
}

string Tile::getType() {
    return type;
}

void Tile::setType(string x){
    type = x;
}