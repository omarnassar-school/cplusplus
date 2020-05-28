/*Hash Table: A program that randomly generates students and stores them using a hash table
 *Author: Omar Nassar
 *Date: 5/17/2020
 */

#include <cstring>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct Student {
  char* first;
  char* last;
  int id;
  float gpa;
};

struct Node {
  Student* student;
  Node* next;
  int index;
};

//colors to make the console look "pretty"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int tableSize = 10;
Node** HashTable = new Node*[tableSize];
//int idCounter = 0;
vector<int> usedIDs;

void initTable(Node** table, int size) {
  for (int i = 0; i < size; i++) {
    table[i] = NULL;
  }
}

bool checkTable() {
  int counter = 0;
  for (int i = 0; i < tableSize; i++) {
    if (HashTable[i] != NULL)
      counter++;
  }
  if (counter >= tableSize)
    return true;
  else
    return false;
}

void reHash() {
  while (checkTable()) {
    cout << endl << YELLOW << "Rehashing..." << GREEN << " New table size is: " << RESET << pow(tableSize, 2) << endl;
    Node** tempTable = new Node*[(int)pow(tableSize, 2)];
    initTable(tempTable, (int)pow(tableSize, 2));
    for (int i = 0; i < tableSize; i++) {
      Node* tempNode = HashTable[i];
      int pos = 0;
      for (int i = 0; i < 10; i++) {
	if (tempNode -> student -> first[i] != '\0') {
	  pos += (int)tempNode -> student -> first[i];
	}
      }
      pos = pos % (int)pow(tableSize, 2);
      tempNode -> index = pos;
      tempTable[pos] = tempNode;
    }    
    HashTable = tempTable;
    tableSize = (int)pow(tableSize, 2);
    
    for (int i = 0; i < tableSize; i++) {
      if (HashTable[i] != NULL) {
	if (HashTable[i] -> next != NULL) {
	  Node* current = HashTable[i];
	  while (current -> next != NULL) {
	    Node* parent = current;
	    current = current -> next;
	    int pos = 0;
	    for (int i = 0; i < 10; i++) {
	      if (current -> student -> first[i] != '\0') {
		pos += (int) current -> student -> first[i];
	      }
	    }
	    pos = pos % tableSize;
	    
	    if (pos != parent -> index) {
	      Node* temp = current;
	      temp -> index = pos;
	      current = parent;
	      parent = NULL;
	      current -> next = temp -> next;
	      if (HashTable[pos] == NULL)
		HashTable[pos] = temp;
	      else {
		Node* occupier = HashTable[pos];
		while (occupier -> next != NULL)
		  occupier = occupier -> next;
		
		occupier -> next = temp;
	      }
	    }
	    else {
	      current -> index = pos;
	    }
	  }
	}
      }
    }
  }
}

void addStudent(char* inFirst, char* inLast, float inGPA) {
  Student* newStudent = new Student();
  Node* newNode = new Node();
  int randID;
  while (true) {
    randID = rand() % 1000000;
    bool exists = false;
    vector<int>::iterator i;
    for (i = usedIDs.begin(); i != usedIDs.end(); i++) {
      if (randID == *i) {
	exists = true;
      }
    }
    if (!exists)
      break;
  }
  
  newStudent -> id = randID;
  usedIDs.push_back(randID);

  newStudent -> first = inFirst;
  newStudent -> last = inLast;
  newStudent -> gpa = inGPA;

  int pos = 0;

  for (int i = 0; i < 10; i++) {
    if (newStudent -> first[i] != '\0') {
      pos += (int)newStudent -> first[i];
      //cout << (int)newStudent -> first[i] << endl;
      //cout << pos << endl;
    }
  }

  pos = pos % tableSize;
  //cout << tableSize << endl;
  //cout << pos << endl;
  newNode -> student = newStudent;
  newNode -> index = pos;
  
  if (HashTable[pos] ==  NULL) {
    HashTable[pos] = newNode;
    //cout << "happened";
  }
  else {
    Node* current = HashTable[pos];
    while (current -> next != NULL)
      current = current -> next;
    
    current -> next = newNode;
  }
  
  //cout << pos;
  //cout << HashTable[pos] -> student -> first;
  
  //pos = 0;
}

void removeStudent(int idx) {
  if (HashTable[idx] -> next == NULL) {
    char yesno = '\0';
    cout << YELLOW << endl << "Are you sure you would like to delete this student? (y/n)" << endl << GREEN << ">> " << RESET;
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');

    if (yesno == 'y') {
      delete HashTable[idx];
      HashTable[idx] = NULL;
      cout << endl << GREEN << "Student was deleted." << endl << RESET;
      return;
    }
    else if (yesno == 'n') {
      cout << endl << RED << "Student was not deleted." << RESET << endl;
      return;
    }
    else {
      cout << endl << RED << "Invalid Input." << RESET << endl;
      return;
    }
  }

  else {
    int chainNo = 0;
    char yesno = '\0';
    cout << endl << "What is the student's chain number?" << endl << GREEN << ">> " << RESET;
    cin >> chainNo;
    cin.clear();
    cin.ignore(1000000, '\n');

    Node* current = HashTable[idx];
    Node* parent;
    int counter;
    while (counter != chainNo) {
      if (current -> next != NULL) {	
	parent = current;
	current = current -> next;
      }
      else {
	cout << endl << RED << "There is no student with that chain number." << RESET << endl;
	return;
      }
      counter++;
      cout << endl << counter << endl;
    }
    
    cout << endl << current -> student -> first << endl;
    cout << current -> student -> last << endl;
    cout << setw(6) << setfill('0') << current -> student -> id << endl;
    printf("%.2f\n", current -> student -> gpa);

    cout << endl << YELLOW << "Are you sure you would like to delete this student? (y/n)" << GREEN << endl << ">> " << RESET;
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (yesno == 'y') {
      if (current -> next == NULL) {
	parent -> next = NULL;
	current = NULL;
	delete current;
	cout << GREEN << "Student was deleted." << endl << RESET;
      }
      else {
	Node* temp = current -> next;
	if (current == HashTable[idx]) {
	  HashTable[idx] = temp;
	}
	if (parent != NULL)
	  parent -> next = temp;
	current = NULL;
	delete current;
	cout << endl <<  GREEN << "Student was deleted." << endl << RESET;
	return;
      }
    }
    else if (yesno == 'n') {
      cout << endl << RED << "Student was not deleted." << endl << RESET;
      return;
    }
    else {
      cout << endl << RED << "Invalid Input." << endl << RESET;
      return;
    }
  }
}

