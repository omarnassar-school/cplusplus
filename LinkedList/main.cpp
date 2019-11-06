#include <iostream>
#include <stdio.h>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

int main() {
  Student* student = new Student;
  cout << "Enter a first name: ";
  cin.get(student -> getFirst(), 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  //student -> setFirst((char*)(first));
  cout << "Enter a last name: ";
  cin.get(student -> getLast(), 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  //student -> setLast((char*)(last));
  cout << "Enter an ID number: ";
  cin >> *student -> getID();
  cin.clear();
  cin.ignore(1000000, '\n');
  //student -> setID(ID);
  cout << "Enter a GPA: ";
  cin >> *student -> getGPA();
  cin.clear();
  cin.ignore(1000000, '\n');
  //student -> setGPA(GPA);
  cout << endl;
  cout << student -> getFirst() << " " << student -> getLast() << endl;
  cout << *student -> getID() << endl;
  printf("%.2f\n", *student -> getGPA());
  cout << endl;
  
  Student* student2 = new Student;
  cout << "Enter a first name: ";
  cin.get(student2 -> getFirst(), 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  //student2 -> setFirst((char*)(first));
  cout << "Enter a last name: ";
  cin.get(student2 -> getLast(), 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  //student2 -> setLast((char*)(last));
  cout << "Enter an ID number: ";
  cin >> *student2 -> getID();
  cin.clear();
  cin.ignore(1000000, '\n');
  //student2 -> setID(ID);
  cout << "Enter a GPA: ";
  cin >> *student2 -> getGPA();
  cin.clear();
  cin.ignore(1000000, '\n');
  //student2 -> setGPA(GPA);
  cout << endl;
  cout << student -> getFirst() << " " << student2 -> getLast() << endl;
  cout << *student -> getID() << endl;
  printf("%.2f\n", *student2 -> getGPA());
  cout << endl;
  
  Node* firstNode = new Node;
  Node* secondNode = new Node;
  firstNode -> setStudent(student);
  firstNode -> setNext(secondNode);
  secondNode -> setStudent(student2);
  
  cout << firstNode -> getStudent() -> getFirst() << firstNode -> getStudent() -> getLast() << endl;
  cout << firstNode -> getNext() -> getStudent() -> getFirst() << firstNode -> getNext() -> getStudent() -> getLast() << endl;
  return 0;
}
