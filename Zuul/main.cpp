/* Author: Omar Nassar
 * Date: 10/16/19
 * This is an adventure game based off of the "World of Zuul" application by Michael Kolling and David J. Barnes
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> invenctory);
void getItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]); //int id);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]);
//int getID(char name[]);

int main() {
  vector<Room*> rooms; //vector for storing rooms
  vector<Item*> items; //vector for storing items
  vector<int> inventory; //vector for storing inventory (item IDs)
  char input[20];
  int currentRoom = 1;
  initializeItems(&items);
  initializeRooms(&rooms);
  cout << endl << "You are late to school and are rushing to get to school when someone runs up from behind you and takes your things. You try to catch him but he is too fast. He drops your backpack but keeps running with a few of your things. He runs inside the school and hides somewhere. What you need to find along with your backpack is your pencil, eraser, late slip, calculator, and your graded test that your parents signed and you were supposed to return today." << endl;

  cout << endl << "Type 'help' if you need help." << endl << endl;
  while (true) {
    cout << "You are currently ";
    printRoom(&rooms, &items, currentRoom);
    cin >> input;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "help") == 0) {
      cout << endl << "You are looking for your things that were stolen from you."  << endl;
      cout << "Your command words are:" << endl;
      cout << "go quit help inventory get drop" << endl << endl;
    }
    else if (strcmp(input, "quit") == 0) {
      cout << endl << "Thanks for playing!" << endl;
      break;
    }
    else if (strcmp(input, "go") == 0) {
      cout << endl << "Where would you like to go?" << endl << endl;
      cin >> input;
      cin.clear();
      cin.ignore(1000000, '\n');
      if (move(&rooms, currentRoom, input) == 0) {//if there is no room that matches the input
	cout << endl << "There is nothing in that direction." << endl << endl;
      }
      else {
	currentRoom = move(&rooms, currentRoom, input); //changing current room to the new room
	cout << endl;
      }
    }
    else if (strcmp(input, "inventory") == 0) {
      if (inventory.size() != 0) {//if there is something in inventory
	cout << endl << "You have: " << endl;
	printInventory(&items, inventory);
      }
      else {//if inventory is empty
	cout << endl << "There is nothing in your inventory." << endl << endl;
      }
    }
    else if (strcmp(input, "get") == 0) {
      cout << endl << "What would you like to get?" << endl << endl;
      cin >> input;
      cin.clear();
      cin.ignore(1000000, '\n');
      getItem(&rooms, &items, &inventory, currentRoom, input);
    }
    else if (strcmp(input, "drop") == 0) {
      cout << endl << "What would you like to drop?" << endl << endl;
      cin >> input;
      cin.clear();
      cin.ignore(1000000, '\n');
      dropItem(&rooms, &items, &inventory, currentRoom, input);
    }
    else {
      cout << endl << "Invalid Input." << endl << endl;
    }

    if (find(inventory.begin(), inventory.end(), 1) != inventory.end()) {//first losing condition
      cout << endl << "Don't do drugs. You lose." << endl;
      break;
    }
    if (find(inventory.begin(), inventory.end(), 2) != inventory.end()) {//second losing condition
      cout << endl<< "Don't pick up something someone else ate. It has germs. you lose." << endl;
      break;
    }
    if ((currentRoom == 9) && (find(inventory.begin(), inventory.end(), 3) != inventory.end()) && (find(inventory.begin(), inventory.end(), 4) != inventory.end()) && (find(inventory.begin(), inventory.end(), 5) != inventory.end()) && (find(inventory.begin(), inventory.end(), 6) != inventory.end()) && (find(inventory.begin(), inventory.end(), 7) != inventory.end()) && find(inventory.begin(), inventory.end(), 8) != inventory.end()) {//how to win
      cout << "Good job! You win" << endl << "Against all odds, you found everything you lost and got your test back for credit!" << endl << "Thank you for playing! Goodbye!" << endl;
      break;
    }
  }
  return 0;
}

void initializeRooms(vector<Room*>* rooms) {//function for adding all the rooms to the vector
  //making variables for each direction to save typing time
  char* west = (char*)("west");
  char* east = (char*)("east");
  char* north = (char*)("north");
  char* south = (char*)("south");
  map<int, char*> temp; //temporary map to store exits then be set as room exits
  //Outside Front
  Room* outsideFront = new Room();
  outsideFront -> setDescription((char*)("outside in front of the school")); //setting description
  outsideFront -> setID(1); //setting room ID
  //setting exits
  temp.insert(pair<int, char*> (2, west)); 
  temp.insert(pair<int, char*> (12, (char*)("around")));
  outsideFront -> setExits(temp); //pushing exits to class
  outsideFront -> setItem(7); //setting initial item
  rooms -> push_back(outsideFront); //pushing room to the vector
  temp.clear(); //resetting the map
  //Main Office
  Room* mainOffice = new Room();
  mainOffice -> setDescription((char*)("in the main office"));
  mainOffice -> setID(2);
  temp.insert(pair<int, char*> (1, east));
  temp.insert(pair<int, char*> (6, west));
  temp.insert(pair<int, char*> (3, north));
  temp.insert(pair<int, char*> (4, south));
  mainOffice -> setExits(temp);
  mainOffice -> setItem(0);
  rooms -> push_back(mainOffice);
  temp.clear();
  //Attendance Office
  Room* attendance = new Room();
  attendance -> setDescription((char*)("in the attendance office"));
  attendance -> setID(3);
  temp.insert(pair<int, char*> (2, south));
  attendance -> setExits(temp);
  attendance -> setItem(5);
  rooms -> push_back(attendance);
  temp.clear();
  //Principal's Office
  Room* principal = new Room();
  principal -> setDescription((char*)("in the principal's office"));
  principal -> setID(4);
  temp.insert(pair<int, char*> (2, north));
  principal -> setExits(temp);
  principal -> setItem(0);
  rooms -> push_back(principal);
  temp.clear();
  //Room D-8
  Room* d8 = new Room();
  d8 -> setDescription((char*)("in room D-8. The teacher asks if you need help finding your classroom"));
  d8 -> setID(5);
  temp.insert(pair<int, char*> (6, south));
  d8 -> setExits(temp);
  d8 -> setItem(0);
  rooms -> push_back(d8);
  temp.clear();
  //Main Hall
  Room* mainHall = new Room();
  mainHall -> setDescription((char*)("in Main hall"));
  mainHall -> setID(6);
  temp.insert(pair<int, char*> (2, east));
  temp.insert(pair<int, char*> (7, south));
  temp.insert(pair<int, char*> (5, north));
  mainHall -> setExits(temp);
  mainHall -> setItem(4);
  rooms -> push_back(mainHall);
  temp.clear();
  //1 Hall
  Room* oneHall = new Room();
  oneHall -> setDescription((char*)("in 1 hall"));
  oneHall -> setID(7);
  temp.insert(pair<int, char*> (6, north));
  temp.insert(pair<int, char*> (8, south));
  temp.insert(pair<int, char*> (15, east));
  temp.insert(pair<int, char*> (11, west));
  oneHall -> setExits(temp);
  oneHall -> setItem(0);
  rooms -> push_back(oneHall);
  temp.clear();
  //Cafeteria
  Room* cafeteria = new Room();
  cafeteria -> setDescription((char*)("in the cafeteria"));
  cafeteria -> setID(8);
  temp.insert(pair<int, char*> (7, north));
  cafeteria -> setExits(temp);
  cafeteria -> setItem(2);
  rooms -> push_back(cafeteria);
  temp.clear();
  //Math Class
  Room* math = new Room();
  math -> setDescription((char*)("in your math classroom"));
  math -> setID(9);
  temp.insert(pair<int, char*> (11, north));
  temp.insert(pair<int, char*> (10, east));
  math -> setExits(temp);
  math -> setItem(0);
  rooms -> push_back(math);
  temp.clear();
  //Teacher's Office
  Room* teacherOffice = new Room();
  teacherOffice -> setDescription((char*)("in your math teacher's office"));
  teacherOffice -> setID(10);
  temp.insert(pair<int, char*> (9, west));
  teacherOffice -> setExits(temp);
  teacherOffice -> setItem(6);
  rooms -> push_back(teacherOffice);
  temp.clear();
  //G Hall
  Room* gHall = new Room();
  gHall -> setDescription((char*)("in G hall"));
  gHall -> setID(11);
  temp.insert(pair<int, char*> (12, north));
  temp.insert(pair<int, char*> (7, east));
  temp.insert(pair<int, char*> (9, south));
  temp.insert(pair<int, char*> (13, west));
  gHall -> setExits(temp);
  gHall -> setItem(3);
  rooms -> push_back(gHall);
  temp.clear();
  //Outside Back
  Room* outsideBack = new Room();
  outsideBack -> setDescription((char*)("outside behind the school"));
  outsideBack -> setID(12);
  temp.insert(pair<int, char*> (1, (char*)("around")));
  temp.insert(pair<int, char*> (11, south));
  outsideBack -> setExits(temp);
  outsideBack -> setItem(0);;
  rooms -> push_back(outsideBack);
  temp.clear();
  //Bathroom
  Room* bathroom = new Room();
  bathroom -> setDescription((char*)("in the G hall bathroom"));
  bathroom -> setID(13);
  temp.insert(pair<int, char*> (11, east));
  temp.insert(pair<int, char*> (14, south));
  bathroom -> setExits(temp);
  bathroom -> setItem(0);
  rooms -> push_back(bathroom);
  temp.clear();
  //Bathroom Stall
  Room* stall = new Room();
  stall -> setDescription((char*)("in the nearest stall"));
  stall -> setID(14);
  temp.insert(pair<int, char*> (13, north));
  stall -> setExits(temp);
  stall -> setItem(1);
  rooms -> push_back(stall);
  temp.clear();
  //Room 1-20
  Room* one20 = new Room();
  one20 -> setDescription((char*)("in room 1-20. You are amazed by the rows upon rows of computers in the room"));
  one20 -> setID(15);
  temp.insert(pair<int, char*> (7, west));
  one20 -> setExits(temp);
  one20 -> setItem(8);
  rooms -> push_back(one20);
  temp.clear();
  /*
  //printing rooms and ids for debugging
  vector<Room*>::iterator i;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    cout << endl << (*i) -> getDescription() << endl;
    cout << (*i) -> getID() << endl;
    for (map<int, char*>::const_iterator it = (*i) -> getExits() -> begin(); it != (*i) -> getExits() -> end(); it++) {
      cout << it -> first << ", " << it -> second << endl;
    }
    //cout << (*i) -> getExits() << endl;
    cout << (*i) -> getItem() << endl;
  }
  */
}

