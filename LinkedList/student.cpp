#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student() {
  
}

char* Student::getFirst() {
  return first;
}

void Student::setName(char* inFirst) {
  first = inFirst;
}

char* Student::getLast() {
  return last;
}

void Student::setLast(char* inLast) {
  last = inLast;
}

int Student::getID() {
  return ID;
}

void Student::setID(int inID) {
  ID = inID;
}

float Student::getGPA() {
  return GPA;
}

void Student::setGPA(float inGPA) {
  GPA = inGPA;
}

void Student::getStudent() {
  return student;
}
