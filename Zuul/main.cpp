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
  cout << "You are late to school and are rushing to get to school when someone runs up from behind you and takes your things. You try to catch him but he is too fast. He drops your backpack but keeps running with a few of your things. He runs inside the school and hides somewhere. What you need to find along with your backpack is your pencil, eraser, late slip, calculator, and your graded test that your parents signed and you were supposed to return today." << endl;

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
  
}

void initializeItems(vector<Item*>* items) {
  Item* juul = new Item();
  juul -> getName() = "Juul";
  cout << juul -> getName() << endl;
  juul -> getID() = 1;
  items -> push_back(juul);
}
