/*
Driver.cpp Pseudocode:
1. Sort through the data in the in the text files
2. Make a split function
3. Make a dice function
4.sort through riddles in the riddles.txt file
5. Put everything in main and prompt users to answer questions and play the game
6. Filter through player input from the choices in the main menu
*/
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Board.cpp"
#include "Player.h"
#include "Player.cpp"

using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE) {
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

void printMainMenue() {
    cout << "Main Menu: Select an option to continue\n " << 
    "1. Check Player Progress (1)\n" <<
    "2. Review Character (2)\n" <<
    "3. Check Position (3)\n " <<
    "4. Review your Advisor (4)\n " <<
    "5. Move Forward (5)\n" <<
    "Please choose an option using the corresponding number:\n";
}

void displayCharacters() {
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

void chooseCharacter(Player &player) {
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
            player.setName(arr[0]);
            player.setAge(stoi(arr[1]));
            player.setStrength(stoi(arr[2]));
            player.setStamina(stoi(arr[3]));
            player.setWisdom(stoi(arr[4]));
        } else if(input == 2 && arr[0] == "Mane") {
            player.setName(arr[0]);
            player.setAge(stoi(arr[1]));
            player.setStrength(stoi(arr[2]));
            player.setStamina(stoi(arr[3]));
            player.setWisdom(stoi(arr[4]));
        } else if(input == 3 && arr[0] == "Elsa") {
            player.setName(arr[0]);
            player.setAge(stoi(arr[1]));
            player.setStrength(stoi(arr[2]));
            player.setStamina(stoi(arr[3]));
            player.setWisdom(stoi(arr[4]));
        } else if(input == 4 && arr[0] == "Zuri") {
            player.setName(arr[0]);
            player.setAge(stoi(arr[1]));
            player.setStrength(stoi(arr[2]));
            player.setStamina(stoi(arr[3]));
            player.setWisdom(stoi(arr[4]));
        } else if(input == 5 && arr[0] == "Roary") {
            player.setName(arr[0]);
            player.setAge(stoi(arr[1]));
            player.setStrength(stoi(arr[2]));
            player.setStamina(stoi(arr[3]));
            player.setWisdom(stoi(arr[4]));
        }
    }
}


int main() {
    Player player1;
//     srand(time(0)); //seed random number genrator
//     Board board(2);
//    // board.initializeBoard();
//     board.displayBoard();
    displayCharacters();
    chooseCharacter(player1);
    player1.printStats();
    return 0;
}