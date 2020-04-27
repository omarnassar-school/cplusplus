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
  int getDistance();
  //Setters
  void setLabel(char);
  void setDistance(int);
 private:
  char label;
  int distance;
};

#endif