void initializeItems(vector<Item*>* items) {//setting up item vector
  //Juul
  Item* juul = new Item();
  juul -> setName((char*)("Juul")); //setting name
  juul -> setID(1); //setting id
  items -> push_back(juul); //pushing item back to vector
  //Apple
  Item* apple = new Item();
  apple -> setName((char*)("Half-Eaten_Apple"));
  apple -> setID(2);
  items -> push_back(apple);
  //Eraser
  Item* eraser = new Item();
  eraser -> setName((char*)("Eraser"));
  eraser -> setID(3);
  items -> push_back(eraser);
  //Pencil
  Item* pencil = new Item();
  pencil -> setName((char*)("Pencil"));
  pencil -> setID(4);
  items -> push_back(pencil);
  //Late Slip
  Item* lateSlip = new Item();
  lateSlip -> setName((char*)("Late_Slip"));
  lateSlip -> setID(5);
  items -> push_back(lateSlip);
  //Test
  Item* test = new Item();
  test -> setName((char*)("Graded_Test"));
  test -> setID(6);
  items -> push_back(test);
  //Backpack
  Item* backpack = new Item();
  backpack -> setName((char*)("Backpack"));
  backpack -> setID(7);
  items -> push_back(backpack);
  //Calculator
  Item* calculator = new Item();
  calculator -> setName((char*)("Calculator"));
  calculator -> setID(8);
  items -> push_back(calculator);

  /*
  //printing items and ids for debugging
  vector<Item*>::iterator i;
  for (i = items -> begin(); i != items -> end(); i++) {
    cout << endl << (*i) -> getName() << endl;
    cout << (*i) -> getID() << endl;
  }
  */
}

