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
Node* search(int value, Node* current);
void remove(int value);
Node* BSTsuccessor(Node* current);
Node* findLeast(Node* current, bool LR);
Node* twoChildren(Node* current);
void RBTremove(Node* current);
void fixDouble(Node* current);
bool hasRed(Node* current);

Node* head = NULL;
const bool red = true;
const bool black = false;

int main() {
  char fileName[20];
  char input[1000];
  int* parsed;
  int value;
  char yn;
  int intIn;

  cout << endl << "Would you like to input from a file? (y/n)" << endl << ">> ";
  cin >> yn;
  cin.clear();
  cin.ignore(1000000, '\n');
  if (yn == 'y') {
    cout << endl << "What is the name of your file?" << endl << ">> ";
    cin.get(fileName, 20);
    cin.clear();
    cin.ignore(1000000, '\n');
    streampos size;
    ifstream file(fileName, ios::in | ios::binary | ios::ate);
    //ifstream file("Numbers3.txt", ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
      //cout << input << endl;
    }
    parseInput(input);
    cout << endl;
    printTree(head, NULL, NULL);
  }
  
  while (true) {
    cout << endl << "What would you like to do?" << endl;
    cout << "1: INSERT" << endl;
    cout << "2: SEARCH" << endl;
    cout << "3: DELETE" << endl;
    cout << "4: PRINT" << endl;
    cout << "5: QUIT" << endl;
    cout << ">> ";
    cin >> intIn;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (intIn == 1) {
      cout << endl << "What number would you like to insert?" << endl << ">> ";
      cin >> value;
      cin.clear();
      cin.ignore(1000000, '\n');
      addNode(value, head);
      cout << endl;
      printTree(head, NULL, NULL);
    }
    else if (intIn == 2) {
      cout << endl << "What number would you like to search for?" << endl << ">> ";
      cin >> value;
      cin.clear();
      cin.ignore(100000, '\n');
      Node* temp = search(value, head);
      if (temp != NULL)
	cout << endl << value << " is in the tree." << endl;
      else
	cout << endl << value << " is not in the tree." << endl;
      
      temp = NULL;
      delete temp;
    }
    else if (intIn == 3) {
      cout << endl << "What number would you like to delete?" << endl << ">> ";
      cin >> value;
      cin.clear();
      cin.ignore(1000000, '\n');
      remove(value);
    }
    else if (intIn == 4) {
      cout << endl;
      printTree(head, NULL, NULL);
    }

    else if (intIn == 5)
      break;
    
    else
      cout << endl << "Invalid Input." << endl;
  }
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
	j = j + 1;
      }
      newArray[j] = '\0';
      temp = parsed;
      parsed = new int[counter];
      if (counter > 1) {
	for (int i = 0; i < counter - 1; i++) {
	  parsed[i] = temp[i];
	}
      }
      parsed[counter - 1] = atoi(newArray);
      counter = counter + 1;
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    j = j + 1;
  }
  newArray[j] = '\0';
  temp = parsed;
  parsed = new int[counter];
  if (counter > 1) {
    for (int i = 0; i < counter - 1; i++) {
      parsed[i] = temp[i];
    }
  }
  parsed[counter - 1] = atoi(newArray);
  for (int i = 0; i < counter; i++) {
    addNode(parsed[i], head);
    //cout << endl;
    //printTree(head, NULL, NULL);
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
      cout << endl << "You cannot have duplicate values." << endl;
      return;
    }
  }
  checkTree(current);
  /*cout << endl;
    printTree(head, NULL, NULL);*/
  return;
}

