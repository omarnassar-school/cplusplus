#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char str[20];
  char str2[20];
  cin.get(str, 20);
  cin.get();
  int count = 0;
  for (int i = 0; i < 20; i++) {
    if (str[i] != '\0') {
      str2[count] = str[i];
      count++;
    }
    
  }
  cout << str << endl;
  cout << str2 << endl;
  return 0;
}
