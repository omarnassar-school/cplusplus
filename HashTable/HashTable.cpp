/*Hash Table: A program that randomly generates students and stores them using a hash table
 *Author: Omar Nassar
 *Date: 5/17/2020
 */

#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct Student {
  char* first;
  char* last;
  //char first[10];
  //char last[10];
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
map<char*, char*> usedNames;
int nameSize = 20;

void initTable(Node** table, int size) {
  for (int i = 0; i < size; i++) {
    table[i] = NULL;
  }
}

bool checkTable() {//checking if table is full so we can rehash
  //decided not to rehash based on collisions because names can be the same and would cause endless rehashing
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

void reHash(bool forced) {
  while (checkTable() || forced) {
    forced = false;
    cout << endl << YELLOW << "Rehashing..." << GREEN << " New table size is: " << RESET << pow(tableSize, 2) << endl;
    Node** tempTable = new Node*[(int)pow(tableSize, 2)];
    initTable(tempTable, (int)pow(tableSize, 2));
    for (int i = 0; i < tableSize; i++) {
      Node* tempNode = HashTable[i];
      int pos = 0;
      for (int i = 0; i < nameSize; i++) {
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
	    for (int i = 0; i < nameSize; i++) {
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

int genID() {
  //decided to generate a random ID number, just like an actual school would most likely do it
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
  usedIDs.push_back(randID);
  return randID;
}

bool checkCombos(char* first, char* last) {
  map<char*, char*>::const_iterator j;
  for (j = usedNames.begin(); j != usedNames.end(); ++j) {
    if (strcmp(first, j -> first) == 0) {
      if (strcmp(last, j -> second) == 0) {
	return false;
      }
    }
  }
  return true;
}

void addStudent(char* inFirst, char* inLast, float inGPA) {
  Student* newStudent = new Student();
  Node* newNode = new Node();
  
  newStudent -> id = genID();  
  newStudent -> first = inFirst;
  newStudent -> last = inLast;
  newStudent -> gpa = inGPA;

  int pos = 0;

  for (int i = 0; i < nameSize; i++) {
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

  usedNames.insert(pair<char*, char*> (inFirst, inLast));
  
  //cout << pos;
  //cout << HashTable[pos] -> student -> first;
  
  //pos = 0;
  reHash(false);
}

void parseInput(vector<char*> &names, char* input) {
  char* name = new char[nameSize];
  int i = 0;
  int counter = 0;
  while (input[i] != '\0') {
    //cout << input[i];
    if (input[i] == ' ') {
      if (counter < nameSize) {
	name[counter] = '\0';
	//cout << endl << name << endl << endl;
	names.push_back(name);
      }
      name = new char[nameSize];
      counter = 0;
    }
    else {
      name[counter] = input[i];
      counter++;
      //cout << endl << counter;
    }
    i++;
  }
  //name[counter] = '\0';
  //cout << endl << name << endl << endl;
  names.push_back(name);
  //cout << endl << endl;
}

void randomGen(char first[], char last[], int amount) {
  vector<char*> firstNames;
  vector<char*> lastNames;
  char* input = new char[10000];
  ifstream file;
  
  
  file.open(first);
  if (file) {
    int i = 0;
    while (!file.eof()) {
      input[i] = file.get();
      i++;
    }
    input[i - 1] = '\0';
  }
  else {
    cout << endl << RED << "There is an error opening: " << first << endl << RESET;
    return;
  }
  parseInput(firstNames, input);
  file.close();
  
  file.open(last);
  if (file) {
    int i = 0;
    while (!file.eof()) {
      input[i] = file.get();
      i++;
    }
    input[i - 1] = '\0';
  }
  else {
    cout << endl << RED << "There is an error opening: " << last << endl << RESET;
    return;
  }
  parseInput(lastNames, input);
  file.close();
  vector<map<char*,char*>> combos;
  vector<char*>::iterator n;
  vector<char*>::iterator n2;
  int z;
  //cout << endl <<  firstNames.size() << endl << lastNames.size() << endl;
  for (n = firstNames.begin(); n != firstNames.end(); n++) {
    for (n2 = lastNames.begin(); n2 != lastNames.end(); n2++) {
      //cout << z << endl;
      map<char*, char*> temp;
      if (checkCombos(*n, *n2)) {
	temp.insert(pair<char*, char*> (*n, *n2));
	combos.push_back(temp);
      }
      temp.clear();
      z++;
    }
  }
  //cout << endl << z;
  //cout << endl << firstNames.size() << endl << lastNames.size() << endl <<  combos.size() << endl;

  if (amount > combos.size()) {
    cout << RED << endl << "Maximum amount of random students is: " << combos.size() << RESET << endl;
    return;
  }
  
  for (int i = 0; i < amount; i++) {
    char* firstName = new char[nameSize];
    char* lastName = new char[nameSize];
    float gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
    //cout << endl << "1" << endl;
    do {
      vector<map<char*, char*>>::const_iterator v;
      map<char*, char*>::const_iterator m;
      int random = rand() % combos.size();
      //cout << random;
      int counter = 0;
      for (v = combos.begin(); v != combos.end(); ++v) {
	if (counter == random) {
	  for (m = v -> begin(); m != v -> end(); ++m) {
	    //cout << endl << m -> first << " " << m -> second << endl;
	    firstName = m -> first;
	    lastName = m -> second;
	    break;
	  }
	  break;
	}
	counter++;
      }
      //cout << endl << random << endl;
    } while (!checkCombos(firstName, lastName));
    //cout << endl << "2" << endl;
    //cout << endl << firstName << endl;
    //cout << endl << lastName << endl;
    //cout << endl << gpa << endl;
    addStudent(firstName, lastName, gpa);
    //cout << endl << "4" << endl;
  }
 
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
  srand(time(0));
  int choice;
  initTable(HashTable, tableSize);
  while (true) {
    cout << endl << "Would you like to:" << endl;
    cout << CYAN << "1: " << RESET << "ADD" << endl;
    cout << CYAN << "2: " << RESET << "PRINT" << endl;
    cout << CYAN << "3: " << RESET << "DELETE" << endl;
    cout << CYAN << "4: " << RESET << "REHASH" << endl;
    cout << CYAN << "5: " << RESET << "QUIT" << endl;
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
	char* first = new char[nameSize];
	char* last = new char[nameSize];
	float gpa;
	cout << endl << "What is the student's first name?" << endl << GREEN << ">> " << RESET;
	//cin.get(newStudent -> first, 10);
	cin.get(first, nameSize);
	cin.clear();
	cin.ignore(1000000, '\n');

	cout << endl << "What is the student's last name?" << endl << GREEN << ">> " << RESET;
	//cin.get(newStudent -> last, 10);
	cin.get(last, nameSize);
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
	
	if (gpa <= 5 && gpa > 0) {
	  if (checkCombos(first, last)) {
	    addStudent(first, last, gpa);
	    cout << endl << GREEN << "Student has been added." << endl << RESET;
	  }
	  else 
	    cout << endl << RED << "There is already a student with that name." << endl << RESET;
	}
	else
	  if (gpa > 0)
	    cout << endl << RED << "GPA is too high." << endl << RESET;
	  else
	    cout << endl << RED << "GPA is too low." << endl << RESET;
      }

      else if (choice == 2) {//From a file
	char firstFile[20];
	char secondFile[20];
	int amount;
	
	cout << endl << "What is name of the file with the first names?" << endl << GREEN << ">> " << RESET;
	cin.get(firstFile, 20);
	cin.clear();
	cin.ignore(1000000, '\n');

	cout << endl << "What is the name of the file with the last names?" << endl << GREEN << ">> " << RESET;
	cin.get(secondFile, 20);
	cin.clear();
	cin.ignore(1000000, '\n');

	cout << endl << "How many student would you like to generate?" << endl << GREEN << ">> " << RESET;
	cin >> amount;
	cin.clear();
	cin.ignore(1000000, '\n');

	randomGen(firstFile, secondFile, amount);
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

    else if (choice == 4)
      reHash(true);
    
    else if (choice == 5) //QUIT
      break;
    
    else
      cout << endl << RED << "Invalid Input" << RESET << endl;
    
  }
  return 0;
}
