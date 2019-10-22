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

Student* ADD(); //adding a new student
void PRINT(vector<Student*> students);
void DELETE(vector<Student*>* students, int id);


int main() {
  vector<Student*> students; //vector for storing students
  while (true) {
    cout << "What would you like to do next? (ADD, DELETE, PRINT, QUIT)" << endl;
    char input[10]; //storing input
    cin.get(input, 10); //getting next instruction
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      students.push_back(ADD()); //adding more students
      //cout << students.size() << endl;
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      cout << "What is the student's ID?" << endl;
      int idInput;
      cin >> idInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      DELETE(&students, idInput); //function for deleting students
    }
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      PRINT(students); //printint students
    }
    else if (strcmp(input,"QUIT") == 0 || strcmp(input, "quit") == 0) {
      break; //exiting loop
    }
    else {//if none of the four functions is given as input
      cout << "Invalid Input. Try Again" << endl;
    }
    
  }
  
  return 0;
}

Student* ADD() {
  Student* newStudent = new Student(); //making a new student 
  cout << "Please enter a first name." << endl;
  cin >> newStudent -> first; //getting first name
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter a last name." << endl;
  cin >> newStudent -> last; //getting last name
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter an id number." << endl;
  cin >> newStudent -> id; //getting id
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "Please enter a gpa." << endl;
  cin >> newStudent -> gpa; //getting gpa
  cin.clear();
  cin.ignore(1000000, '\n');
  return newStudent; //returning the value into the vector
}

void PRINT(vector<Student*> students) {
  //cout << "test" << endl;
  vector<Student*>::iterator i; //goes through the vector
  for (i = students.begin(); i != students.end(); i++) {
    cout << (*i) -> first << " " << (*i) -> last << ", " << (*i) -> id << ", " <<
      fixed << setprecision(2) << (*i) -> gpa << endl;
  }
}

void DELETE(vector<Student*>* students, int id) {
  vector<Student*>::iterator i; //going through vector
  for (i = students -> begin(); i != students -> end(); i++) {
    if((*i) -> id == id) { //if id is equal to the student's id
      delete *i; //delete student from memory
      students -> erase(i); //erase student from vectore
      return;
    }
  }
  cout << "Invalid ID." << endl; //if there is no student corresponding to the id
}
