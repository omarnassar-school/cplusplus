/*Author: Omar Nassar
 *Date: 9/25/19
 *This is a 2 player Tic Tac Toe game in the terminal
 */

#include <iostream>
#include <cstring>

using namespace std;

bool checkWin(char* Prnt[3][3], char player); //function for checking wins
bool checkTie(char* Prnt[3][3]); //function for checking ties
void printBoard(char* Prnt[3][3]); //function for printing the board
void clearBoard(char* Prnt[3][3]); //function for clearing the board

int main() {
  cout << "Welcome to Tic Tac Toe. Enter a row followed by a column to choose your spot." << endl;
  char board[3][3]; //creating the board
  char* boardPrnt[3][3]; //pointer for board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      boardPrnt[i][j] = &board[i][j]; //assigning pointer the same value as the board
    }
  }
  clearBoard(boardPrnt); //initializing the board
  char input[2]; //storing input
  char player = 'O'; //start with O because it will change to X
  int x_wins = 0; // x win counter
  int o_wins = 0; //o win counter
  bool stillPlaying = true; //boolean to see if game is still going on
  bool game = true; //boolean to see if player still wants to play
  while (game == true) {
    printBoard(boardPrnt); 
    while (stillPlaying == true) {
      if (player == 'X') {//switching turns
	player = 'O';
      }
      else {
	player = 'X';
      }
      cin.get(input, 3); //taking in input for playing
      cin.clear();
      cin.ignore(1000000, '\n');
      //making sure input is valid
      if ((input[0] == 'a' || input[0] == 'b' || input[0] == 'c') 
	  && (input[1] == '1' || input[1] == '2' || input[1] == '3')
	  && (board[(int) input[0] - 'a'][(int) input[1] - '1'] == ' ')) {
	board[(int) input[0] - 'a'][(int) input[1] - '1'] = player;
      }
      else {
	cout << "Invalid output. Try again." << endl;
	if (player == 'X') {//giving player another attempt
	  player = 'O';
	}
	else {
	  player = 'X';
	}
      }
      printBoard(boardPrnt);
      if (checkWin(boardPrnt, player) == true) {//checking for wins
	cout << player << " wins!" << endl;
	if (player == 'X') {
	  x_wins++;
	}
	else {
	  o_wins++;
	}
	stillPlaying = false;
	cout << "X wins: " << x_wins << endl;
	cout << "O wins: " << o_wins << endl;
      }
      else if (checkTie(boardPrnt) == true) {//checking for ties
	cout << "Tie Game." << endl;
	stillPlaying = false;
      }
    }
    cout << "Would you like to play again? (y/n)" << endl;
    char answer;
    cin >> answer;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (answer == 'y') {
      clearBoard(boardPrnt);
      stillPlaying = true;
      player = 'O';
    }
    else if (answer == 'n') {
      cout << "Thanks for playing!" << endl;
      break;
    }
    else {//player can only input y or n
      cout << "Invalid answer. Try again." << endl;
    }
  }
  return 0;
}

bool checkWin(char* Prnt[3][3], char player) {//checking for wins (taken from last year)
  if (*Prnt[0][0] == player && *Prnt[0][1] == player && *Prnt[0][2] == player) {//top row
    return true;
  }
  if (*Prnt[0][0] == player && *Prnt [1][1] == player && *Prnt [2][2] == player) {//top left to bottom right diagonal
    return true;
  }
  if (*Prnt[1][0] == player && *Prnt[1][1] == player && *Prnt[1][2] == player) {//middle row
    return true;
  }
  if (*Prnt[2][0] == player && *Prnt[2][1] == player && *Prnt[2][2] == player) {//bottom row
    return true;
  }
  if (*Prnt[0][0] == player && *Prnt[1][0] == player && *Prnt[2][0] == player) {//left column
    return true;
  }
  if (*Prnt[0][1] == player && *Prnt[1][1] == player && *Prnt[2][1] == player) {//middle column
    return true;
  }
  if (*Prnt[0][2] == player && *Prnt[1][2] == player && *Prnt[2][2] == player) {//right column
    return true;
  }
  if (*Prnt[0][2] == player && *Prnt [1][1] == player && *Prnt [2][0] == player) {//top right to bottom left diagonal
    return true;
  }
  return false;
}

bool checkTie(char* Prnt[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (*Prnt[i][j] == ' ') {//if there are any empty spots then no tie
	return false;
      }
    }
  }
  return true; //otherwise there is a tie
  //this happens after checking for a win so board can be full but still have a win
}

void printBoard(char* Prnt[3][3]) {//printing each line manually
  cout << "  1 2 3" << endl;
  cout << "a " << *Prnt[0][0] << " " << *Prnt[0][1] << " " << *Prnt[0][2] << endl;
  cout << "b " << *Prnt[1][0] << " " << *Prnt[1][1] << " " << *Prnt[1][2] << endl;
  cout << "c " << *Prnt[2][0] << " " << *Prnt[2][1] << " " << *Prnt[2][2] << endl;
}

void clearBoard(char* Prnt[3][3]) {//resetting all values
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      *Prnt[i][j] = ' ';
    }
  }
}
