/*
This creates a tile header fucntion with private variabel type and public variable color
to store the color and the type of the tile of which the person can land on
*/

//tile.h


#include <iostream>

#ifndef TILE_H
#define TILE_H

using namespace std;

class Tile {
    private:
        string type;

    public:
        char color;
        char getColor();
        string getType();
};

#endif