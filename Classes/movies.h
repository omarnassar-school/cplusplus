#ifndef movies_h
#define movies_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movies : public Media {
 public:
  Movies();
  virtual int getType();
  char* getDirector();
  int* getDuration();
  float* getRating();
 private:
  char director[50];
  int duration;
  float rating;
};

#endif
