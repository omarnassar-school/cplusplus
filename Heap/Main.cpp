/*Author: Omar Nassar
 *Date: 2/6/20
 *This is a program that creates a heap that can take input from either the console or a text file.
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cmath>

//#include "Node.h"

using namespace std;

void parseInput(int*& parsed, char input[], int &counter);
void heapify(int*& arr, int n, int i);
void buildHeap(int*& arr, int n);
void printHeap(int* arr, int n);
void sortHeap(int* arr, int n);
void visualPrint(int* arr, int n);

int main() {
  //cout << pow(2, 0);
  int method;
  char fileName[20];
  char input[1000];
  int* parsed;
  int parsedSize;
  cout << endl << "How would you like to input your numbers? (1 for console, 2 for file)" << endl << ">> ";
  cin >> method;
  cin.clear();
  cin.ignore(1000000, '\n');
  if (method == 1) {//getting input from console, store in char array
    cout << endl << "Please input your numbers with spaces in between them here: " << endl << ">> ";
    cin.get(input, 1000);
    cin.clear();
    cin.ignore(1000000, '\n');
    //cout << input << endl;
  }
  else if (method == 2) {//getting input from file, store in char array
    cout << endl << "What is the name of the file?" << endl << ">> ";
    cin.get(fileName, 20);
    cin.clear();
    cin.ignore(1000000, '\n');
    streampos size;
    ifstream file(fileName, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
      //cout << input << endl;
    }
  }
  else {
    return 0;
  }
  parseInput(parsed, input, parsedSize);
  /*cout << endl << "There are: " << parsedSize << " numbers." << endl;
  for (int i = 0; i < parsedSize; i++) {
    cout << parsed[i] << " ";
  }
  cout << endl;*/
  buildHeap(parsed, parsedSize);
  cout << endl << "The heap in array form: ";
  printHeap(parsed, parsedSize);
  cout << endl << "Visual printing of the heap: " << endl;
  visualPrint(parsed, parsedSize);
  cout << "The input sorted from greatest to least: ";
  sortHeap(parsed, parsedSize);
  //printHeap(parsed, parsedSize);
  return 0;
}

void parseInput(int*& parsed, char input[], int &counter) {//remove spaces between the chars, make int pointer (array)
  /*This works by finding a space and adding a pointer, then moving forward in the array until it finds another
   *space. It then adds another pointer and adds the characters between the spaces to a new char array, which is then
   *turned to an int and added to the int pointer. This method was originally created by Zareef Amyeen, but I modified
   *it for use with an int pointer instead of a vector. 
   */
  int pointers[2];
  int value;
  int* temp;
  counter = 1;
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0]];
      for (int i = pointers[0] + 1; i < pointers[1]; i++) {
	newArray[j] = input[i];
	//cout << newArray[i] << endl;
	j = j + 1;
      }
      newArray[j] = '\0';
      temp = parsed;
      parsed = new int[counter];
      if (counter > 1) {
	for (int i = 0; i < counter - 1; i++) {
	  parsed[i] = temp[i];
	  //cout << parsed[i] << endl;
	}
      }
      parsed[counter - 1] = atoi(newArray);
      /*for (int i = 0; i < counter; i++) {
	cout << endl << parsed[i] << endl;
	}*/
      counter = counter + 1;
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;
  for (int i = pointers[0] + 1; i < strlen(input); i++) {
    newArray[j] = input[i];
    //cout << newArray[j];
    j = j + 1;
  }
  newArray[j] = '\0';
  temp = parsed;
  parsed = new int[counter];
  if (counter > 1) {
    for (int i = 0; i < counter - 1; i++) {
      parsed[i] = temp[i];
      //cout << parsed[i] << endl;
    }
  }
  parsed[counter - 1] = atoi(newArray);
  /*for (int i = 0; i < counter; i++) {
    cout << endl << parsed[i] << endl;
    }*/

}

void heapify(int*& arr, int n, int i) {//heapifying a subtree rooted with node i which is an index in arr[], n is size
  int largest = i; //initialize largest as root
  int l = 2 * i + 1; //left child
  int r = 2 * i + 2; //right child

  //if left is larger than root
  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }

  //if right is larger than root
  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }

  //if largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildHeap(int*& arr, int n) {//building the heap
  int startIdx = (n / 2) - 1;

  for (int i = startIdx; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

void printHeap(int* arr, int n) {//printing the heap as an array
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sortHeap(int* arr, int n) {//sorting the heap from greatest to least
  /*for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
  int counter = 0;
  int* temp = new int[n];
  for (int i = n - 1; i >= 0; i--) {
    temp[i] = arr[counter];
    counter++;
  }
  arr = temp;*/
  //printHeap(arr, n);
  int counter = n;
  int* temp = arr;
  arr = new int[n];
  for (int i = 0; i < n; i++) {//taking the head of the array and adding it to the final array
    arr[i] = temp[0];
    //cout << arr[i] << endl;

    //removing the head
    int* temp2 = new int[counter - 1];
    for (int j = 0; j < counter - 1; j++) {
      temp2[j] = temp[j + 1];
      //cout << temp2[j] << " ";
    }
    //cout << endl;
    counter = counter - 1;
    temp = temp2;
    //rebuilding heap so the largest number will be the head
    buildHeap(temp, counter);
  }
  printHeap(arr, n);
}

void visualPrint(int* parsed, int n) {//printing the array visually (would add spaces but haven't fully figured it out)
  //bool whichSlash = true;
  int* temp = parsed;
  //moving indexes one spot over for calculatiosn
  parsed = new int[n + 1];
  for (int i = 0; i < n; i++) {
    parsed[i + 1] = temp[i];
  }  
  int levels = ceil(log2(n)); //how many levels are in the array
  int index = 1;
  for (int i = 0; i < levels; i++) {
    int num = index;
    for (int j = 0; j < num; j++) {//the index of the first value of each level is the amount of numbers in that level
      if (index <= n) {
	cout << parsed[index] << " ";
	index = index + 1;
      }
    }
    cout << endl;
    if (i < levels - 1) {
      for (int k = 0; k < pow(2, i); k++) {//add slashes between each level except last
	cout << "/\\";
      }
      cout << endl;
    }
  }
  cout << endl;
  /*for (int i = 0; i < n; i++) {
    /*while (true) {
      cout << parsed[i] << " ";
      if (floor(log2(i)) == log2(i)) {
	cout << endl;
	break;
      }
      i = i + 1;
      }
    
    int x = i;
    for (int j = 0; j < pow(2, x); j++) {
      cout << parsed[i] << " ";
      i = i + 1;
    }
    i = i - 1;
    cout << endl;
    
    for (int k = 0; k < log2(x + 1); k++) {
      //if (whichSlash == true) {
	cout << "/";
	//whichSlash = false;
	//}
	//else if (whichSlash == false) {
	cout << "\\";
	//whichSlash = true;
	//}
    }
    cout << endl;
    //whichSlash = true;
  }*/
}
