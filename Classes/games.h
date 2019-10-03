#ifndef games_h
#define games_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Games : public Media {
 public:
  Games();
  virtual int getType();
  char* getPublisher();
  float* getRating();
 private:
  char publisher[100];
  float rating;
};

#endif
