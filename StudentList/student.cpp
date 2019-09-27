/*Author: Omar Nassar
 *Date: 9/27/19
 *This a program that can store a list of students first and last names, id, and GPA and print them out or delete them
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {//storing all parts of student
  char first[10];
  char last[10];
  int id;
  float gpa;
};

Student* ADD();
void PRINT(vector<Student*> students);
void DELETE(vector<Student*>* students, int id);


int main() {
  vector<Student*> students;
  while (true) {
    cout << "What would you like to do next? (ADD, DELETE, PRINT, QUIT)" << endl;
    char input[10];
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "ADD") ==0 || strcmp(input, "add") == 0) {
      students.push_back(ADD());
      //cout << students.size() << endl;
    }
    if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      cout << "What is the student's ID?" << endl;
      int idInput;
      cin >> idInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      DELETE(&students, idInput);
    }
    if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      PRINT(students);
    }
    if (strcmp(input,"QUIT") == 0 || strcmp(input, "quit") == 0) {
      break;
    }
  }
  
  return 0;
}

Student* ADD() {
  Student* newStudent = new Student();
  cout << "Please enter a first name." << endl;
  cin >> newStudent -> first;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter a last name." << endl;
  cin >> newStudent -> last;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter an id number." << endl;
  cin >> newStudent -> id;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter a gpa." << endl;
  cin >> newStudent -> gpa;
  cin.clear();
  cin.ignore(1000000, '\n');
  return newStudent;
}

void PRINT(vector<Student*> students) {
  //cout << "test" << endl;
  vector<Student*>::iterator i;
  for (i = students.begin(); i != students.end(); i++) {
    cout << (*i) -> first << " " << (*i) -> last << ", " << (*i) -> id << ", " <<
      fixed << setprecision(2) << (*i) -> gpa << endl;
  }
}

void DELETE(vector<Student*>* students, int id) {
  vector<Student*>::iterator i;
  for (i = students -> begin(); i != students -> end(); i++) {
    if((*i) -> id == id) {
      delete *i;
      students -> erase(i);
      return;
    }
  }
  cout << "Invalid ID." << endl;
}
