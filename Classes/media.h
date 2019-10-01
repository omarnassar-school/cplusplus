#ifndef media_h
#define media_h

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  int* getYear();
  char* getTitle();
  virtual int getType();
 private:
  int year;
  char title[100];
};

#endif
