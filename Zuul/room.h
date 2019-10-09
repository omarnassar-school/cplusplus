#ifndef room_h
#define room_h

#include <iostream>
#include <cstring>

using namespace std;

class Room {
 public:
  Room();
  map* getExits();
  list* items();
 private:
  map exits();
  list items();
};

#endif
