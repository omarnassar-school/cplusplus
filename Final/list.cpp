#include "list.h"
#include <cstring>

using namespace std;

void removeHead(node * & head) {
  if (head -> next != NULL) {
    node * temp = head;
    head = head -> next;
    //destroy(temp);
    delete temp;
  }
}
