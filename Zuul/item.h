#ifndef item_h
#define item_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Item {
 public:
  Item();
  char* getName();
  //char* getDescription();
  int getID();
  void setName(char*);
  void setDescription(char*);
  void setID(int);
 private:
  char* name;
  //char* description;
  int id;
};

#endif
