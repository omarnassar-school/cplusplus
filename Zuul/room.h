#ifndef room_h
#define room_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  Room();
  char* getDescription();
  int getID();
  map<int, char*>* getExits();
  int getItem();
  void setDescription(char*);
  void setID(int);
  void setExits(map<int, char*>);
  void setItem(int);
 private:
  char* description;
  int id;
  map<int, char*> exits;
  int item;
};

#endif
