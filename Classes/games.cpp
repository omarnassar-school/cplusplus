#include <iostream>
#include <cstring>
#include "games.h"
#include "media.h"

using namespace std;

Games::Games() {//calling .h file

  
}

int Games::getType() {//storing type
  return 1;
}

char* Games::getPublisher() {//sending publisher to .h file
  return publisher;
}

float* Games::getRating() {//sending rating to .h file
  return &rating;
}
