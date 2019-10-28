/*Author: Omar Nassar
 *Date: 10/3/19
 *This is the .cpp file for the room class. This is where all the getters and setters are stored.
 */

#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room() {//calling .h file
  
  
}

char* Room::getDescription() {//function for getting room description, returns char pointer
  return description;
}

int Room::getID() {//function for getting room ID, returns int
  return id;
}

map<int, char*>* Room::getExits() {//function for getting room exits, returns map pointer
  return &exits;
}

int Room::getItem() {//function for getting item ID, returns int
  return item;
}

void Room::setDescription(char* inDescription) {//function for setting rooom description, takes in char pointer
  description = inDescription;
}

void Room::setID(int inID) {//function for setting room ID, takes in int
  id = inID;
}

void Room::setExits(map<int, char*> inExits) {//function for seting room exits, takes in map
  exits = inExits;
}

void Room::setItem(int inItem) {//function for setting room item, takes in int
  item = inItem;
}
