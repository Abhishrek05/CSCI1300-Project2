#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Board.h"

using namespace std;


Game::Game(Player players[2], Board board, int turn) {
    player[0] = players[0];
    player[1] = players[1];
    gameBoard = board;
    currentTurn = turn;
}
int Game::split(string input_string, char separator, string arr[], const int ARR_SIZE) {
    int count = 0;
    string temp = "";

    if (input_string.length() == 0) {
            return 0; 
        }

     for (unsigned int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == separator) {
            if (count < ARR_SIZE) {
                arr[count] = temp;
                count++;
            } else {

                return -1;
            }
            temp = ""; 
        } else {
            temp += input_string[i]; 
        }
    }

    if (count < ARR_SIZE) {
        arr[count] = temp;
        count++;
    } else {
        return -1;
    }


    if (count == 1 && arr[0] == input_string) {
        return 1;
    }

    return count; 
}



void Game::chooseCharacters(Player player[], int playerIndex){
    displayCharacters();
    cout<<"Input the corresponding number to choose a character."<<endl;
    int input = 0;
    cin>>input;
    ifstream file("character.txt");
    string line;
    string arr[6];
    if(file.fail()) {
        cout<<"Could not open file."<<endl;
        return;
    }
    while(getline(file, line)) {
        split(line, '|', arr, 6);
        if(input == 1 && arr[0] == "Apollo") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 2 && arr[0] == "Mane") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 3 && arr[0] == "Elsa") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 4 && arr[0] == "Zuri") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 5 && arr[0] == "Roary") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        }
    }
}

void Game::chooseAdvisor(Player player){
    cout<<"Input the corresponding number to choose an advisor."<<endl;
    int input = 0;
    cin>>input;
    
    string AdivsorName[5] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};

    for(int i = 0; i < 5; i++){
        cout << i+1 << ") " << AdivsorName[i] << endl;
    }

    cin>>input;

    player.setAdvisor(AdivsorName[input - 1]);

}
void Game::displayCharacters() {
    ifstream file("character.txt");
    string line;
    int count = 0;
    if(file.fail()) {
        cout<<"Could not open file."<<endl;
        return;
    }
    cout<<"Characters to choose from: "<<endl;
    while(getline(file, line)) {
        cout<<count<<" - "<<line<<endl;
        count++;
    }
}
        // void selectPath();
        // void playgame();
        // void determineWinner();  