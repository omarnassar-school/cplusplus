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
  /*int method;
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
  /*while (true) {
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
    }*/
  addNode(10, head);
  printTree(head, NULL, NULL);
  addNode(3, head);
  printTree(head, NULL, NULL);
  addNode(54, head);
  printTree(head, NULL, NULL);
  addNode(6, head);
  printTree(head, NULL, NULL);
  addNode(2, head);
  printTree(head, NULL, NULL);
  addNode(9, head);
  printTree(head, NULL, NULL);
  addNode(1, head);
  printTree(head, NULL, NULL);
  addNode(12, head);
  printTree(head, NULL, NULL);
  addNode(43, head);
  printTree(head, NULL, NULL);
  addNode(94, head);
  printTree(head, NULL, NULL);
  addNode(13, head);
  printTree(head, NULL, NULL);
  return 0;
}

void parseInput(char input[]) {//remove spaces between the chars, make int pointer (array)
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

void addNode(int value, Node* current) {//insert from BST
  if (head == NULL) {
    head = new Node();
    head -> setValue(value);
    current = head;
  }
  else {
    if (value > current -> getValue()) {
      if (current -> getRight() == NULL) {
	current -> setRight(new Node());
	current -> getRight() -> setParent(current);
	current -> getRight() -> setValue(value);
	current = current -> getRight();
      }
      else 
	addNode(value, current -> getRight());
    }
    else if (value < current -> getValue()) {
      if (current -> getLeft() == NULL) {
	current -> setLeft(new Node());
	current-> getLeft() -> setParent(current);
	current -> getLeft() -> setValue(value);
        
        current = current -> getLeft();
      }
      else
	addNode(value, current -> getLeft());
    }
    else {
      cout << "You cannot have duplicate values." << endl;
    }
  }
  checkTree(current);
}

void checkTree(Node* current) {
  Node* parent = NULL;
  Node* grandParent = NULL;
  //cout << "got here" << endl;
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
	  rotate(parent, true);
	  current = parent;
	  parent = current -> getParent();
	}
	//current is left child
	rotate(grandParent, false);
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
  //cout << "got here 2" << endl;
  if (method) {//left rotation
    //cout << "got here 3" << endl;
    Node* right = current -> getRight();
    current -> setRight(current -> getLeft());

    if (current -> getRight() != NULL)
      current -> getRight() -> setParent(current);

    right -> setParent(current -> getParent());

    if (current -> getParent() == NULL)
      head = right;

    else if (current == current -> getParent() -> getLeft())
      current -> getParent() -> setLeft(right);

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