void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom) {//printing the rooms and their exits and items
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    if (currentRoom == (*i) -> getID()) {//getting the description of the current room
      cout << (*i) -> getDescription() << "." << endl;
      cout << "Exits: ";
      for (map<int, char*>::const_iterator it = (*i) -> getExits() -> begin(); it != (*i) -> getExits() -> end(); it++) {//printing exits
	cout << it -> second << " ";
      }
      cout << endl;
      cout << "Item in this room: " << endl;
      for (j = items -> begin(); j != items -> end(); j++) {
	if ((*i) -> getItem() == (*j) -> getID()) {//printing item in the room
	  cout << (*j) -> getName() << endl;
	}
      }
      cout << endl;
      break;
    }
  }
}

void printInventory(vector<Item*>* items, vector<int> inventory) {//printing the items in inventory
  vector<int>::iterator i;
  vector<Item*>::iterator j;
  for (i = inventory.begin(); i != inventory.end(); i++) {
    for (j = items -> begin(); j != items -> end(); j++) {
      if (*i == (*j) -> getID()) {//printing the item if it matches the id stored in the inventory vector
	cout << (*j) -> getName() << endl;
      }
    }
  }
  cout << endl;
}

void getItem(vector<Room*>* rooms, vector<Item*>* items, vector <int>* inventory, int currentRoom, char name[]) { //int id) {  //function for getting the item from the room
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    if (currentRoom == (*i) -> getID()) {
      for (j = items -> begin(); j != items -> end(); j++) {
	if (((*i) -> getItem() == (*j) -> getID()) && (strcmp((*j) -> getName(), name) == 0)) {//if the item name is in the room
	  inventory -> push_back((*j) -> getID()); //adding item to inventory
	  (*i) -> setItem(0); //setting room item to 0 (empty)
	  cout << endl << "Got " << (*j) -> getName() << "." << endl << endl;
	  return;
	}
      }
    }
  }
  cout << endl <<  "That item is not here." << endl << endl;
}

