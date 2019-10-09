#ifndef music_h
#define music_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {//music is a child of media
 public:
  Music();
  virtual int getType(); //storing type
  char* getArtist(); //pointer to artist
  int* getDuration(); //pointer to duration
  char* getPublisher(); //pointer to publisher
 private:
  char artist[50]; //storing artist
  int duration; //storing duration
  char publisher[100]; //storing publisher
};

#endif
