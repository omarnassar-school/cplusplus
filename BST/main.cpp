#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include "node.h"

using namespace std;

struct Trunk {
  Trunk *prev;
  char* str;

  Trunk(Trunk *prev, char* str) {
    this -> prev = prev;
    this -> str = str;
  }
};

void parseInput(char input[]);
void addNode(int value, Node* current);
void printTree(Node* root, Trunk *prev, bool isLeft);
void showTrunks(Trunk *p);

Node* head = NULL;

int main() {
  int method;
  char fileName[20];
  char input[1000];
  int* parsed;
  cout << endl << "How would you like to initially input your numbers? (1 for console, 2 for file)" << endl << ">> ";
  cin >> method;
  cin.clear();
  cin.ignore(1000000, '\n');
  if (method == 1) {//getting input from console, store in char array
    cout << endl << "Please input your numbers with spaces in between them here: " << endl << ">> ";
    cin.get(input, 1000);
    cin.clear();
    cin.ignore(1000000, '\n');
    //cout << input << endl;
  }
  else if (method == 2) {//getting input from file, store in char array
    cout << endl << "What is the name of the file?" << endl << ">> ";
    cin.get(fileName, 20);
    cin.clear();
    cin.ignore(1000000, '\n');
    streampos size;
    ifstream file(fileName, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
      //cout << input << endl;
    }
  }
  parseInput(input);
  printTree(head, NULL, false);
  
  return 0;
}

void parseInput(char input[]) {//remove spaces between the chars, make int pointer (array)
  /*This works by finding a space and adding a pointer, then moving forward in the array until it finds another
   *space. It then adds another pointer and adds the characters between the spaces to a new char array, which is then
   *turned to an int and added to the int pointer. This method was originally created by Zareef Amyeen, but I modified
   *it for use with an int pointer instead of a vector. 
   */
  int counter;
  int* parsed;
  int pointers[2];
  int value;
  int* temp;
  counter = 1;
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0]];
      for (int i = pointers[0] + 1; i < pointers[1]; i++) {
	newArray[j] = input[i];
	//cout << newArray[i] << endl;
	j = j + 1;
      }
      newArray[j] = '\0';
      temp = parsed;
      parsed = new int[counter];
      if (counter > 1) {
	for (int i = 0; i < counter - 1; i++) {
	  parsed[i] = temp[i];
	  //cout << parsed[i] << endl;
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
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    //cout << newArray[j];
    j = j + 1;
  }
  newArray[j] = '\0';
  temp = parsed;
  parsed = new int[counter];
  if (counter > 1) {
    for (int i = 0; i < counter - 1; i++) {
      parsed[i] = temp[i];
      //cout << parsed[i] << endl;
    }
  }
  parsed[counter - 1] = atoi(newArray);
  /*for (int i = 0; i < counter; i++) {
    cout << endl << parsed[i] << endl;
    }*/
  cout << "works" << endl;
  for (int i = 0; i < counter; i++) {
    cout << "fault?" << endl;
    addNode(parsed[i], head);
  }
}

void addNode(int value, Node* current) {
  cout << "Works?" << endl;
  if (head == NULL) {
    head -> setValue(value);
  }
  else {
    if (value > current -> getValue()) {
      if (current -> getRight() == NULL)
	current -> getRight() -> setValue(value);
      else
	addNode(value, current -> getRight());
    }
    else if (value < current -> getValue()) {
      if (current -> getLeft() == NULL)
	current -> getLeft() -> setValue(value);
      else
	addNode(value, current -> getLeft());
    }
    else {
      cout << "You cannot have duplicate values." << endl;
    }
  }
}

//https://www.techiedelight.com/c-program-print-binary-tree/
void showTrunks(Trunk *p) {
  if (p == NULL)
    return;

  showTrunks(p -> prev);

  cout << p -> str;
}

//https://www.techiedelight.com/c-program-print-binary-tree
void printTree(Node* root, Trunk *prev, bool isLeft) {
  if (root == NULL)
    return;

  char* prev_str = (char*)("    ");
  Trunk *trunk = new Trunk(prev, prev_str);
  printTree(root -> getLeft(), trunk, true);
  if (!prev)
    trunk -> str = (char*)("---");
  else if (isLeft) {
    trunk -> str = (char*)(".---");
    prev_str = (char*)("   |");
  }
  else {
    trunk -> str = (char*)("`---");
    prev -> str = prev_str;
  }
  showTrunks(trunk);
  cout << root -> getValue() << endl;

  if (prev)
    prev -> str = prev_str;
  trunk -> str = (char*)("   |");
  printTree(root -> getRight(), trunk, false);
}
