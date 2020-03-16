/*Red Black Tree: basically a self balancing binary search tree
 *Author: Omar Nassar
 *Date: 3/12/2020
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include "node.h"
#define RESET "\033[0m"
#define RED "\033[31m"

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
void printTree(Node* root, Trunk *prev, bool isLeft);
void showTrunks(Trunk *p);
void addNode(Node* head);

Node* head = NULL;
const bool red = true;
const bool black = false;

int main() {
  
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
  //cout << "works" << endl;
  for (int i = 0; i < counter; i++) {//add all input to the tree
    //cout << "fault?" << endl;
    //addNode(parsed[i], head);
  }
}


//https://www.techiedelight.com/c-program-print-binary-tree/
void showTrunks(Trunk *p) {//helper method for printing
  if (p == NULL)
    return;
  
  showTrunks(p -> prev);

  cout << p -> str;
}

//https://www.techiedelight.com/c-program-print-binary-tree
void printTree(Node* root, Trunk *prev, bool isLeft) {
  /*what this method does is start out with the leftmost node and then print until the right most
   *i chose to use this method from this site because it was visually appealing :)
   */
  if (root == NULL) //don't print if the tree is nonexistant
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
  if (root -> getColor() == red)
    //https://stackoverflow.com/questions/9158150/colored-output-in-c/9158263
    cout << RED << root -> getValue() << RESET << endl; 
  else
    cout << root -> getValue() << endl;

  if (prev)
    prev -> str = prev_str;
  trunk -> str = (char*)("   |");
  printTree(root -> getRight(), trunk, false);
}

void addNode(int value, Node* current) {//method for adding nodes
  //cout << "Works?" << endl;
  if (head == NULL) {//if the tree doesn't exist
    head = new Node();
    head-> setValue(value);
  }
  else {//if it does exist
    if (value > current -> getValue()) {//if the value is larger than the current node
      if (current -> getRight() == NULL) {//if the node doesn't have a right child
	current -> setRight(new Node());
	current -> getRight() -> setParent(current);
	current -> getRight() -> setValue(value);
      }
      else //if not null, recursively call next right
	addNode(value, current -> getRight());
    }
    else if (value < current -> getValue()) {//if the value is less than the current node
      if (current -> getLeft() == NULL) {//if the node doesn't have a left child
	current -> setLeft(new Node());
	current-> getLeft() -> setParent(current);
	current -> getLeft() -> setValue(value);
      }
      else //if not null, recursively call next left
	addNode(value, current -> getLeft());
    }
    else {//if the value is a duplicate
      //cout << "You cannot have duplicate values." << endl;
    }
  }
}