void dropItem(vector<Room*>* rooms, vector <Item*>* items, vector <int>* inventory, int currentRoom, char name[]) {//dropping items
  int counter;
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
  vector<int>::iterator k;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    if (currentRoom == (*i) -> getID()) {
      if ((*i) -> getItem() == 0) {
	for (j = items -> begin(); j != items -> end(); j++) {
	  if ((strcmp((*j) -> getName(), name) == 0)) {
	    for (k = inventory -> begin(); k != inventory -> end(); k++) {
	      if ((*k) == (*j) -> getID()) {//if room is empty and item that is being dropped is in the inventory
		cout << endl << "Dropped " << (*j) -> getName() << "." << endl << endl;
		(*i) -> setItem((*j) -> getID()); //setting the room item
		k = inventory -> erase(k); //removing item from vector
		return;
	      }
	    }
	  }
	  else if (counter == items -> size() - 1) {
	    cout << endl << "That item is not in your inventory." << endl;
	  }
	  counter++;
	}
      }
      else {//if there is already an item in the room
	cout << endl << "There is already an item here." << endl;
      }
    }
  }
  cout << endl;
}

int move(vector<Room*>* rooms, int currentRoom, char direction[]) {//moving to another room
  vector<Room*>::iterator i;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    if (currentRoom == (*i) -> getID()) {
      map<int, char*> exits;
      exits = *(*i) -> getExits();
      map<int, char*>::const_iterator j;
      for (j = exits.begin(); j != exits.end(); ++j) {
	if (strcmp(j -> second, direction) == 0) {//if the direction in the map matches the input, change the room to the ID of the room in that direction
	  return j -> first;
	}
      }
    }
  }
  return 0;
}

/*int getID(char name[]) {
  
  return 0;
  }*/
