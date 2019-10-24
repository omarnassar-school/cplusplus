#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item() {
  
  
}

char* Item::getName() {
  return name;
}

/*char* Item::getDescription() {
  return description;
  }*/

int Item::getID() {
  return id;
}

void Item::setName(char* inName) {
  name = inName;
}

/*void Item::setDescription(char* inDescription) {
  description = inDescription;
  }*/

void Item::setID(int inID) {
  id = inID;
}
