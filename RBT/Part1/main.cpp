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
void addNode(int value, Node* current);
void checkTree(Node* current);
void rotate(Node* current, bool method);

Node* head = NULL;
const bool red = true;
const bool black = false;

int main() {
  int method;
  char fileName[20];
  char input[1000];
  int* parsed;
  int value;
  /*
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
    if (file.is_open()) {//same file reading method from shunting yard and heap
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
      //cout << input << endl;
    }
  }
  else {
    cout << "Invalid Input.";
    return 0;
  }
  parseInput(input);
  cout << endl;
  printTree(head, NULL, false);
  */
  while (true) {
    value = NULL;
    cout << endl << "Would you like to insert another number?" << endl << ">> ";
    cin.get(input, 5);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "yes") == 0 || strcmp(input, "YES") == 0) {
      cout << "Please enter a value: ";
      cin >> value;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl;
      addNode(value, head);
    }
    else
      break;
    printTree(head, NULL, NULL);
  }
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
    addNode(parsed[i], head);
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
    head -> setValue(value);
    checkTree(head);
  }
  else {//if it does exist
    if (value > current -> getValue()) {//if the value is larger than the current node
      if (current -> getRight() == NULL) {//if the node doesn't have a right child
	current -> setRight(new Node());
	current -> getRight() -> setParent(current);
	current -> getRight() -> setValue(value);
	/*if (current -> getLeft() != NULL) {
	  current -> getRight() -> setSibling(current -> getLeft());
	  current -> getLeft() -> setSibling(current -> getRight());
	  }*/
	if (current -> getParent() != NULL)
	  checkTree(current -> getRight());
      }
      else //if not null, recursively call next right
	addNode(value, current -> getRight());
    }
    else if (value < current -> getValue()) {//if the value is less than the current node
      if (current -> getLeft() == NULL) {//if the node doesn't have a left child
	current -> setLeft(new Node());
	current-> getLeft() -> setParent(current);
	current -> getLeft() -> setValue(value);
	/*if (current -> getRight() != NULL) {
	  current -> getLeft() -> setSibling(current -> getRight());
	  current -> getRight() -> setSibling(current -> getLeft());
	  }*/
	if (current -> getParent() != NULL)
	  checkTree(current -> getLeft());
      }
      else //if not null, recursively call next left
	addNode(value, current -> getLeft());
    }
    else {//if the value is a duplicate
      //cout << "You cannot have duplicate values." << endl;
    }
  }
}

void checkTree(Node* current) {
  /*cout << endl << "got here" << endl;
  if (current == head)
    current -> setColor(black);
  else if (current -> getParent() -> getParent() != NULL) {// & current -> getParent() -> getSibling() != NULL) {
    if (current -> getParent() -> getSibling() != NULL) {
      if (current -> getParent() -> getSibling() -> getColor() == red) {
	current -> getParent() -> setColor(black);
	current -> getParent() -> getSibling() -> setColor(black);
	current -> getParent() -> getParent() -> setColor(red);
	//checkTree(current -> getParent() -> getParent());
      }
    }      
    else {
      if (current == current -> getParent() -> getLeft())// && current -> getParent() -> getValue() < current -> getParent() -> getSibling() -> getValue()) //left left
	rotate(current, 1);
      else if (current == current -> getParent() -> getRight())// && current -> getParent() -> getValue() < current -> getParent() -> getSibling() -> getValue()) //left right
	rotate(current, 2);
      else if (current == current -> getParent() -> getLeft() && current -> getParent() -> getValue() > current -> getParent() -> getSibling() -> getValue()) //right left
	rotate(current, 3);
      else if (current == current -> getParent() -> getRight() && current -> getParent() -> getValue() > current -> getParent() -> getSibling() -> getValue()) //right right
	rotate(current, 4);
    }    
    }*/
  Node* parent = NULL;
  Node* grandParent = NULL;

  while (current != head && current -> getColor() != black && current -> getParent() -> getColor() == red) {
    parent = current -> getParent();
    grandParent = parent -> getParent();
    
    if (parent == grandParent -> getLeft()) {//parent is a left child
      Node* uncle = grandParent -> getRight();
      if (uncle != NULL && uncle -> getColor() == red) {//uncle is red
	grandParent -> setColor(red);
	parent -> setColor(black);
	uncle -> setColor(black);
	current = grandParent;
      }
      else {//uncle is black
	if (current == parent -> getRight()) {//current is right child
	  rotate(current, true);
	  current = parent;
	  parent = current -> getParent();
	}
	//current is left child
	rotate(grandParent, false);

	/*if (parent -> getColor() == red)
	  parent -> setColor(black);
	else
	  parent -> setColor(red);
	
	if (grandParent -> getColor() == red)
	  grandParent -> setColor(black);
	else
	  parent -> setColor(red);
	*/
	
	bool tempColor = parent -> getColor();
	parent -> setColor(grandParent -> getColor());
	grandParent -> setColor(tempColor);
	
	current = parent;
      }
      uncle = NULL;
      delete uncle;
    }
    
    
    else {
      Node* uncle = grandParent -> getLeft();

      if (uncle != NULL && uncle -> getColor() == red) {//uncle is red
	grandParent -> setColor(red);
	parent -> setColor(black);
	uncle -> setColor(black);
	current = grandParent;
      }
      else {//uncle is black
	if (current = parent -> getLeft()) {//current is left child
	  rotate(parent, false);
	  current = parent;
	  parent = current -> getParent();
	}
	//current is right child
	rotate(grandParent, true);

	/*if (parent -> getColor() == red)
	  parent -> setColor(black);
	else
	  parent -> setColor(red);

	if (grandParent -> getColor() == red)
	  grandParent -> setColor(black);
	else
	  parent -> setColor(red);
	*/

	bool tempColor = parent -> getColor();
	parent -> setColor(grandParent -> getColor());
	grandParent -> setColor(tempColor);
	
	current = parent;
      }
      uncle = NULL;
      delete uncle;
    }
  }
  
  parent = NULL;
  delete parent;
  grandParent = NULL;
  delete grandParent;
  
  head -> setColor(black);
}

