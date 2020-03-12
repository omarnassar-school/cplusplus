#ifndef Node_h
#define Node_h

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  //Getters
  Node* getParent();
  Node* getLeft();
  Node* getRight();
  Node* getSibling();
  bool getColor();
  int getValue();
  //Setters
  void setParent(Node*);
  void setLeft(Node*);
  void setRight(Node*);
  void setValue(int);
  void setSibling(Node*);
  void setColor(bool);
 private:
  Node* parent;
  Node* left;
  Node* right;
  Node* sibling;
  bool color; //false is black, true is red
  int value;
};

#endif
