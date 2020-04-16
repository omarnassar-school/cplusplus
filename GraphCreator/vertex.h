#ifndef vertex_h
#define vertex_h

#include <iostream>

using namespace std;

class Vertex {
 public:
  Vertex(char);
  ~Vertex();
  //Getters
  char getLabel();
  //Setters
  void setLabel(char);
 private:
  char label;
};

#endif
