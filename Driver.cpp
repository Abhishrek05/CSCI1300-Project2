// main.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Board.h"
// #include "Board.cpp"
// #include "Player.cpp"
#include "Game.h"
// #include "Game.cpp"

using namespace std;

// Constants
// const int MAX_CHARACTERS = 5;
// const int MAX_ADVISORS = 5;

// class Game {
// private:
//     Player players[2];
//     Board gameBoard;
//     int currentPlayerTurn;

//     // Character structure to read characters
//     struct Character {
//         char name[50];
//         int age;
//         int strength;
//         int stamina;
//         int wisdom;
//         int pridePoints;
//     };

//     // Advisors array
//     struct Advisor {
//         char name[20];
//         char ability[50];
//     } advisors[MAX_ADVISORS];

//     Character characters[MAX_CHARACTERS];
//     int characterCount;
//     int advisorCount;

//     // File reading methods
//     void loadCharacters() {
//         ifstream file("charecter.txt");
//         if (!file.is_open()) {
//             cerr << "Unable to open characters file!" << endl;
//             exit(1);
//         }

//         characterCount = 0;
//         string line;
//         while (getline(file, line) && characterCount < MAX_CHARACTERS) {
//             sscanf(line.c_str(), "%49[^|]|%d|%d|%d|%d|%d", 
//                 characters[characterCount].name,
//                 &characters[characterCount].age,
//                 &characters[characterCount].strength,
//                 &characters[characterCount].stamina,
//                 &characters[characterCount].wisdom,
//                 &characters[characterCount].pridePoints
//             );
//             characterCount++;
//         }
//         file.close();
//     }

//    void loadAdvisors() {
//     // Predefined advisors based on project requirements
//     advisorCount = 5;

//     const char predefinedNames[MAX_ADVISORS][20] = {
//         "Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"
//     };

//     const char predefinedAbilities[MAX_ADVISORS][50] = {
//         "Invisibility", "Night Vision", "Energy Manipulation", 
//         "Weather Control", "Super Speed"
//     };

//     for (int i = 0; i < advisorCount; i++) {
//         // Manually copy names
//         int j = 0;
//         while (predefinedNames[i][j] != '\0') {
//             advisors[i].name[j] = predefinedNames[i][j];
//             j++;
//         }
//         advisors[i].name[j] = '\0'; // Null-terminate the string

//         // Manually copy abilities
//         j = 0;
//         while (predefinedAbilities[i][j] != '\0') {
//             advisors[i].ability[j] = predefinedAbilities[i][j];
//             j++;
//         }
//         advisors[i].ability[j] = '\0'; // Null-terminate the string
//     }
// }

//     void displayCharacters() {
//         cout << "Available Characters:" << endl;
//         for (int i = 0; i < characterCount; i++) {
//             Character& c = characters[i];
//             cout << i+1 << ". " << c.name 
//                  << " (Age: " << c.age 
//                  << ", Strength: " << c.strength 
//                  << ", Stamina: " << c.stamina 
//                  << ", Wisdom: " << c.wisdom 
//                  << ", Pride Points: " << c.pridePoints << ")" << endl;
//         }
//     }

//     void selectCharacters() {
//         for (int playerIndex = 0; playerIndex < 2; playerIndex++) {
//             cout << "Player " << playerIndex + 1 << ", select your character:" << endl;
//             displayCharacters();
            
//             int choice;
//             do {
//                 cout << "Enter character number: ";
//                 cin >> choice;
//             } while (choice < 1 || choice > characterCount);

//             // Adjust for 0-based indexing
//             choice--;

//             // Create player with selected character attributes
//             players[playerIndex] = Player(
//                 characters[choice].name, 
//                 characters[choice].strength,
//                 characters[choice].stamina,
//                 characters[choice].wisdom
//             );
//         }
//     }

//     void selectPathType() {
//         for (int playerIndex = 0; playerIndex < 2; playerIndex++) {
//             cout << "Player " << playerIndex + 1 
//                  << ", choose your path:" << endl;
//             cout << "1. Cub Training" << endl;
//             cout << "2. Straight to Pride Lands" << endl;
            
//             int pathChoice;
//             do {
//                 cout << "Enter path number: ";
//                 cin >> pathChoice;
//             } while (pathChoice < 1 || pathChoice > 2);