void checkTree(Node* current) {
  Node* parent = NULL;
  Node* grandParent = NULL;
  //cout << "got here" << endl;
  while (current != head && current -> getColor() != black && current -> getParent() -> getColor() == red) {
    //cout << "checking: " << current -> getValue() << endl;
    parent = current -> getParent();
    grandParent = parent -> getParent();
    //printTree(head, NULL, NULL);
    if (parent == grandParent -> getLeft()) {//parent is a left child
      Node* uncle = grandParent -> getRight();
      if (uncle != NULL && uncle -> getColor() == red) {//uncle is red
	grandParent -> setColor(red);
	parent -> setColor(black);
	uncle -> setColor(black);
	current = grandParent;
	//printTree(head, NULL, NULL);
      }
      else {//uncle is black
	if (current == parent -> getRight()) {//current is right child
	  rotate(parent, true);
	  current = parent;
	  parent = current -> getParent();
	}
	//printTree(head, NULL, NULL);
	//current is left child
	rotate(grandParent, false);
	bool tempColor = parent -> getColor();
	parent -> setColor(grandParent -> getColor());
	grandParent -> setColor(tempColor);	
	current = parent;
	//printTree(head, NULL, NULL);
      }
      uncle = NULL;
      delete uncle;
    }    
    else {//parent is a right child
      Node* uncle = grandParent -> getLeft();
      
      if (uncle != NULL && uncle -> getColor() == red) {//uncle is red
	grandParent -> setColor(red);
	parent -> setColor(black);
	uncle -> setColor(black);
	current = grandParent;
	//printTree(head, NULL, NULL);
      }
      else {//uncle is black
	if (current == parent -> getLeft()) {//current is left child
	  rotate(parent, false);
	  current = parent;
	  parent = current -> getParent();
	}
	//printTree(head, NULL, NULL);
	//current is right child
	rotate(grandParent, true);
	bool tempColor = parent -> getColor();
	parent -> setColor(grandParent -> getColor());
	grandParent -> setColor(tempColor);
	current = parent;
      }
      uncle = NULL;
      delete uncle;
      //printTree(head, NULL, NULL);
    }
  }
  parent = NULL;
  delete parent;
  grandParent = NULL;
  delete grandParent;
  head -> setColor(black);
  //printTree(head, NULL, NULL);
}

void rotate(Node* current, bool method) {//true is left, false is right
  /*char* LR;
  if (method)
    LR = (char*)("left");
  else
    LR = (char*)("right");
  
  cout << "Rotating " << current -> getValue() << " " << LR << endl;
  */
  
  if (method) {//left rotation
    /*Node* right = current -> getRight();
    current -> setRight(right -> getLeft());

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
    delete right;*/

    Node* right = current -> getRight();

    if (current == head)
      head = right;

    if (current -> getParent() != NULL) {
      if (current == current -> getParent() -> getLeft())
	current -> getParent() -> setLeft(right);
      else
	current -> getParent() -> setRight(right);
    }
    right -> setParent(current -> getParent());
    current -> setParent(right);

    current -> setRight(right -> getLeft());

    if (right -> getLeft() != NULL)
      right -> getLeft() -> setParent(current);

    right -> setLeft(current);

    right = NULL;
    delete right;
  }
  
  else {//right rotation
    /*Node* left = current -> getLeft();
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
    delete left;*/

    Node* left = current -> getLeft();

    if (current == head)
      head = left;

    if (current -> getParent() != NULL) {
      if (current == current -> getParent() -> getLeft())
	current -> getParent() -> setLeft(left);
      else
	current -> getParent() -> setRight(left);
    }
    left -> setParent(current -> getParent());
    current -> setParent(left);

    current -> setLeft(left -> getRight());

    if (left -> getRight() != NULL)
      left -> getRight() -> setParent(current);

    left -> setRight(current);

    left = NULL;
    delete left;
  }
}

Node* search(int value, Node* current) {//searching for a node with a certain value
  if (value == current -> getValue())
    return current;

  else if (value > current -> getValue()) {
    if (current -> getRight() == NULL)
      return NULL;
    else
      search(value, current -> getRight());
  }

  else if (value < current -> getValue()) {
    if (current -> getLeft() == NULL)
      return NULL;
    else
      search(value, current -> getLeft());
  }

  else {
    return NULL;
  }
}

void remove(int value) {
  Node* temp = search(value, head);
  if (temp == NULL) {
    cout << endl << "That number is not in the tree." << endl;
    return;
  }
  
  cout << endl << "Removing: " << temp -> getValue() << endl;

  //if the tree only has a head
  if (temp -> getParent() == NULL && temp -> getLeft() == NULL && temp -> getRight() == NULL) {
    head = NULL;
    return;
  }
  
  RBTremove(temp);
  temp = NULL;
  delete temp;
  cout << endl;
  printTree(head, NULL, NULL);
}

