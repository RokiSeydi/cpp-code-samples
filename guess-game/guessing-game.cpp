#include <iostream>

using namespace std;

// int main(){
// int secretNumb = 8;
// int guess;

// while(secretNumb != guess){
//     cout << "Enter guess: ";
//     cin >> guess;
// }

// cout <<"You guessed right!"<< endl;
//     return 0;
// }

// with a do while loop;

int main(){
    int secretNum = 8;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;

    bool outOfGuesses = false;

    cout <<"Guess the secret number - you have 3 attempts! " <<endl;

do {
    if(guessCount < guessLimit){
    cout << "Guess the number: ";
    cin >> guess;
    guessCount++;
    } else {
        outOfGuesses = true;
    }
} 

while(secretNum != guess && !outOfGuesses);

if(secretNum == guess){
cout << "you guessed it right!" << endl;
} else {
    cout << "you lost, try again!" <<endl;
}
   return 0;
}