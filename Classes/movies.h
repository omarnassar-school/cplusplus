#ifndef movies_h
#define movies_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movies : public Media {//movies is a child of media
 public:
  Movies();
  virtual int getType(); //storing type
  char* getDirector(); //pointing to director
  int* getDuration(); //pointing to duration
  float* getRating(); //pointing to rating
 private:
  char director[50]; //storing director 
  int duration; //storing duration
  float rating; //storing rating
};

#endif
