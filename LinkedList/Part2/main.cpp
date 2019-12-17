#include <iostream>
#include <stdio.h>
#include <cstring>
#include "node.h"
#include "Student.h"

using namespace std;

void addNew(Node*& first, Node* next, Student* student);

int main() {
  Node* first = NULL;
  Node* next = NULL;
  while (true) {
    char input[10];
    int intInput;
    float floatInput;
    cout << "What would you like to do? (ADD/PRINT/DELETE/AVERAGE/QUIT)" << endl << ">> ";
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');
    //add
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      Student* newStudent = new Student;
      cout << "What is the first name?" << endl << ">> ";
      cin.get(newStudent -> getFirst(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "What is the last name?" << endl << ">> ";
      cin.get(newStudent -> getLast(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "What is the ID?" << endl << ">> ";
      cin >> intInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      newStudent -> setID(intInput);
      cout << "What is the GPA?" << endl << ">> ";
      cin >> floatInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      newStudent -> setGPA(floatInput);
      cout << "Student has been added" << endl;
      addNew(&first, next, newStudent);
    }
    //print
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      cout << "printing" << endl;
    }
    //delete
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      cout << "deleting" << endl;
    }
    //average
    else if (strcmp(input, "AVERAGE") == 0 || strcmp(input, "average") == 0) {
      cout << "averaging" << endl;
    }
    //quit
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      cout << "quitting";
      break;
    }
    else {
      cout << "Invalid Input." << endl;
  }
  return 0;
  }
}

void addNew(Node*& first, Node* next, Student* student) {
  cout << "adding" << endl;
  if (first = NULL) {
    first -> setStudent(student);
  }
  else {
    while (true) {
      if (first -> getNext() != NULL) {
	next = first -> getNext();
      }
      else {
	break;
      }
    }
    next -> setStudent(student);
  }
}
