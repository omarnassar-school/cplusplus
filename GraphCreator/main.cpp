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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

vector<Vertex*> vertices;
vector<Edge*> edges;

void addVertex(char label) {
  Vertex* temp = new Vertex(label);
  bool exists = false;
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == label)
      exists = true;
  }
  
  if (!exists) {
    vertices.push_back(temp);
    cout << endl << GREEN << "Vertex has been added." << RESET << endl;
  }
  else
    cout << endl << RED << "Cannot have duplicate labels." << RESET << endl;
  
  temp = NULL;
  delete temp;
}


void addEdge(char firstLabel, char secondLabel, int weight) {
  Edge* temp = new Edge();
  Vertex* first = NULL;
  Vertex* second = NULL;
  bool exists = false;
  
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == firstLabel) {
      first = *v;
    }
    
    if ((*v) -> getLabel() == secondLabel) {
      second = *v;
    }
  }
  
  if (first == second) {
    cout << endl << RED << "You cannot connect a vertex to itself." << RESET << endl;
    return;
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
    cout << endl << GREEN << "Edge has been added." << RESET << endl;
  }
  else if (exists)
    cout << endl << RED << "There is already an edge connecting these two vertices." << RESET << endl;
  else
    cout << endl << RED << "One of the vertices does not exist." << RESET << endl;

  first = NULL;
  second = NULL;
  temp = NULL;
  delete first;
  delete second;
  delete temp;
}

void removeEdge(char firstLabel, char secondLabel, bool user) {
  if (edges.empty()) {
    if (user)
      cout << endl << RED << "There are no edges." << RESET << endl;
    return;
  }
  
  Vertex* first = NULL;
  Vertex* second = NULL;
  
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == firstLabel)
      first = *v;

    if((*v) -> getLabel() == secondLabel)
      second = *v;
  }
  
  if (first == second) {
    cout << endl << RED << "A vertex cannot be connected to itself." << RESET << endl;
    return;
  }
  
  for (e = edges.begin(); e != edges.end(); e++) {
    if (((*e) -> getFirst() == first && (*e) -> getSecond() == second)) {
      edges.erase(e);
      if (user)
	cout << endl << GREEN << "The edge has been removed." << RESET << endl;
      return;
    }
  }
  
  if (first != NULL && second != NULL && user)
    cout << endl << RED << "This edge does not exists." << RESET << endl;
  else
    if (user)
      cout << endl << RED << "One of the vertices does not exists." << RESET << endl;

  first = NULL;
  second = NULL;
  delete first;
  delete second;
}

void removeVertex(char label) {
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  bool edged = false;
  char yesno;
  
  if (vertices.size() == 0) {
    cout << endl << RED << "There are no vertices." << RESET << endl;
    return;
  }
  
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == label) {
      for (e = edges.begin(); e != edges.end(); e++) {
	if ((*e) -> getFirst() == *v || (*e) -> getSecond() == *v) {
	  edged = true;
	}
      }
      if (edged) {
	cout << endl << YELLOW << "The vertex is connected to an edge. Would you still like to remove? (y/n)";
	cout << endl << GREEN << ">> " << RESET;
	cin >> yesno;
	cin.clear();
	cin.ignore(1000000, '\n');
        if (yesno == 'y') {
	  bool finished = false;
	  while(!finished) {
	    for (e = edges.begin(); e != edges.end(); e++) {
	      if (e == edges.end() - 1)
		finished = true;
	      
	      if ((*e) -> getFirst() == *v || (*e) -> getSecond() == *v) {
		removeEdge((*e) -> getFirst() -> getLabel(), (*e) -> getSecond() -> getLabel(), false);
		removeEdge((*e) -> getSecond() -> getLabel(), (*e) -> getFirst() -> getLabel(), false);
		break;
	      }
	    }
	  }
	  //delete *v;
	  vertices.erase(v);
	  cout << endl << GREEN << "The vertex was removed." << RESET << endl; 
	  return;
	}
      
	else {
	  cout << endl << GREEN << "The vertex was not removed." << RESET << endl;
	  return;
	}
      }
      
      else {
	//delete *v;
	vertices.erase(v);
	cout << endl << GREEN << "The vertex has been removed." << RESET << endl;
	return;
      }
    }
  }
  
  
  cout << endl << RED << "There is no vertex with that label." << RESET << endl;
  
}

void findShortest(char startLabel, char  endLabel) {
  Vertex* start = NULL;
  Vertex* end = NULL;
  
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == startLabel) {
      start = *v;
    }

    if ((*v) -> getLabel() == endLabel) {
      end = *v;
    }
  }
  
  if (start == end) {
    cout << endl << RED << "There is no distance between a vertex and itself." << RESET << endl;
    return;
  }
  
  if (start != NULL && end != NULL && !edges.empty()) {
    
  }
  else if (edges.empty())
    cout << endl << RED << "There are no edges." << RESET << endl;
  else
    cout << endl << RED << "One of the vertices does not exist." << RESET << endl;
  
  start = NULL;
  end = NULL;
  delete start;
  delete end;
}

void printAdjacency() {
  if (vertices.empty()) {
    cout << endl << RED << "There are no vertices." << RESET << endl;
    return;
  }
  
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
	cout << YELLOW << "n/a" << RESET;
	connection = true;
      }
      else {
	for (e = edges.begin(); e != edges.end(); e++) {
	  if ((*e) -> getFirst() == *v) {
	    if ((*e) -> getSecond() == *v2) {
	      cout << CYAN << (*e) -> getWeight() << RESET;
	      connection = true;
	    }
	  }
	}
      }
      
      if (!connection)
	cout << RED << "none" << RESET;
      
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
    cout << endl << GREEN << ">> " << RESET;
    
    cin >> numInput;
    cin.clear();
    cin.ignore(1000000, '\n');
    
    if (numInput == 1) {//add vertex
      cout << endl << "What character will you assign the vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      addVertex(charInput);
    }

    else if (numInput == 2) {//add edge
      cout << endl << "What is the label of the first vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the second vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput2;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the weight of this edge?" << endl << GREEN ">> " << RESET;
      cin >> numInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      addEdge(charInput, charInput2, numInput);
    }

    else if (numInput == 3) {//remove vertex
      cout << endl << "What is the label of the vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      removeVertex(charInput);
    }

    else if (numInput == 4) {//remove edge
      cout << endl << "What is the label of the first vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the second vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput2;
      cin.clear();
      cin.ignore(1000000, '\n');
      removeEdge(charInput, charInput2, true);
    }
    
    else if (numInput == 5) {//shortest path
      cout << endl << "What is the label of the starting vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the ending vertex?" << endl << GREEN << ">> " << RESET;
      cin >> charInput2;
      cin.clear();
      cin.ignore(1000000, '\n');
      findShortest(charInput, charInput2);
    }
    
    else if (numInput == 6) //print
      printAdjacency();

    else if (numInput == 7) {//quit
      break;
    }
    
    else
      cout << endl << RED << "Invalid Input." << RESET << endl;
    
  }
  return 0;
}
