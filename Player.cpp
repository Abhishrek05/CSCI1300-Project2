/* Player.cpp Pseudocode: 
 1.initializes the stats
 2. check player stats to ensure they are the correct number and then set their values to a variable to use in this file.  
 3. get and set variables/ inputs        
 4. set up stamina, wisdom, and strength values 
 5. Initialize the basic values of the different traits of each character based on the route they decide to take
 6. Calculate all pride points for player
 7. print out player stats
*/
//player.cpp
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 20000; //should start with 20,000 pride points 
    currentAdvisor = ""; //potential advisor
    isOnPride = true;
}

Player::Player(string name, int strength, int stamina, int wisdom) {
    _name = name;
    _age = 1;
    _strength = strength;
    _stamina = stamina;
    _wisdom = wisdom;
    _pride_points = 20000;
}

string Player::getName() {
    return _name;
}

string Player::getAdvisor() {
    return currentAdvisor;
}

int Player::getStrength() {
    return _strength;
}

int Player::getStamina() {
    return _stamina;
}

int Player::getWisdom() {
    return _wisdom;
}

int Player::getPridePoints() {
    return _pride_points;
}

int Player::getAge() {
    return _age;
}

void Player::setName(string name) {
    _name = name;
}

void Player::setAdvisor(string advisor) {
    currentAdvisor = advisor;
}

void Player::setStrength(int strength) {
    _strength = strength;
}

void Player::addStrength(int strength) {
    _strength = getStrength() + strength;
}

void Player::setStamina(int stamina) {
    _stamina = stamina;
}

void Player::addStamina(int stamina) {
    _stamina = getStamina() + stamina;
}

void Player::setWisdom(int wisdom) {
    _wisdom = wisdom;
}

void Player::addWisdom(int wisdom) {
    _wisdom = getWisdom() + wisdom;
}

void Player::setPridePoints(int pride_points) {
    _pride_points = pride_points;
}

void Player::addPridePoints(int pride_points) {
    _pride_points = getPridePoints() + pride_points;
}

void Player::setAge(int age) {
    _age = age;
}

void Player::trainCub() {
    _strength = getStrength() + 500;
    _stamina = getStamina() + 500;
    _wisdom = getWisdom() + 1000;
    _pride_points = getPridePoints() - 5000;
}

void Player::toPrideLands() {
    _pride_points = getPridePoints() + 5000;
    _strength = getStrength() + 200;
    _stamina = getStamina() + 200;
    _wisdom = getWisdom() + 200;

}

void Player::printStats() {
    cout<<_name<<", age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom: "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;
}


void Player::oasisTile(){
    _strength = getStrength() + 200;
    _stamina = getStamina() + 200;
    _wisdom = getWisdom() + 200;
}

void Player::counselingTile(){
    _strength = getStrength() + 300;
    _stamina = getStamina() + 300;
    _wisdom = getWisdom() + 300;
}

void Player::graveyardTile(){
    _strength = getStrength() - 100;
    _stamina = getStamina() - 100;
    _wisdom = getWisdom() - 100;
    if(_stamina < 100) {
        _stamina = 100;
    }
    if(_strength < 100) {
        _strength = 100;
    }
    if(_wisdom < 100) {
        _wisdom = 100;
    }
}

void Player::heynaTile(){
    _stamina = getStamina() - 300;
    if(_stamina < 100) {
        _stamina = 100;
    }
}

void Player::setPath(bool y) {
    isOnPride = y;
}

bool Player::getPath() {
    return isOnPride;
}