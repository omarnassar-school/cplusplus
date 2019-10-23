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
  map<int, char*> temp;
  //Outside Front
  Room* outsideFront = new Room();
  outsideFront -> setDescription((char*)("outside in front of the school"));
  outsideFront -> setID(1);
  temp.insert(pair<int, char*> (2, (char*)("west")));
  temp.insert(pair<int, char*> (12, (char*)("around")));
  outsideFront -> setExits(temp);
  outsideFront -> setItem(1);
  rooms -> push_back(outsideFront);
  temp.clear();
  Room* mainOffice = new Room();
  mainOffice -> setDescription((char*)("in the main office"));
  mainOffice -> setID(2);
  temp.insert(pair<int, char*> (1, (char*)("east")));
  temp.insert(pair<int, char*> (6, (char*)("west")));
  temp.insert(pair<int, char*> (3, (char*)("north")));
  temp.insert(pair<int, char*> (4, (char*)("south")));
  mainOffice -> setExits(temp);
  mainOffice -> setItem(0);
  rooms -> push_back(mainOffice);
  
  
  //printing rooms and ids for debugging
  vector<Room*>::iterator i;
  for (i = rooms -> begin(); i != rooms -> end(); i++) {
    cout << endl << (*i) -> getDescription() << endl;
    cout << (*i) -> getID() << endl;
    cout << (*i) -> getExits() << endl;
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