void RBTremove (Node* current) {
  Node* temp = BSTsuccessor(current);
  /*if (temp != NULL)
    cout << "Replacing with: " << temp -> getValue() << endl;
  else
    cout << "No replacement needed." << endl;
  */
  bool doubleBlack = false;
  
  Node* parent = current -> getParent();

  if (temp == NULL) {
    if (current -> getColor() == black)
      fixDouble(current);
    else {
      //if current's sibling isn't red, make it red
      if (current = parent -> getRight()) {
	if (parent -> getLeft() != NULL)
	  current -> getParent() -> getLeft() -> setColor(red);
      }
      else {
	if (parent -> getRight() != NULL)
	  current -> getParent() -> getRight() -> setColor(red);
      }
    }
    
    if (current == parent -> getLeft())
      parent -> setLeft(NULL);
    else
      parent -> setRight(NULL);
    
    current -> ~Node();
    parent = NULL;
    delete current;
    delete parent;
    delete temp;
    return;
  }
  
  if (current -> getColor() == black && temp -> getColor() == black)
    doubleBlack = true;
  
  if (current -> getLeft() == NULL || current -> getRight() == NULL) {
    if (current == head) {
      current -> setValue(temp -> getValue());
      current -> setLeft(NULL);
      current -> setRight(NULL);
      temp = NULL;
      delete temp;
    }
    else {
      if (current == parent -> getLeft())
	parent -> setLeft(temp);
      else
	parent -> setRight(temp);
      
      current -> ~Node();
      current = NULL;
      delete current;
      
      temp -> setParent(parent);
      if (doubleBlack)
	fixDouble(temp);
      else
	temp -> setColor(black);
    }
    
    temp = NULL;
    parent = NULL;
    delete parent;
    delete temp;
    return;
  }
  
  int tempVal;
  tempVal = current -> getValue();
  current -> setValue(temp -> getValue());
  temp -> setValue(tempVal);
  /*
  cout << "Recursely calling with: " << temp -> getValue() << endl;
  
  cout << endl;
  printTree(head, NULL, NULL);
  */
  RBTremove(temp);
}

void fixDouble(Node* current) {
  //cout << "Called with: " << current -> getValue() << endl << endl;
  /*printTree(head, NULL, NULL);
  if (current == head)
    return;
  */
  
  Node* sibling;
  Node* parent = current -> getParent();
  bool LR;
  
  if (current == parent -> getRight()) {
    sibling = parent -> getLeft();
    LR = false;
  }
  else {
    sibling = parent -> getRight();
    LR = true;
  }
  
  if (sibling == NULL) {
    fixDouble(parent);
  }
  else {
    if (sibling -> getColor() == red) {
      parent -> setColor(red);
      sibling -> setColor(black);
      rotate(parent, LR);
      fixDouble(current);
    }
    else {
      if (hasRed(sibling)) {
	if (sibling -> getLeft() != NULL && sibling -> getLeft() -> getColor() == red) {
	  if (sibling == sibling -> getParent() -> getLeft()) {
	    sibling -> getLeft() -> setColor(sibling -> getColor());
	    sibling -> setColor(parent -> getColor());
	    rotate(parent, false);
	  }
	  else {
	    sibling -> getLeft() -> setColor(parent -> getColor());
	    rotate(sibling, false);
	    rotate(parent, true);
	  }
	}
	else {
	  if (sibling == sibling -> getParent() -> getLeft()) {
	    sibling -> getRight() -> setColor(parent -> getColor());
	    rotate(sibling, true);
	    rotate(parent, false);
	  }
	  else {
	    sibling -> getRight() -> setColor(sibling -> getColor());
	    sibling -> setColor(parent -> getColor());
	    rotate(parent, true);
	  }
	}
	parent -> setColor(black);
      }
      else {
	sibling -> setColor(red);
	if (parent -> getColor() == black) {
	  fixDouble(parent);
	}
	else
	  parent -> setColor(black);
      }
    }
  }
  /*cout << "Rotated tree:" << endl;
    printTree(head, NULL, NULL);*/
}

Node* BSTsuccessor(Node* current) {
  //no children
  if (current -> getRight() == NULL && current -> getLeft() == NULL)
    return NULL;
  //right only
  else if (current -> getLeft() == NULL)
    return current -> getRight();
  //left only
  else if (current -> getRight() == NULL)
    return current -> getLeft();
  //two children
  else
    return twoChildren(current);  
}

Node* twoChildren(Node* current) {
  //min in right subtree
  if (current -> getRight() -> getLeft() != NULL)
    return findLeast(current -> getRight(), true);
  //max in left subtree
  else if (current -> getLeft() -> getRight() != NULL)
    return findLeast(current -> getLeft(), false);
  //none of childtren have subtrees
  else
    return current -> getRight();
}

Node* findLeast(Node* current, bool LR) {//true for left min, false for right max
  if (LR) {
    while (current -> getLeft() != NULL)
      current = current -> getLeft();
  }
  else {
    while (current -> getRight() != NULL)
      current = current -> getRight();
  }
  return current;
}

bool hasRed(Node* current) {
  if (current -> getLeft() != NULL) {
    //cout << current -> getLeft() -> getValue() << endl;
    if (current -> getLeft() -> getColor() == red)
      return true;
  }

  if (current -> getRight() != NULL) {
    //cout << current -> getRight() -> getValue() << endl;
    if (current -> getRight() -> getColor() == red)
      return true;
  }
  //cout << "checking if " << current -> getValue() << " has any red children" << endl;
  //cout << "no red found" << endl;
  
  return false;
}
