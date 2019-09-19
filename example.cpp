#include <iostream>
#include <cstring>

using namespace std;

float pow(float a, int x);

int main()
{
  float number = 3.0;
  int power = 2;
  float result = pow(number, power);
  cout << result << endl;
  
  return 0;
}

float pow(float a, int x) {
  float answer = a;
  for (int i = 0; i < x - 1; i++) {
    answer = answer * a;
  }
  return answer;
}
