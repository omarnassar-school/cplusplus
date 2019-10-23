#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room() {
  
  
}

char* Room::getDescription() {
  return description;
}

int Room::getID() {
  return id;
}

map<int, char*>* Room::getExits() {
  return &exits;
}

int Room::getItem() {
  return item;
}

void Room::setDescription(char* inDescription) {
  description = inDescription;
}

void Room::setID(int inID) {
  id = inID;
}

void Room::setExits(map<int, char*> inExits) {
  exits = inExits;
}

void Room::setItem(int inItem) {
  item = inItem;
}
