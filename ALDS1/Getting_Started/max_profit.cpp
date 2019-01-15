#include <iostream>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  long long r[n];
  rep(i, n) {
    cin >> r[i];
  }
  long long minv = r[0];
  long long maxv = r[1] - r[0];
  for (long long i = 1; i < n; i++) {
    maxv = max(maxv, r[i] - minv);
    minv = min(minv, r[i]);
  }

  cout << maxv << endl;
}
