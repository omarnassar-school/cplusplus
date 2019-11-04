#ifndef node_h
#define node_h

#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node();
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
