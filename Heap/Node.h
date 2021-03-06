#ifndef Node_h
#define Node_h

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  //Getters
  Node* getPrevious();
  Node* getNext();
  int getValue();
  //Setters
  void setPrevious(Node*);
  void setNext(Node*);
  void setValue(int);
 private:
  Node* previous;
  Node* next;
  int value;
};

#endif
