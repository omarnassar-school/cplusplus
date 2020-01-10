/* Author: Omar Nassar
 * Date: 12/5/2019
 * This is a program that can translate infix to postfix and create an expression tree.
 * This can then be outputted as either infix, prefix, or postfix.
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stack>
#include <queue>
#include "node.h"


using namespace std;

void parseInput(vector<char*> &parsedInput, char input[100]);
void printVector(vector<char*>);
void intopost(vector<char*>& parsedInput, queue<char*>& Queue);

int main() {
  char input[100];
  vector<char*> parsedInput;
  queue<char*> Queue;
  cout << "Enter an infix expression" << endl << endl;
  cin.get(input, 100);
  cin.clear();
  cin.ignore(1000000, '\n');
  parseInput(parsedInput, input);
  char method[8];
  while (true) {
    cout << endl << "What way would you like to output this expression? (Infix, Prefix, Postfix)" << endl << endl;
    cin.get(method, 8);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(method, "Infix") == 0 || strcmp(method, "infix") == 0) {
      cout << endl << "Infix" << endl;
      break;
    }
    else if (strcmp(method, "Prefix") == 0 || strcmp(method, "prefix") == 0) {
      cout << endl << "Prefix" << endl;
      break;
    }
    else if (strcmp(method, "Postfix") == 0 || strcmp(method, "postfix") == 0) {
      cout << endl << "Postfix" << endl;
      break;
    }
    else {
      cout << endl << "Invalid Input" << endl;
    }
  }
  
  return 0;
}

void parseInput(vector<char*> &parsedInput, char input[100]) {
  //cout << "works" << endl;
  int pointers[2];
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
      newArray[j] = '\0';
      parsedInput.push_back(newArray);
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++){
    newArray[j] = input[i];
    j = j + 1;
  }
  newArray[j] = '\0';
  parsedInput.push_back(newArray);
  printVector(parsedInput);
}

void printVector(vector<char*> parsedInput) {
  for (int i = 0; i < parsedInput.size(); i ++) {
    cout << parsedInput[i];
  }
  cout << endl;
}

void intopost(vector<char*>& parsedInput, queue<char*>& Queue) {
  stack<char*> Stack;
  int i = 0;
  while (i < parsedInput.size()) {
    
  }
}
