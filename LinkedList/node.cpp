#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node() {
  student = NULL;
  next = NULL;
}

Node::~Node() {
  delete &student;
  next = NULL;
}

Student* Node::getStudent() {
  return student;
}

void Node::setStudent(Student* inStudent) {
  student = inStudent;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* inNext) {
  next = inNext;
}
