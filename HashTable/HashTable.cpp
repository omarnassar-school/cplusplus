/*Hash Table: A program that randomly generates students and stores them using a hash table
 *Author: Omar Nassar
 *Date: 5/17/2020
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct Student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

struct Node {
  Student* student;
  Node* next;
  Node* chained;
  int chainNumber;
  bool empty;
};

//colors to make the console look "pretty"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
  int choice;
  while (true) {
    cout << endl << "Would you like to:" << endl;
    cout << CYAN << "1: " << RESET << "ADD" << endl;
    cout << CYAN << "2: " << RESET << "PRINT" << endl;
    cout << CYAN << "3: " << RESET << "DELETE" << endl;
    cout << CYAN << "4: " << RESET << "QUIT" << endl;
    cout << GREEN << endl << ">> " << RESET;
    
    cin >> choice;
    cin.clear();
    cin.ignore(1000000, '\n');

    if (choice == 1) {//ADD
      cout << endl << "Would you like to add:" << endl;
      cout << CYAN << "1: " << RESET << "Manually" << endl;
      cout << CYAN << "2: " << RESET << "From a file" << endl;
      cout << GREEN << endl << ">> " << RESET;

      cin >> choice;
      cin.clear();
      cin.ignore(1000000, '\n');

      if (choice == 1) {//Manually
	
      }

      else if (choice == 2) {//From a file
	
      }

      else
	cout << RED << endl << "Invalid Input" << endl << RESET;
    }
    
    else if (choice == 2) {//PRINT
      
    }
    
    else if (choice == 3) {//DELETE
      
    }
    
    else if (choice == 4) //QUIT
      break;
    
    else
      cout << endl << RED << "Invalid Input" << RESET << endl;
  }
  return 0;
}
