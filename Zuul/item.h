/*Author: Omar Nassar
 *Date: 10/28/2019
 *This is the .h file for the item class. This is where all the variables are stored.
 */

#ifndef item_h
#define item_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Item {
 public:
  Item();
  char* getName(); //function for getting name
  //char* getDescription();
  int getID(); //function for getting ID
  void setName(char*); //function for setting name, takes in char pointer
  //void setDescription(char*); 
  void setID(int); //function for setting ID, takes in int
 private:
  char* name; //char pointer for storing name
  //char* description;
  int id; //int to store id
};

#endif
