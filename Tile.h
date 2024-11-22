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