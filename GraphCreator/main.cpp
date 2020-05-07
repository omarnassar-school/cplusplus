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
#include <map>
#include "vertex.h"
#include "edge.h"

using namespace std;

//colors to make the console look "pretty"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

vector<Vertex*> vertices; //global variable for storing vertices
vector<Edge*> edges; //global variable for storing edges

void addVertex(char label) {//function for adding a vertex
  Vertex* temp = new Vertex(label);
  bool exists = false;
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {//making sure that there isn't a vertex with the given label
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


void addEdge(char firstLabel, char secondLabel, int weight) {//function for adding edges
  Edge* temp = new Edge();
  Vertex* first = NULL;
  Vertex* second = NULL;
  bool exists = false;
  
  vector<Vertex*>::iterator v;
  for (v = vertices.begin(); v != vertices.end(); v++) {//finding the first and second vertices
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
  
  if (first != NULL && second != NULL && !exists) {//if there is no current edge and both first and second exist
    temp -> setFirst(first);
    temp -> setSecond(second);
    temp -> setWeight(weight);
    edges.push_back(temp);
    cout << endl << GREEN << "Edge has been added." << RESET << endl;
  }
  else if (exists) //if there is already an edge
    cout << endl << RED << "There is already an edge connecting these two vertices." << RESET << endl;
  else //if either first or second don't exist (or both)
    cout << endl << RED << "One of the vertices does not exist." << RESET << endl;

  first = NULL;
  second = NULL;
  temp = NULL;
  delete first;
  delete second;
  delete temp;
}

void removeEdge(char firstLabel, char secondLabel, bool user) {//removing an edge (put above vertex removal so it can be called)
  if (edges.empty()) {//making sure there are edges
    if (user) //if not called from vertex removal function
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
  
  for (e = edges.begin(); e != edges.end(); e++) {//removing edge from vector
    if (((*e) -> getFirst() == first && (*e) -> getSecond() == second)) {
      edges.erase(e);
      if (user)
	cout << endl << GREEN << "The edge has been removed." << RESET << endl;
      return;
    }
  }
  
  if (first != NULL && second != NULL && user) //if edge doesn't exist
    cout << endl << RED << "This edge does not exists." << RESET << endl;
  else //if one or more of the vertices does not exist
    if (user)
      cout << endl << RED << "One of the vertices does not exists." << RESET << endl;

  first = NULL;
  second = NULL;
  delete first;
  delete second;
}

void removeVertex(char label) {//function to remove a vertex
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  bool edged = false;
  char yesno;
  
  if (vertices.empty()) {//if there are no vertices
    cout << endl << RED << "There are no vertices." << RESET << endl;
    return;
  }
  
  for (v = vertices.begin(); v != vertices.end(); v++) {//going through the vertices vector to find the vertex
    if ((*v) -> getLabel() == label) {
      for (e = edges.begin(); e != edges.end(); e++) {
	if ((*e) -> getFirst() == *v || (*e) -> getSecond() == *v) {
	  edged = true;
	}
      }
      if (edged) {//if the vertex is connected to an edge, ask if they would like to continue
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
	      
	      if ((*e) -> getFirst() == *v || (*e) -> getSecond() == *v) {//remove both an edge from and to this vertex (if it exists)
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

void findShortest(char startLabel, char  endLabel) {//finding the shortest path between two points (using Dijkstra's algorithm)
  Vertex* start = NULL;
  Vertex* end = NULL;
  
  vector<Vertex*>::iterator v;
  vector<Edge*>::iterator e;
  
  for (v = vertices.begin(); v != vertices.end(); v++) {//finding vertices with these labels
    if ((*v) -> getLabel() == startLabel) {
      start = *v;
    }

    if ((*v) -> getLabel() == endLabel) {
      end = *v;
    }
  }
  
  if (start == NULL || end == NULL) {//if one or both of the vertices don't exist
    cout << endl << RED << "One of these vertices does not exist" << RESET << endl;
    return;
  }

  if (start == end) {//if the start and end vertex are the same
    cout << endl << RED << "There is no distance between a vertex and itself." << RESET << endl;
    return;
  }
  
  if (start != NULL && end != NULL && !edges.empty()) {//run algorithm
    vector<Vertex*> visited;
    vector<Vertex*> unvisited = vertices;
    
    Vertex* current = NULL;
    
    for (v = unvisited.begin(); v != unvisited.end(); v++) {//go through vertices to find the starting vertex
      if ((*v) == start) {
	(*v) -> setDistance(0);
	current = (*v);
	break;
      }
    }

    /*Basically what this algorithm does is find the shortest distance between the starting vertex and all other vertices.
     *This isn't the most efficient method, but is relatively easy to implement. What this does is go through every unvisited
     *vertex and update its distance with the current vertex's distance if it is -1 (infinity) or if it's less than the current 
     *distance of the vertex. After going through the current vertex's connections, it will be replaced and the vertex with an 
     *unvisited vertex with the next-least distance. This will repeat until every vertex has been visited.
     */
    
    while (!unvisited.empty()) {//while there are unvisited vertices
      int distance = current -> getDistance();
      //cout << endl << "Did this at least once" << endl;
      for (v = unvisited.begin(); v != unvisited.end(); v++) {
	//cout << endl << "got here -3" << endl;
	//cout << endl << (*v) -> getLabel() << endl;
	//cout << endl << current -> getLabel() << endl;
	if ((*v) -> getLabel() != current -> getLabel()) {
	  //cout << endl << "got here -2" << endl;
	  for (e = edges.begin(); e != edges.end(); e++) {
	    //cout << endl << "got here -1" << endl;
	    if ((*e) -> getFirst() -> getLabel() == current -> getLabel() && (*e) -> getSecond() -> getLabel() == (*v) -> getLabel()) {
	      //cout << endl << "got here" << endl;
	      if ((*v) -> getDistance() == -1 || (*v) -> getDistance() > distance + (*e) -> getWeight()) {
		//cout << endl << "got here 2" << endl;
		(*v) -> setDistance(distance + (*e) -> getWeight());
	      }
	    }
	  }
	}
      }
      
      Vertex* newCurrent = NULL;
      
      for (v = unvisited.begin(); v != unvisited.end(); v++) {//moving the unvisited vertex to visited and erasing
	if ((*v) -> getLabel() == current -> getLabel()) {
	  //cout << endl << "happened" << endl;
	  unvisited.erase(v);
	  visited.push_back(current);
	  break;
	}
      }
      
      for (v = unvisited.begin(); v != unvisited.end(); v++) {//finding the next vertex
	if (newCurrent == NULL)
	  newCurrent = *v;
	
	if (newCurrent -> getDistance() > (*v) -> getDistance())
	    if ((*v) -> getDistance() > 0)
	      newCurrent = *v;
      }
      
      current = newCurrent;
    }
    
    for (v = visited.begin(); v != visited.end(); v++) {//finding the final distance at the end vertex
      if ((*v) -> getLabel() == endLabel) {
	if ((*v) -> getDistance() > 0) {
	  cout << endl << GREEN << "The distance between " << startLabel << " and " << endLabel << " is: " << (*v) -> getDistance() << endl << RESET;
	  break;
	}
	else if ((*v) -> getDistance() == -1) //if the end vertex still has a -1 (infinite) distance
	  cout << endl << RED << "The vertices are not connected." << RESET << endl;
      }
    }
    
  }
  else if (edges.empty()) //if there are no edges
    cout << endl << RED << "There are no edges." << RESET << endl;
  else //if one or both of the vertices does not exist
    cout << endl << RED << "One of the vertices does not exist." << RESET << endl;

  for (v = vertices.begin(); v != vertices.end(); v++) //resetting the vector
    (*v) -> setDistance(-1);
  
  start = NULL;
  end = NULL;
  delete start;
  delete end;
}

void printAdjacency() {//function for printing adjacency matrix
  if (vertices.empty()) {//if there are no vertices
    cout << endl << RED << "There are no vertices." << RESET << endl;
    return;
  }
  
  //Print out all labels then start a new line, add label on first space then tab and add all the weights for connected vertices
  
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
      if (v2 == v) {//vertices cannot be connected to themselves
	cout << YELLOW << "n/a" << RESET;
	connection = true;
      }
      else {
	for (e = edges.begin(); e != edges.end(); e++) {
	  if ((*e) -> getFirst() == *v) {
	    if ((*e) -> getSecond() == *v2) {//if there is an edge connected from the column and row vertices
	      cout << CYAN << (*e) -> getWeight() << RESET;
	      connection = true;
	    }
	  }
	}
      }
      
      if (!connection) //if there the vertices are not connected
	cout << RED << "none" << RESET;
      
      cout << "\t";
    }
    cout << endl;
  }

  /*cout << endl << BLUE << "For debugging purposes:" << endl;
  for (v = vertices.begin(); v != vertices.end(); v++) {
    cout << (*v) -> getLabel() << ": " << (*v) -> getDistance() << endl;
  }
  cout << RESET << endl;*/
}

int main() {//main function for getting input
  
  int numInput;
  char charInput;
  char charInput2;
  
  while (true) {//while user hasn't quit, keep going
    cout << endl << "Would you like to:" << endl;
    cout << "1: Add a vertex" << endl;
    cout << "2: Add an edge" << endl;
    cout << "3: Remove a vertex" << endl;
    cout << "4: Remove an edge" << endl;
    cout << "5: Find the shortest path between two vertices" << endl;
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
    
    else //if something other than 1-7 has been inputted
      cout << endl << RED << "Invalid Input." << RESET << endl;
    
  }
  return 0;
}
