/* Author: Omar Nassar
 * Date: 10/16/19
 * This is an adventure game based off of the "World of Zuul" application by Michael Kolling and David J. Barnes
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);

int main() {
  vector<Room*> rooms;
  vector<Item*> items;
  char input[10];
  initializeItems(&items);
  initializeRooms(&rooms);
  cout << endl << "You are late to school and are rushing to get to school when someone runs up from behind you and takes your things. You try to catch him but he is too fast. He drops your backpack but keeps running with a few of your things. He runs inside the school and hides somewhere. What you need to find along with your backpack is your pencil, eraser, late slip, calculator, and your graded test that your parents signed and you were supposed to return today." << endl;

  cout << endl << "Type 'help' if you need help." << endl << endl;
  while (true) {
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
    else {
      cout << endl << "Invalid Input." << endl << endl;
    }
  }
  return 0;
}

void initializeRooms(vector<Room*>* rooms) {
  char* west = (char*)("west");
  char* east = (char*)("east");
  char* north = (char*)("north");
  char* south = (char*)("south");
  map<int, char*> temp;
  //Outside Front
  Room* outsideFront = new Room();
  outsideFront -> setDescription((char*)("outside in front of the school"));
  outsideFront -> setID(1);
  temp.insert(pair<int, char*> (2, west));
  temp.insert(pair<int, char*> (12, (char*)("around")));
  outsideFront -> setExits(temp);
  outsideFront -> setItem(1);
  rooms -> push_back(outsideFront);
  temp.clear();
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
  
}

void initializeItems(vector<Item*>* items) {
  //Juul
  Item* juul = new Item();
  juul -> setName((char*)("Juul"));
  juul -> setID(1);
  items -> push_back(juul);
  //Apple
  Item* apple = new Item();
  apple -> setName((char*)("Apple"));
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
  lateSlip -> setName((char*)("Late Slip"));
  lateSlip -> setID(5);
  items -> push_back(lateSlip);
  //Test
  Item* test = new Item();
  test -> setName((char*)("Test"));
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

  
  //printing items and ids for debugging
  vector<Item*>::iterator i;
  for (i = items -> begin(); i != items -> end(); i++) {
    cout << endl << (*i) -> getName() << endl;
    cout << (*i) -> getID() << endl;
  }
  
}
