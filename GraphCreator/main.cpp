/* Graph Creator: A program that can create weighted edge directed graphs and find the shortest path using Dijkstra's Algorithm
 *Author: Omar Nassar
 *Date: 4/16/2020
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include "vertex.h"
#include "edge.h"

using namespace std;

vector<Vertex*> vertices;
vector<Edge*> edges;

void addVertex(char label) {
  Vertex* temp = new Vertex(label);
  bool exists = false;
  vector<Vertex*>::iterator i;
  for (i = vertices.begin(); i != vertices.end(); i++) {
    if ((*i) -> getLabel() == label)
      exists = true;
  }
  
  if (!exists) {
    vertices.push_back(temp);
    cout << endl << "Vertex has been added." << endl;
  }
  else
    cout << endl << "Cannot have duplicate labels." << endl;
  
  temp = NULL;
  delete temp;
}

void removeVertex() {
  
}

void addEdge(char firstLabel, char secondLabel, int weight) {
  Edge* temp = new Edge();
  Vertex* first = NULL;
  Vertex* second = NULL;
  bool exists = false;
  
  vector<Vertex*>::iterator i;
  for (i = vertices.begin(); i != vertices.end(); i++) {
    if ((*i) -> getLabel() == firstLabel) {
      first = *i;
    }
    else if ((*i) -> getLabel() == secondLabel) {
      second = *i;
    }
  }
  
  vector<Edge*>::iterator e;
  for (e = edges.begin(); e != edges.end(); e++) {
    if (((*e) -> getFirst() == first && (*e) -> getSecond() == second))
      exists = true;
  }
  
  if (first != NULL && second != NULL && !exists) {
    temp -> setFirst(first);
    temp -> setSecond(second);
    temp -> setWeight(weight);
    edges.push_back(temp);
    cout << endl << "Edge has been added." << endl;
  }
  else if (exists)
    cout << endl << "There is already an edge connecting these two vertices." << endl;
  else
    cout << endl << "One of the vertices does not exist." << endl;

  first = NULL;
  second = NULL;
  temp = NULL;
  delete first;
  delete second;
  delete temp;
}

void removeEdge(char firstLabel, char secondLabel) {

}

void findShortest(char firstLabel, char  secondLabel) {
  
}

void printAdjacency() {
  if (vertices.empty())
    return;
  
  cout << "\t";
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    cout << (*v) -> getLabel() << "\t";
  }
  cout << endl;

  vector<Vertex*>::iterator v2;
  vector<Edge*>::iterator e;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    cout << (*v) -> getLabel() << "\t";
    for (v2 = vertices.begin(); v2 != vertices.end(); v2++) {
      bool connection = false;
      if (v2 == v) {
	cout << "n/a";
	connection = true;
      }
      else {
	for (e = edges.begin(); e != edges.end(); e++) {
	  if ((*e) -> getFirst() -> getLabel() == (*v) -> getLabel()) {
	    if ((*e) -> getSecond() -> getLabel() == (*v2) -> getLabel() ) {
	      cout << (*e) -> getWeight();
	      connection = true;
	    }
	  }
	}
      }
      
      if (!connection)
	cout << "none";
      
      cout << "\t";
    }
    cout << endl;
  }
}

int main() {
  
  int numInput;
  char charInput;
  char charInput2;
  
  while (true) {
    cout << endl << "Would you like to:" << endl;
    cout << "1: Add a vertex" << endl;
    cout << "2: Add an edge" << endl;
    cout << "3: Remove a vertex" << endl;
    cout << "4: Remove an edge" << endl;
    cout << "5: Find the shortest path between two points" << endl;
    cout << "6: Print the adjacency matrix" << endl;
    cout << "7: Quit" << endl;
    cout << endl << ">> ";
    
    cin >> numInput;
    cin.clear();
    cin.ignore(1000000, '\n');
    
    if (numInput == 1) {//add vertex
      cout << endl << "What character will you assign the vertex?" << endl << ">> ";
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      addVertex(charInput);
    }

    else if (numInput == 2) {//add edge
      cout << endl << "What is the label of the first vertex?" << endl << ">> ";
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the second vertex?" << endl << ">> ";
      cin >> charInput2;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the weight of this edge?" << endl << ">> ";
      cin >> numInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      addEdge(charInput, charInput2, numInput);
    }

    else if (numInput == 3) {//remove vertex
      
    }

    else if (numInput == 4) {//remove edge

    }

    else if (numInput == 5) {//shortest path

    }

    else if (numInput == 6) //print
      printAdjacency();

    else if (numInput == 7) {//quit
      break;
    }

    else
      cout << "Invalid Input." << endl;
    
  }
  return 0;
}
