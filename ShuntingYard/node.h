#ifndef node_h
#define node_h

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  //Getters
  Node* getLeft();
  Node* getRight();
  char getValue();
  //Setters
  void setLeft(Node*);
  void setRight(Node*);
  void setValue(char);
 private:
  Node* left;
  Node* right;
  char value;
};

#endif
