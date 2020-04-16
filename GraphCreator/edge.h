#ifndef edge_h
#define edge_h

#include <iostream>
#include "vertex.h"

using namespace std;

class Edge {
 public:
  Edge();
  ~Edge();
  //Getters
  Vertex* getFirst();
  Vertex* getSecond();
  int getWeight();
  //Setters
  void setFirst(Vertex*);
  void setSecond(Vertex*);
  void setWeight(int);
 private:
  Vertex* first;
  Vertex* second;
  int weight;
};

#endif
