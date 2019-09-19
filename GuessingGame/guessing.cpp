#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
  srand(time(NULL)); //setting random seed
  bool stillPlaying = true; //keeping track of whether playing or not
  while (stillPlaying == true) { //while the game is still going
    cout << "Welcome to the guessing game! Guess the number below." << endl;
    int random = rand() % 100 + 1; //generating random number
    //cout << random << endl;
    int guessCounter = 1; //keeping track of guesses
    int input = -1;
    while (input != random) { //while the number has not been guessed
      cin >> input; //taking in input
      if (input <= 100 && input >= 0) { //making sure input is valid
	if (input == random) {//if guess is right
	  cout << "You are correct!" << endl;
	  cout << "You took " << guessCounter << " tries." << endl;
	}
	else if (input < random) {//if guess is too low
	  cout << "Number is too low. Try again." << endl;
	  guessCounter += 1;
	}
	else if (input > random) {//if guess is too high
	  cout << "Number is too high. Try again." << endl;
	  guessCounter += 1;
	}
      }
      else {//if input is invalid
	cout << "Invalid input. Try again." << endl;
      }
    }
    char yesNo; //keeping track of answer for playing again
    cout << "Would you like to play again? (y/n)" << endl; 
    cin >> yesNo;
    if (yesNo == 'y') {
      stillPlaying = true;
    }
    else {
      stillPlaying = false;
      cout << "Thanks for playing!" << endl;
    }
  }
}
