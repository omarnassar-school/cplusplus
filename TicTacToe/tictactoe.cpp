#include <iostream>
#include <cstring>

using namespace std;

bool checkWin(int);
bool checkTie();
void printBoard();

int main() {
  
  int board[3][3];
  const int BLANK = 0;
  const int X_MOVE = 1;
  const int O_MOVE = 2;
  const int X_TURN = 0;
  const int O_TURN = 1;
  int turn = X_TURN;
  int X_wins = 0;
  int O_wins = 0;

  bool stillPlaying = true;
  while (stillPlaying == true) { //&& checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
    printBoard();
  }
  
  return 0;
}

bool checkWin(int player) {
  if (player == 0) {
    return false;
  }
  else {
    return true;
  }
}

bool checkTie() {

}

void printBoard() {
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    char output = ('a' + row) + "\t";
    for (int column = 0; column < 3; column++) {
      //if (board[row][column] == BLANK) {
	output += "\t";
	//}
	//else if (board[row][column] == X_MOVE) {
	//output += "X\t";
	//      }
	//      else if (board[row][column] == O_MOVE) {
	//	output += "0\t";
	//      }
    }
    cout << output << endl;
