#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

int main() {
  int n;
  cin >> n;
  double a, b;
  double d1 = 0.0, d2 = 0.0, d3 = 0.0, d_inf = 0.0;
  vector<double> x, y;

  rep(i, n) {
    cin >> a;
    x.push_back(a);
  }
  rep(i, n) {
    cin >> b;
    y.push_back(b);
  }
  rep(i, n) {
    d1 += abs(x[i] - y[i]);
    d2 += pow(abs(x[i] - y[i]), 2);
    d3 += pow(abs(x[i] - y[i]), 3);
    d_inf = max(d_inf, abs(x[i] - y[i]));
  }
  printf("%.8lf\n", d1);
  printf("%.8lf\n", sqrt(d2));
  printf("%.8lf\n", pow(d3, 1.0/3.0));
  printf("%.8lf\n", d_inf); 
  return 0;
}
