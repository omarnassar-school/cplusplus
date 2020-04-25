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
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    if ((*v) -> getLabel() == label)
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
    cout << endl << "You cannot connect a vertex to itself." << endl;
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

void removeEdge(char firstLabel, char secondLabel, bool user) {
  if (edges.empty()) {
    if (user)
      cout << endl << "There are no edges." << endl;
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
    cout << endl << "A vertex cannot be connected to itself." << endl;
    return;
  }
  
  for (e = edges.begin(); e != edges.end(); e++) {
    if (((*e) -> getFirst() == first && (*e) -> getSecond() == second)) {
      edges.erase(e);
      if (user)
	cout << endl << "The edge has been removed." << endl;
      return;
    }
  }
  
  if (first != NULL && second != NULL)
    cout << endl << "This edge does not exists." << endl;
  else
    cout << endl << "One of the vertices does not exists." << endl;

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
    cout << endl << "There are no vertices." << endl;
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
	cout << endl << "The vertex is connected to an edge. Would you still like to remove? (y/n)" << endl << ">> ";
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
	  cout << endl << "The vertex was removed." << endl; 
	  return;
	}
      }
      else {
	cout << endl << "The vertex was not removed." << endl;
	return;
      }
    }
    else {
      //delete *v;
      vertices.erase(v);
      cout << endl << "The vertex has been removed." << endl;
      return;
    }
  }
  
  
  cout << endl << "There is no vertex with that label." << endl;
  
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
    cout << endl << "There is no distance between a vertex and itself." << endl;
    return;
  }
  
  if (start != NULL && end != NULL && !edges.empty()) {
    
  }
  else if (edges.empty())
    cout << endl << "There are no edges." << endl;
  else
    cout << endl << "One of the vertices does not exist." << endl;
  
  start = NULL;
  end = NULL;
  delete start;
  delete end;
}

void printAdjacency() {
  if (vertices.empty()) {
    cout << endl << "There are no vertices." << endl;
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
	cout << "n/a";
	connection = true;
      }
      else {
	for (e = edges.begin(); e != edges.end(); e++) {
	  if ((*e) -> getFirst() == *v) {
	    if ((*e) -> getSecond() == *v2) {
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
      cout << endl << "What is the label of the vertex?" << endl << ">> ";
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      removeVertex(charInput);
    }

    else if (numInput == 4) {//remove edge
      cout << endl << "What is the label of the first vertex?" << endl << ">> ";
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the second vertex?" << endl << ">> ";
      cin >> charInput2;
      cin.clear();
      cin.ignore(1000000, '\n');
      removeEdge(charInput, charInput2, true);
    }
    
    else if (numInput == 5) {//shortest path
      cout << endl << "What is the label of the starting vertex?" << endl << ">> ";
      cin >> charInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl << "What is the label of the ending vertex?" << endl << ">> ";
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
      cout << "Invalid Input." << endl;
    
  }
  return 0;
}
