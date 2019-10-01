#include <iostream>
#include <cstring>
#include "games.h"
#include "media.h"

using namespace std;

Games::Games() {

  
}

int Games::getType() {
  return 1;
}

char* Games::getPublisher() {
  return publisher;
}

float* Games::getRating() {
  return &rating;
}