//             if (pathChoice == 1) {
//                 // Cub Training path
//                 players[playerIndex].trainCub(500, 500, 1000);
                
//                 // Advisor selection
//                 cout << "Select your advisor:" << endl;
//                 for (int i = 0; i < advisorCount; i++) {
//                     cout << i+1 << ". " << advisors[i].name 
//                          << " - " << advisors[i].ability << endl;
//                 }
                
//                 int advisorChoice;
//                 do {
//                     cout << "Enter advisor number: ";
//                     cin >> advisorChoice;
//                 } while (advisorChoice < 1 || advisorChoice > advisorCount);
                
//                 // Adjust for 0-based indexing
//                 advisorChoice--;
//                 players[playerIndex].setAdvisor(advisors[advisorChoice].name);
//             } else {
//                 // Straight to Pride Lands path
//                 players[playerIndex].toPrideLands();
//             }
//         }
//     }

//     void playGame() {
//         gameBoard = Board(2);  // Initialize board for 2 players
//         currentPlayerTurn = 0;

//         while (true) {
//             // Display current board state
//             cout << "Current Board State:" << endl;
//             gameBoard.displayBoard();

//             // Display current player's stats
//             cout << "Player " << currentPlayerTurn + 1 << " Turn:" << endl;
//             players[currentPlayerTurn].printStats();

//             // Main menu
//             displayMainMenu();

//             // Switch turns
//             currentPlayerTurn = (currentPlayerTurn + 1) % 2;

//             // Check win condition (when a player reaches the end)
//             if (gameBoard.getPlayerPosition(currentPlayerTurn) == 51) {
//                 break;
//             }
//         }

//         // Determine winner
//         determineWinner();
//     }

//     void displayMainMenu() {
//         int choice;
//         do {
//             cout << "Main Menu:" << endl;
//             cout << "1. Check Player Progress" << endl;
//             cout << "2. Review Character" << endl;
//             cout << "3. Check Position" << endl;
//             cout << "4. Review Advisor" << endl;
//             cout << "5. Move Forward" << endl;
//             cout << "Enter your choice: ";
//             cin >> choice;

//             switch (choice) {
//                 case 1:
//                     players[currentPlayerTurn].printStats();
//                     break;
//                 case 2:
//                     cout << "Character: " << players[currentPlayerTurn].getName() << endl;
//                     break;
//                 case 3:
//                     gameBoard.displayBoard();
//                     break;
//                 case 4:
//                     cout << "Advisor: " << players[currentPlayerTurn].getAdvisor() << endl;
//                     break;
//                 case 5:
//                     // Simulate dice roll (1-6)
//                     int steps = (rand() % 6) + 1;
//                     cout << "You rolled a " << steps << endl;
//                     // TODO: Implement tile-specific logic when moving
//                     break;
//             }
//         } while (choice != 5);
//     }

//     void determineWinner() {
//         int player1Points = players[0].getPridePoints();
//         int player2Points = players[1].getPridePoints();

//         cout << "Final Results:" << endl;
//         players[0].printStats();
//         players[1].printStats();

//         if (player1Points > player2Points) {
//             cout << "Player 1 (" << players[0].getName() 
//                  << ") is the new Pride Leader!" << endl;
//         } else if (player2Points > player1Points) {
//             cout << "Player 2 (" << players[1].getName() 
//                  << ") is the new Pride Leader!" << endl;
//         } else {
//             cout << "It's a tie! Both players show great leadership potential!" << endl;
//         }
//     }

// public:
//     Game() : gameBoard(2), currentPlayerTurn(0) {
//         srand(time(NULL));  // Seed random number generator
//     }

//     void run() {
//         loadCharacters();
//         loadAdvisors();
//         selectCharacters();
//         selectPathType();
//         playGame();
//     }
// };

int main() {
    //Game lionKingGame;
    //lionKingGame.run();
    Player player1;
    Player player2;
    int index = 0;
    Board board(2);
    Player players[2] = {player1, player2};
    Game game(players, board, 0);

    game.chooseCharacters(players, index);
    players[0].printStats();
    //game.chooseAdvisor(player1);
    return 0;
}