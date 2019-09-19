#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  char str[80];
  char str2[80];
  cin.get(str, 80);
  cin.get();
  //cout << str << endl;

  //found out about !isalpha and !isdigit from stackoverflow
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i]) && !isdigit(str[i])) {//making sure character is alphanumeric
      for (int k = i; str[k] != '\0'; k++) {
	str[k] = str[k+1];
      }
      i--;
    }
  }

  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  
  //cout << str << endl;
  //cout << strlen(str) << endl;

  int counter = strlen(str);
  for (int i = 0; i < strlen(str); i++) {//reversing the cstring
    str2[i] = str[counter - 1];
    counter--;
  }
  
  //cout << str2 << endl;
  //cout << strlen(str2) << endl;

  //cout << strcmp(str, str2) << endl;
  
  if (strcmp(str, str2) == 0) {//if all the characters are the same
    cout << "Palindrome." << endl;
  }
  else {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
