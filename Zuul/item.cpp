/*Author: Omar Nassar
 *Date: 10/28/19
 *This is the .cpp file for the item class. This is where all the getter and setter functions are stored.
 */

#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item() {//calling .h file
  
  
}

char* Item::getName() {//function for getting name, returns name
  return name;
}

/*char* Item::getDescription() {
  return description;
  }*/

int Item::getID() {//function for getting ID, returns ID
  return id;
}

void Item::setName(char* inName) {//function for setting name, takes in char pointer
  name = inName;
}

/*void Item::setDescription(char* inDescription) {
  description = inDescription;
  }*/

void Item::setID(int inID) {//function for setting ID, takes in int
  id = inID;
}
