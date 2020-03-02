#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
  previous = NULL;
  next = NULL;
}

Node::~Node() {
  delete &value;
  previous = NULL;
  next = NULL;
}

//Getters

Node* Node::getPrevious() {
  return previous;
}

Node* Node::getNext() {
  return next;
}

int Node::getValue() {
  return value;
}

//Setters

void Node::setPrevious(Node* inPrevious) {
  previous = inPrevious;
}

void Node::setNext(Node* inNext) {
  next = inNext;
}

void Node::setValue(int inValue) {
  value = inValue;
}
