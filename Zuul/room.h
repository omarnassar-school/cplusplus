/*Author: Omar Nassar
 *Date: 10/28/19
 *This is the .h file for the room class. This is where all the variables are stored.
 */

#ifndef room_h
#define room_h

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  Room();
  char* getDescription(); //function for getting description
  int getID(); //function for getting room ID
  map<int, char*>* getExits(); //function for getting map for exits
  int getItem(); //function for getting item ID
  void setDescription(char*); //function for setting description, takes in char pointer
  void setID(int); //function for setting room ID, takes in int
  void setExits(map<int, char*>); //function for setting room exits, takes in map
  void setItem(int); //function for setting item ID, takes in int
 private:
  char* description; //char pointer to store description
  int id; //int to store room ID
  map<int, char*> exits; //map to store room exits
  int item; //int to store item ID
};

#endif
