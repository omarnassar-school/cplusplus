#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

Room::Room() {
  
  
}

map* Room::getExits() {
  return &map;
}

list* Room::getItems() {
  return &items;
}
