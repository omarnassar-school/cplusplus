#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media() {


}

int Media::getType() {
  return 0;
}

int* Media::getYear() {
  return &year;
}

char* Media::getTitle() {
  return title;
}
