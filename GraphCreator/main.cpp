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
  vertices.push_back(temp);
  temp = NULL;
  delete temp;
}

void removeVertex() {
  
}

void addEdge(Vertex* first, Vertex* second, int weight) {
  
}

void removeEdge() {

}

void findShortest(Vertex* first, Vertex* second) {
  
}

void printAdjacency() {
  
}

int main() {
  
  int numInput;
  char charInput;
  
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

    }

    else if (numInput == 3) {//remove vertex

    }

    else if (numInput == 4) {//remove edge

    }

    else if (numInput == 5) {//shortest path

    }

    else if (numInput == 6) {//print

    }

    else if (numInput == 7) {//quit
      break;
    }

    else {
      cout << "Invalid Input." << endl;
      break;
    }
  }
  return 0;
}
