#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main() {

  while (1) {
    int n;
    double a, m, s;
    cin >> n;
    vector<int> v;
    if ( n == 0 ) break;
    
    rep(i, n) {
      cin >> a;
      v.push_back(a);
    }
    m = 0;
    rep(i, v.size()) {
      m += v[i];
    }
    m /= n;
    s = 0;
    rep(i, v.size()) {
      s += pow(v[i] - m, 2);
    }
    s /= n;
    
    printf("%.8lf\n", sqrt(s));
  }
  
  return 0;
}
