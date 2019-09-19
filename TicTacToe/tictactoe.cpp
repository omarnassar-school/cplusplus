#include <iostream>

using namespace std;

boolean checkWin(int);

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

  boolean stillPlaying = true;
  while (stillPlaying) {
    if (checkWin(0) == false) {
      stillPlaying == false;
    }
    else {
      cout << "yeet" << endl;
    }
    
    
  }
  
  return 0;
}

boolean checkWin(int player) {
  if (player == 0) {
    return false;
  }
  else {
    return true;
  }
}
