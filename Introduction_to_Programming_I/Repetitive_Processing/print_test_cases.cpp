#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
  int x;
  vector<int> v;

  while (1) {
    cin >> x;
    if (x == 0) break;
    v.push_back(x);
  }

  for (int i = 0; i < v.size(); i++) {
    printf("Case %d: %d\n", i+1, v[i]);
  }

  return 0;

}
    
