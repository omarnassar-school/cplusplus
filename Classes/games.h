#ifndef games_h
#define games_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Games : public Media {//games is a child of media
 public:
  Games();
  virtual int getType(); //storing type
  char* getPublisher(); //pointer to publisher
  float* getRating(); //pointer to rating
 private:
  char publisher[100]; //storing publisher
  float rating; //storing rating
};

#endif
