#include <iostream>
#include "vertex.h"

using namespace std;

Vertex::Vertex(char inLabel) {
  label = inLabel;
  distance = -1;
}

Vertex::~Vertex() {
  delete &label;
  delete &distance;
}

//Getters

char Vertex::getLabel() {
  return label;
}

int Vertex::getDistance() {
  return distance;
}

//Setters

void Vertex::setLabel(char inLabel) {
  label = inLabel;
}

void Vertex::setDistance(int inDistance) {
  distance = inDistance;
}
