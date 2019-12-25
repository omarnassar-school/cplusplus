#ifndef node_h
#define node_h

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  Student* getStudent();
  void setStudent(Student*);
  Node* getNext();
  void setNext(Node*);
 private:
  Student* student;
  Node* next;
};

#endif
