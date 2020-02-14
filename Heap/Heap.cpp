/*Author: Omar Nassar
 *Date: 2/6/20
 *This is a program that creates a heap that can take input from either the console or a text file.
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>

//#include "Node.h"

using namespace std;

void parseInput(int*& parsed, char input[], int &counter);

int main() {
  int method;
  char fileName[20];
  char input[1000];
  int* parsed;
  int parsedSize;
  cout << endl << "How would you like to input your numbers? (1 for console, 2 for file)" << endl << ">> ";
  cin >> method;
  cin.clear();
  cin.ignore(1000000, '\n');
  if (method == 1) {
    cout << endl << "Please input your numbers with spaces in between them here: " << endl << ">> ";
    cin.get(input, 1000);
    cin.clear();
    cin.ignore(1000000, '\n');
    //cout << input << endl;
  }
  else if (method == 2) {
    cout << endl << "What is the name of the file?" << endl << ">> ";
    cin.get(fileName, 20);
    cin.clear();
    cin.ignore(1000000, '\n');
    streampos size;
    ifstream file(fileName, ios::in | ios::binary |ios::ate);
    if (file.is_open()) {
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
    }
  }
  else {
    return 0;
  }
  parseInput(parsed, input, parsedSize);
  cout << endl << "There are: " << parsedSize << " numbers." << endl;
  for (int i = 0; i < parsedSize; i++) {
    cout << parsed[i] << " ";
  }
  cout << endl;
  
  return 0;
}

void parseInput(int*& parsed, char input[], int &counter) {
  int pointers[2];
  int value;
  int* temp;
  counter = 1;
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0] - 1];
      for (int i = pointers[0] + 1; i < pointers[1]; i++) {
	newArray[j] = input[i];
	j = j + 1;
      }
      temp = parsed;
      parsed = new int[counter];
      if (counter > 1) {
	for (int i = 0; i < counter - 1; i++) {
	  parsed[i] = temp[i];
	}
      }
      parsed[counter - 1] = atoi(newArray);
      /*for (int i = 0; i < counter; i++) {
	cout << endl << parsed[i] << endl;
	}*/
      counter = counter + 1;
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0] - 1];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    j = j + 1;
  }
  temp = parsed;
  parsed = new int[counter];
  if (counter > 1) {
    for (int i = 0; i < counter - 1; i++) {
      parsed[i] = temp[i];
    }
  }
  parsed[counter - 1] = atoi(newArray);
  /*for (int i = 0; i < counter; i++) {
    cout << endl << parsed[i] << endl;
    }*/
}
