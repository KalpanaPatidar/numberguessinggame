#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
public:
    int mynum;  
    int playerGuess;  

    Game() {
        srand(time(0));
        mynum = rand() % 50 + 1;
    }

    void putvalue() {
        cout << "Welcome to the number guessing Game!" << endl;
        cout << "I have selected a number between 1 and 50." << endl;
        cout << "Enter your guess: ";
        cin >> playerGuess;
    }

    void result() {
        int attempts = 20;
        
        while (attempts > 0) {
            try {
                if (playerGuess < 1 || playerGuess > 50) {
                    throw invalid_argument("Invalid number. Please enter a number between 1 and 50.");
                }
                
                if (playerGuess == mynum) {
                    cout << "You win!" << endl;
                    break;
                } else {
                    attempts--;
                    if (attempts == 0) {
                        cout << "You lose! No more attempts left." << endl;
                        break;
                    } else {
                        if (playerGuess < mynum) {
                            cout << "Too low! ";
                        } else {
                            cout << "Too high! ";
                        }
                        cout << "Try again (" << attempts << " attempts left): ";
                        cin >> playerGuess;
                    }
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                cout << "Try again: ";
                cin >> playerGuess;
            }
        }
    }
};

int main() {
    Game numberguess;
    numberguess.putvalue();
    numberguess.result();

    return 0;
}

