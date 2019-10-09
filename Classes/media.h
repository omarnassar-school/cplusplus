#ifndef media_h
#define media_h

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  int* getYear(); //pointing to year
  char* getTitle(); //pointing to title
  virtual int getType(); //storing type
 private:
  int year; //storing year
  char title[100]; //storing title
};

#endif
