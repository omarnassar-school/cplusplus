#ifndef item_h
#define item_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Item {
 public:
  Item() {
    name = new char[10];
    id = new id;
  };
  char*& getName();
  int& getID();
 private:
  char* name;
  int* id;
};

#endif
