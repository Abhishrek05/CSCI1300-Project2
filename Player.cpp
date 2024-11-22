#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 0;
}

Player::Player(string name, int strength, int stamina, int wisdom) {
    _name = name;
    _age = 1;
    _strength = strength;
    _stamina = stamina;
    _wisdom = wisdom;
    _pride_points = 0;
}

string Player::getName() {
    return _name;
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

void Player::setStrength(int strength) {
    _strength = strength;
}

void Player::setStamina(int stamina) {
    _stamina = stamina;
}

void Player::setWisdom(int wisdom) {
    _wisdom = wisdom;
}

void Player::setPridePoints(int pride_points) {
    _pride_points = pride_points;
}

void Player::setAge(int age) {
    _age = age;
}

void Player::trainCub(int strength, int stamina, int wisdom) {
    _strength = getStrength() + strength;
    _stamina = getStamina() + stamina;
    _wisdom = getWisdom() + wisdom;
    _pride_points = getPridePoints() - 5000;
}

void Player::toPrideLands() {
    _pride_points = getPridePoints() + 5000;
    _strength = getStrength() - 2000;
    _stamina = getStamina() - 1000;
    _wisdom = getWisdom() - 2000;

}

void Player::printStats() {
    cout<<_name<<", age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom: "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;
}