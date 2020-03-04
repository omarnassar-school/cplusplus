#ifndef Node_h
#define Node_h

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  //Getters
  Node* getLeft();
  Node* getRight();
  int getValue();
  //Setters
  void setLeft(Node*);
  void setRight(Node*);
  void setValue(int);
 private:
  Node* left;
  Node* right;
  int value;
};

#endif
