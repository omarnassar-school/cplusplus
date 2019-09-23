#include <iostream>
#include <cstring>

using namespace std;

bool checkWin(int);
bool checkTie();
void printBoard(char* Prnt[3][3]);
void clearBoard(char* Prnt[3][3]);

int main() {
  char board[3][3];
  char* boardPrnt[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      boardPrnt[i][j] = &board[i][j];
    }
  }
  clearBoard(boardPrnt);
  char input[2];
  char player = 'O';

  bool stillPlaying = true;
  while (stillPlaying == true) {
    printBoard(boardPrnt);
    if (player == 'X') {
      player = 'O';
    }
    else {
      player = 'X';
    }
    cin.get(input, 3);
    cin.clear();
    cin.ignore(1000000, '\n');
    if ((input[0] == 'a' || input[0] == 'b' || input[0] == 'c')
	&& (input[1] == '1' || input [1] == '2' || input[1] == '3')) {
      board[(int) input[0] - 'a'][(int) input[1] - '1'] = player;
    }
    //stillPlaying = false;
  }
  printBoard(boardPrnt);
  
  return 0;
}

bool checkWin(int player) {
  
}

bool checkTie() {

}

void printBoard(char* Prnt[3][3]) {
  cout << "  1 2 3" << endl;
  cout << "a " << *Prnt[0][0] << " " << *Prnt[0][1] << " " << *Prnt[0][2] << endl;
  cout << "b " << *Prnt[1][0] << " " << *Prnt[1][1] << " " << *Prnt[1][2] << endl;
  cout << "c " << *Prnt[2][0] << " " << *Prnt[2][1] << " " << *Prnt[2][2] << endl;
}

void clearBoard(char* Prnt[3][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      *Prnt[i][j] = ' ';
    }
  }
}
