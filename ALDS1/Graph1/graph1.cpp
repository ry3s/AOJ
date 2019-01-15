#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;


int main () {
  int n;
  cin >> n;
  int a[n][n];
  rep(i, n) {
    rep(j, n) {
      a[i][j] = 0;
    }
  }

  rep(i, n) {
    int u;
    int degree;
    cin >> u;
    cin >> degree;
    rep(j, degree) {
      int v;
      cin >> v;
      a[u - 1][v - 1] = 1;
    }
  }

  rep(i, n) {
    rep(j, n) {
      if (j) cout << " ";
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
