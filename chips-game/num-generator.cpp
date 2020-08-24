#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


// string FindPlayerName(string name[], bool playerTurn);

string FindPlayerName(string name[], bool playerTurn) {
    if(playerTurn == true)
      return name[0];
    else 
      return name[1];
}

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

int main(){

// when it's true, it's players1's turn, when it's false it's players2's turn
bool player1Turn = true;

//determine when the game is over
bool gameOver = false;

//starting point
int chipsInPile = 0;
int chipsTaken = 0;

char playAgain;

string playerName[2];
cout <<"player 1, please enter your name: \n";
cin >> playerName[0];
cout <<"player 2, please enter your name: \n";
cin >> playerName[1];

srand(time(0));

do
{
 //start the game with a random number of chips from 1 to 100
chipsInPile = (rand()% MAX_CHIPS) + 1;

cout << "this round will start with " << chipsInPile << " chips in the pile" << endl;
gameOver = false;

while (gameOver == false) {
do {
            cout << FindPlayerName(playerName, player1Turn) << ", how many chips would you like?" << endl;

        cout << "you can take up to "; 
        // if half of the number of chips in my pile is zero (which will be one when the pile is one or less) display one otherwise display the number of chips in pile divided by 2 (.5))
        if (static_cast<int>(MAX_TURN * chipsInPile) == 0) {
            cout << "1 \n";
        } else {
            cout << (static_cast<int>(MAX_TURN * chipsInPile)) << endl;
        }
        cin >> chipsTaken;
        } while ((chipsTaken > (static_cast<int>(MAX_TURN * chipsInPile))) && (chipsInPile > 1));

        chipsInPile = chipsInPile - chipsTaken;
        cout << "there are " << chipsInPile << " left in the pile" <<endl;
        if (chipsInPile == 0) {
            gameOver = true;
        
            cout << FindPlayerName(playerName, player1Turn) << ", you won!" << endl;
        } else {
            player1Turn = !player1Turn;
        }
    }
      cout << "would you like to play again? y/n " << endl;
      cin >> playAgain;

} while ((playAgain == 'y') || (playAgain == 'Y'));

    return 0;
}

