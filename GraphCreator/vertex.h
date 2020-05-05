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
  Vertex* getPrevious();
  //Setters
  void setLabel(char);
  void setDistance(int);
  void setPrevious(Vertex*);
 private:
  char label;
  int distance;
  Vertex* previous;
};

#endif
