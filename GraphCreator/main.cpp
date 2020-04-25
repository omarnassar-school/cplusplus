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

void removeVertex(char label) {
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  bool edged = false;
  char yesno;
  
  if (vertices.size() == 0) {
    cout << endl << "There are no vertices." << endl;
    return;
  }

  int i = 0;
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
	  int j = 0;
	  for (e = edges.begin(); e != edges.end(); e++) {
	    if ((*e) -> getFirst() == *v || (*e) -> getSecond() == *v) {
	      //delete *e;
	      edges.erase(e);
	    }
	    j++;
	  }
	  //delete *v;
	  vertices.erase(v);
	  cout << endl << "The vertex was removed." << endl; 
	  return;
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
    i++;
  }

  cout << endl << "There is no vertex with that label." << endl;
  
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
    else if ((*v) -> getLabel() == secondLabel) {
      second = *v;
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
