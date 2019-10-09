#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music() {//calling .h file


}

int Music::getType() {//storing type
  return 2;
}

char* Music::getArtist() {//sending artist to .h file
  return artist;
}

int* Music::getDuration() {//sending duration to .h file
  return &duration;
}

char* Music::getPublisher() {//sending publisher to .h file
  return publisher;
}
