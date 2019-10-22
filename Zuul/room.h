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
  int* getID();
  map<int, char*>* getExits();
  int* getItem();
 private:
  char description[100];
  int id;
  map<int, char*> exits;
  int item;
};

#endif
