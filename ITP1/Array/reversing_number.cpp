#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, a;
  vector<int> v;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }

  reverse(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    if (i == (v.size() - 1)) cout << v[i];
    else  cout << v[i] << " ";
   
  }
  cout << endl;
  return 0;
}
    
