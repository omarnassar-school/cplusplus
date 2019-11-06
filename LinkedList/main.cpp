#include <iostream>
#include <stdio.h>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

int main() {
  char first[10];
  char last[10];
  int ID;
  float GPA;
  Student* student = new Student;
  cout << "Enter a first name: ";
  cin.get(first, 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  student -> setFirst((char*)(first));
  cout << "Enter a last name: ";
  cin.get(last, 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  student -> setLast((char*)(last));
  cout << "Enter an ID number: ";
  cin >> ID;
  cin.clear();
  cin.ignore(1000000, '\n');
  student -> setID(ID);
  cout << "Enter a GPA: ";
  cin >> GPA;
  cin.clear();
  cin.ignore(1000000, '\n');
  student -> setGPA(GPA);
  cout << student -> getFirst() << " " << student -> getLast() << endl;
  cout << student -> getID() << endl;
  printf("%.2f\n", student->getGPA());

  Student* student2 = new Student;
  
  
  return 0;
}
