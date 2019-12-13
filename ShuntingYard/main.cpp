/* Author: Omar Nassar
 * Date: 12/5/2019
 * This is a program that can translate infix to postfix and create an expression tree.
 * This can then be outputted as either infix, prefix, or postfix.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"


using namespace std;

void parseInput(vector<char*> &parsedInput, char input[100]);

int main() {
  char input[100];
  vector<char*> parsedInput;
  cout << "Enter an infix expression" << endl << endl;
  cin.get(input, 100);
  cin.clear();
  cin.ignore(1000000, '\n');
  parseInput(parsedInput, input);
  char method[7];
  while (true) {
    cout << endl << "What way would you like to output this expression? (Infix, Prefix, Postfix)" << endl << endl;
    cin.get(method, 7);
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
  cout << "works" << endl;
}
