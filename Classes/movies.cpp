#include <iostream>
#include <cstring>
#include "media.h"
#include "movies.h"

using namespace std;

Movies::Movies() {//calling .h file


}

int Movies::getType() {//sending type to media class
  return 0;
}

char* Movies::getDirector() {//sending director to .h file
  return director;
}

int* Movies::getDuration() {//sending duration to .h file
  return &duration;
}

float* Movies::getRating() {//sending rating to .h file
  return &rating;
}
