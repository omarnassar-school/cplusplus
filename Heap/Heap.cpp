/*Author: Omar Nassar
 *Date: 2/6/20
 *This is a program that creates a heap that can take input from either the console or a text file.
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
//#include "Node.h"

using namespace std;

void parseInput(int*& parsed, char input[], int &counter);

int main() {
  int method;
  char input[1000];
  int* parsed;
  int parsedSize;
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
  parseInput(parsed, input, parsedSize);
  /*for (int i = 0; i < sizeof(parsed)/sizeof(parsed[0]); i++) {
    cout << parsed[i] << " ";
  }*/
  cout << parsed[0];
  return 0;
}

void parseInput(int*& parsed, char input[], int &counter) {
  //cout << "works so far";
  int pointers[2];
  int value;
  counter = 1;
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
      /*int temp[counter];
      for (int i = 0; i < counter; i++) {
	temp[i] = parsed[i];
      }
      counter++;
      //cout << "check1" << endl;
      value = atoi(newArray);
      //cout << "check2" << endl;
      parsed = new int[counter + 1];
      for (int i = 0; i < counter; i++) {
	parsed[i] = temp[i];
      }
      //cout << "check3" << endl;
      parsed[counter] = value;
      //cout << "check4" << endl;
      //cout << parsed[counter] << endl;*/
      int* temp;
      temp = parsed;
      parsed = new int[counter];
      if (counter > 1) {
	for (int i = 0; i < counter - 2; i++) {
	  parsed[i] = temp[i];
	}
      }
      parsed[counter - 1] = atoi(newArray);
      counter++;
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    j = j + 1;
  }
  int* temp;
  temp = parsed;
  parsed = new int[counter];
  if (counter > 1) {
    for (int i = 0; i < counter - 2; i++) {
      parsed[i] = temp[i];
    }
  }
  parsed[counter - 1] = atoi(newArray);
  counter++;
  /*int temp[counter];
  for (int i = 0; i < counter; i++) {
    temp[i] = parsed[i];
  }
  counter++;
  //cout << "check5" << endl;
  value = atoi(newArray);
  //cout << "check6" << endl;
  parsed = new int[counter + 1];
  for (int i = 0; i < counter - 1; i++) {
    parsed[i] = temp[i];
  }
  //cout << "check7" << endl;
  parsed[counter] = value;
  //cout << "check8" << endl;
  //cout << "got it" << endl;
  //cout << parsed[counter] << endl;*/
  parsed[counter] = atoi(newArray);
  cout << parsed[0] << endl;
  cout << parsed[1] << endl;
  cout << parsed[2] << endl;
  cout << parsed[3] << endl;
  cout << parsed[4] << endl;
  cout << parsed[counter] << endl;
  cout << counter << endl;
  /*for (int i = 0; i < sizeof(parsed)/sizeof(parsed[0]); i++) {
    cout << parsed[i] << " ";
    }*/
}
