#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
    public:
        Player();
        Player(string, int, int, int);
        string getName(); 
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        void setName(string);
        void setStrength(int);
        void setStamina(int);
        void setWisdom(int);
        void setPridePoints(int);
        void setAge(int);
        void trainCub(int, int, int);
        void toPrideLands();
        void printStats();
};

#endif