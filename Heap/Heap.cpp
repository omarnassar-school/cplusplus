/*Author: Omar Nassar
 *Date: 2/6/20
 *This is a program that creates a heap that can take input from either the console or a text file.
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Node.h"

using namespace std;

Node* parseInput(char input[]);

int main() {
  int method;
  char input[1000];
  Node* head;
  cout << endl << "How would you like to input your numbers? (1 for console, 2 for file)" << endl << ">> ";
  cin >> method;
  cin.clear();
  cin.ignore(1000000, '\n');
  if (method == 1) {
    cout << endl << "Please input your numbers with spaces in between them here: " << endl;
    cin.get(input, 1000);
    cin.clear();
    cin.ignore(1000000, '\n');
    //cout << input << endl;
  }
  else if (method == 2) {
  }
  else {
    return 0;
  }
  head = parseInput(input);
  
  return 0;
}

Node* parseInput(char input[]) {
  Node* head;
  Node* current;
  current = head;
  //cout << "works so far";
  int pointers[2];
  int value;
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0]];
      for (int i = pointers[0] + 1; i < pointers[1]; i++) {
	newArray[j] = input[i];
	j = j + 1;
      }
      cout << "check1" << endl;
      current -> setValue(atoi(newArray));
      cout << "check2" << endl;
      current = current -> getNext();
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    j = j + 1;
  }
  cout << "check3" << endl;
  current -> setValue(atoi(newArray));
  cout << "check4" << endl;
  return head;
}
