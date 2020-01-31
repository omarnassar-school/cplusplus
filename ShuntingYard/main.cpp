/* Author: Omar Nassar
 * Date: 12/5/2019
 * This is a program that can translate infix to postfix and create an expression tree.
 * This can then be outputted as either infix, prefix, or postfix.
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stack>
#include <queue>
#include "node.h"


using namespace std;

void parseInput(vector<char*> &parsedInput, char input[100]);
void printVector(vector<char*>);
void intopost(vector<char*>& parsedInput, queue<char*>& Queue);
void printQueue(queue<char*> Queue);
int precedence(char* op);
bool isOperand(char* op);
void constructTree(stack<Node*>& Tree, queue <char*>& Queue);
void infix(Node* Root);
void postfix(Node* Root);
void prefix(Node* Root);

int main() {
  char input[100];
  vector<char*> parsedInput;
  queue<char*> Queue;
  cout << "Enter an infix expression" << endl << endl;
  cin.get(input, 100);
  cin.clear();
  cin.ignore(1000000, '\n');
  parseInput(parsedInput, input);
  intopost(parsedInput, Queue);
  //printQueue(Queue);
  stack <Node*> ExpressionTree;
  constructTree(ExpressionTree, Queue);
  
  char method[8];
  while (true) {
    cout << endl << "What way would you like to output this expression? (Infix, Prefix, Postfix)" << endl << endl;
    cin.get(method, 8);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(method, "Infix") == 0 || strcmp(method, "infix") == 0) {
      cout << endl; // << "Infix" << endl;
      infix(ExpressionTree.top());
      break;
    }
    else if (strcmp(method, "Prefix") == 0 || strcmp(method, "prefix") == 0) {
      cout << endl; // << "Prefix" << endl;
      prefix(ExpressionTree.top());
      break;
    }
    else if (strcmp(method, "Postfix") == 0 || strcmp(method, "postfix") == 0) {
      cout << endl; // << "Postfix" << endl;
      postfix(ExpressionTree.top());
      break;
    }
    else {
      cout << endl << "Invalid Input" << endl;
    }
  }
  
  return 0;
}

void parseInput(vector<char*> &parsedInput, char input[100]) {
  //cout << "works" << endl;
  int pointers[2];
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0]];
      for (int i = pointers[0] + 1; i < pointers[1]; i++) {
	newArray[j] = input[i];
	j = j + 1;
      }
      newArray[j] = '\0';
      parsedInput.push_back(newArray);
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++){
    newArray[j] = input[i];
    j = j + 1;
  }
  newArray[j] = '\0';
  parsedInput.push_back(newArray);
  //printVector(parsedInput);
}

void printVector(vector<char*> parsedInput) {
  for (int i = 0; i < parsedInput.size(); i ++) {
    cout << parsedInput[i];
  }
  cout << endl;
}

void printQueue(queue<char*> Queue) {
  cout << endl;
  while (!Queue.empty()) {
    cout << Queue.front() << " ";
    Queue.pop();
  }
  cout << endl;
}

void intopost(vector<char*>& parsedInput, queue<char*>& Queue) {
  stack<char*> Stack;
  int i = 0;
  while (i < parsedInput.size()) {
    if (strlen(parsedInput[i]) != 1 || isOperand(parsedInput[i])) {
      Queue.push(parsedInput[i]);
    }
    else if (strcmp(parsedInput[i], "(") == 0) {
      Stack.push(parsedInput[i]);
    }
    else if (strcmp(parsedInput[i], ")") == 0) {
      while (strcmp(Stack.top(), "(") != 0) {
	Queue.push(Stack.top());
	Stack.pop();
	if (Stack.empty()) {
	  break;
	}
      }
      Stack.pop();
    }
    else {
      if (!Stack.empty()) {
	while ( (precedence(Stack.top()) > precedence(parsedInput[i]) || ( (precedence(Stack.top()) == precedence(parsedInput[i])) && (strcmp(Stack.top(),"^") != 0) ) ) && (strcmp(Stack.top(),"(") != 0)){
	  Queue.push(Stack.top());
	  Stack.pop();
	  if (Stack.empty()) {
	    break;
	  }
	}
      }
      Stack.push(parsedInput[i]);
    }
    i = i + 1;
  }
  while (!Stack.empty()){
    Queue.push(Stack.top());
    Stack.pop();
  }
}

int precedence(char* op) {
  if (strcmp(op, "^") == 0) {
    return 3;
  }
  else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) {
    return 2;
  }
  else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) {
    return 1;
  }
  return 0;
}

bool isOperand(char* op) {
  if (isalnum(op[0])) {
    return true;
  }
  return false;
}

void constructTree(stack<Node*>& Tree, queue<char*>& Queue) {
  while (!Queue.empty()) {
    if (isOperand(Queue.front())) {
      Node* newNode = new Node();
      newNode -> setValue(Queue.front());
      Queue.pop();
      Tree.push(newNode);
    }
    else {
      Node* newNode = new Node();
      newNode -> setValue(Queue.front());
      Queue.pop();
      newNode -> setRight(Tree.top());
      Tree.pop();
      newNode -> setLeft(Tree.top());
      Tree.pop();
      Tree.push(newNode);
    }
  }
}

void infix(Node* Root) {
  if (Root != NULL) {
    if (!isOperand(Root -> getValue())) {
      cout << "( ";
    }
    infix(Root -> getLeft());
    cout << Root -> getValue() << " ";
    infix(Root -> getRight());
    if (!isOperand(Root -> getValue())) {
      cout << ") ";
    }   
  }
}

void postfix(Node* Root) {
  if (Root != NULL) {
    postfix(Root -> getLeft());
    postfix(Root -> getRight());
    cout << Root -> getValue() << " ";
  }
}

void prefix(Node* Root) {
  if (Root != NULL) {
    cout << Root -> getValue() << " ";
    prefix(Root -> getLeft());
    prefix(Root -> getRight());				  
  }
}
