#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  printf("%d %d %f\n", a / b, a % b, (a + 0.0) / b);
  return 0;
}
