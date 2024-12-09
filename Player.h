/*
Player.h Pseudocode:
This sets and gets (stores player data in these variables )
based on the special tiles in the game, there are modifications to the specific tiles
oasis, counseling, graveyard, hyenas, challenge*/
#ifndef PLAYER_H
#define PLAYER_H
//player.h
#include <iostream>

using namespace std;

class Player {
    private:
        string _name, currentAdvisor;
        int _strength, _stamina, _wisdom, _pride_points, _age;
        bool isOnPride;
    public:
        Player();
        Player(string, int, int, int);
        string getName();
        string getAdvisor(); 
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        void setName(string);
        void setAdvisor(string);
        void setStrength(int);
        void setStamina(int);
        void setWisdom(int);
        void setPridePoints(int);
        void setAge(int);
        void trainCub();
        void toPrideLands();
        void printStats();
        void oasisTile();
        void counselingTile();
        void graveyardTile();
        void heynaTile();
        void setPath(bool);
        bool getPath();
};

#endif