/*Author: Omar Nassar
 *Date: 2/6/20
 *This is a program that creates a heap that can take input from either the console or a text file.
 */

#include <iostream>
#include <cstring>

using namespace std;

int* parseInput(char input[]);

int main() {
  int method;
  char input[1000];
  int* parsedInput;
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
  parsedInput = parseInput(input);
  
  return 0;
}

int* parseInput(char input[]) {
  //cout << "lol worked";
  
}