int main() {
  int choice;
  initTable(HashTable, tableSize);
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
      cout << CYAN << "2: " << RESET << "From a file (randomly generated)" << endl;
      cout << GREEN << endl << ">> " << RESET;
      
      cin >> choice;
      cin.clear();
      cin.ignore(1000000, '\n');

      if (choice == 1) {//Manually
	char* first;
	char* last;
	float gpa;
	
	cout << endl << "What is the student's first name?" << endl << GREEN << ">> " << RESET;
	//cin.get(newStudent -> first, 10);
	cin.get(first, 10);
	cin.clear();
	cin.ignore(1000000, '\n');

	cout << endl << "What is the student's last name?" << endl << GREEN << ">> " << RESET;
	//cin.get(newStudent -> last, 10);
	cin.get(last, 10);
	cin.clear();
	cin.ignore(1000000, '\n');

	/*cout << endl << "What is their ID?" << endl << GREEN << ">> " << RESET;
	cin >> newStudent -> id;
	cin.clear();
	cin.ignore(1000000, '\n');*/
		
	cout << endl << "What is their GPA?" << endl << GREEN << ">> " << RESET;
	//cin >> newStudent -> gpa;
	cin >> gpa;
	cin.clear();
	cin.ignore(1000000, '\n');

	addStudent(first, last, gpa);
      }

      else if (choice == 2) {//From a file
	
      }

      else
	cout << RED << endl << "Invalid Input" << endl << RESET;
    }
    
    else if (choice == 2) {//PRINT
      Node* current;
      bool found = false;
      for (int i = 0; i < tableSize; i++) {
	if (HashTable[i] != NULL) {
	  found = true;
	  if (HashTable[i] -> student != NULL) {
	    cout << endl << HashTable[i] -> student -> first << endl;
	    cout << HashTable[i] -> student -> last << endl;
	    cout << setw(6) << setfill('0') << HashTable[i] -> student -> id << endl;
	    printf("%.2f\n", HashTable[i] -> student -> gpa);
	    cout << CYAN << "Index: " << RESET << HashTable[i] -> index << MAGENTA << " (0)" << endl << RESET;
	  }
	  current = HashTable[i];
	  int num = 0;
	  while (current -> next != NULL) {
	    current = current -> next;
	    num++;
	    if (current -> student != NULL) {
	      cout << endl << current -> student -> first << endl;
	      cout << current -> student -> last << endl;
	      cout << setw(6) << setfill('0') << current -> student -> id << endl;
	      printf("%.2f\n", current -> student -> gpa);
	      cout << CYAN << "Index: " << RESET << current -> index << MAGENTA << " (" << num << ")" << endl << RESET;
	    }
	  }
	}
      }
      if (!found)
	cout << RED << endl << "There are no students to print." << RESET << endl;
    }
    
    else if (choice == 3) {//DELETE
      int idx;
      cout << endl << "What is the student's index? (If unknown input -1)" << endl << GREEN << ">> " << RESET;
      cin >> idx;
      cin.clear();
      cin.ignore(1000000, '\n');

      if (idx == -1)
	cout << endl << "Input 2 to print all students and their information." << endl;
      else {
	bool found = false;
	if (HashTable[idx] != NULL) {
	  cout << endl << HashTable[idx] -> student -> first << endl;
	  cout << HashTable[idx] -> student -> last << endl;
	  cout << setw(6) << setfill('0') << HashTable[idx] -> student -> id << endl;
	  printf("%.2f\n", HashTable[idx] -> student -> gpa);
	  if (HashTable[idx] -> next != NULL)
	    cout << CYAN << "Chain number: " << MAGENTA << "0" << endl << RESET;
	
	  Node* current = HashTable[idx];
	  int num = 0;
	  while (current -> next != NULL) {
	    current = current -> next;
	    num++;
	    if (current -> student != NULL) {
	      cout << endl << current -> student -> first << endl;
	      cout << current -> student -> last << endl;
	      cout << setw(6) << setfill('0') << current -> student -> id << endl;
	      printf("%.2f\n", current -> student -> gpa);
	      cout << CYAN << "Chain number: " << MAGENTA << num << endl << RESET;
	    }
	  }
	  found = true;
	}
	if (!found)
	  cout << endl << RED << "There is no student with that index number." << RESET << endl;
	else
	  removeStudent(idx);
      }
    }
    
    else if (choice == 4) //QUIT
      break;
    
    else
      cout << endl << RED << "Invalid Input" << RESET << endl;
    
    reHash();
  }
  return 0;
}
