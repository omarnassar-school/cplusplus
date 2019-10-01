#include <iostream>
#include <cstring>
#include "media.h"
#include "movies.h"

using namespace std;

Movies::Movies() {


}

int Movies::getType() {
  return 0;
}

char* Movies::getDirector() {
  return director;
}

int* Movies::getDuration() {
  return &duration;
}

float* Movies::getRating() {
  return &rating;
}