void rotate(Node* current, bool method) {//true is left, false is right
  /*cout << endl << "got here2" << endl;
  Node* tempG = current -> getParent() -> getParent();
  Node* tempP = current -> getParent();
  Node* tempX = current;
  if (method == 1) {//left left
    tempP -> setSibling(tempG -> getSibling());
    if (tempP -> getSibling() != NULL)
      tempP -> getSibling() -> setSibling(tempP);
    tempG -> setLeft(tempP -> getRight());
    tempP -> setRight(tempG);
    tempP -> setParent(tempG -> getParent());
    tempG -> setSibling(tempX);
    tempX -> setSibling(tempG);
    tempG -> setParent(tempP);
    tempP -> setColor(black);
    tempG -> setColor(red);
  }
  else if (method == 2) {//left right
    tempX -> setParent(tempG);
    tempX -> setSibling(tempG -> getRight());
    if (tempX -> getSibling() != NULL)
      tempX -> getSibling() -> setSibling(tempX);
    tempP -> setRight(tempX -> getLeft());
    tempX -> setLeft(tempP);
    tempP -> setParent(tempX);
    rotate(tempP, 1);
  }
  else if (method == 3) {//right left
    tempX -> setParent(tempG);
    tempX -> setSibling(tempG -> getLeft());
    if (tempX -> getSibling() != NULL)
      tempX -> getSibling() -> setSibling(tempX);
    tempP -> setRight(tempX -> getRight());
    tempX -> setLeft(tempP);
    tempP -> setParent(tempX);
    rotate(tempP, 4);
  }
  else if (method == 4) {//right right
    tempP -> setSibling(tempG -> getSibling());
    if (tempP -> getSibling() != NULL)
      tempP -> getSibling() -> setSibling(tempP);
    tempG -> setRight(tempP -> getLeft());
    tempP -> setLeft(tempG);
    tempP -> setParent(tempG -> getParent());
    tempG -> setSibling(tempX);
    tempG -> setSibling(tempX);
    tempG -> setParent(tempP);
    tempP -> setColor(black);
    tempG -> setColor(red);
  }
  else {
    cout << "There's something wrong" << endl;
  }
  //tempG = NULL;
  //delete tempG;
  //tempP = NULL;
  //delete tempP;
  //tempX = NULL;
  //delete tempX;*/
  if (method) {//left rotation
    Node* right = current -> getRight();
    current -> setRight(current -> getLeft());

    if (current -> getRight() != NULL)
      current -> getRight() -> setParent(current);

    right -> setParent(current -> getParent());

    if (current -> getParent() == NULL)
      head = right;

    else if (current = current -> getParent() -> getLeft())
      current -> setParent(right);

    else
      current -> getParent() -> setRight(right);

    right -> setLeft(current);
    current -> setParent(right);

    right = NULL;
    delete right;
  }
  
  else {//right rotation
    Node* left = current -> getLeft();
    current -> setLeft(left -> getRight());

    if (current -> getLeft() != NULL)
      current -> getLeft() -> setParent(current);

    left -> setParent(current -> getParent());

    if (current -> getParent() == NULL)
      head = left;

    else if (current == current -> getParent() -> getLeft())
      current -> getParent() -> setLeft(left);

    else
      current -> getParent() -> setRight(left);

    left -> setRight(current);
    current -> setParent(left);

    left = NULL;
    delete left;
  }
}
