#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream passwordSheet;
    passwordSheet.open("password-file.txt");
    ofstream passwordSecondSheet;
    passwordSecondSheet.open("password-second-file.txt");

    int userGuess = 0;

    string passPhrase;

    if(!passwordSheet.fail()){
        while(passwordSheet >> passPhrase)
        {          
            cout << "the passphrase is " << passPhrase << endl;
            cout << "what is your guess?" <<endl;
            cin >> userGuess;
            if (userGuess == passPhrase.length())
            cout <<"you guessed it right! "<<endl;
            else 
            cout << "try again" <<endl;
            passwordSecondSheet << passPhrase <<endl; 
        }        
    }

    passwordSheet.close();
    passwordSecondSheet.close();
}