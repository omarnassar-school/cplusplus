#include <iostream>
#include "vertex.h"

using namespace std;

Vertex::Vertex(char inLabel) {
  label = inLabel;
}

Vertex::~Vertex() {
  delete &label;
}

//Getters

char Vertex::getLabel() {
  return label;
}

//Setters

void Vertex::setLabel(char inLabel) {
  label = inLabel;
}
