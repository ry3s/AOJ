#include <iostream>
#include <utility>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
typedef long long int LL;
using namespace std;

void kock(int n, pair<double, double> p1, pair<double,double> p2) {
  if (n == 0) return;
  pair<double, double> s, t, u;
  double x, y;
  x = (2.0 * p1.first + p2.first) / 3.0;
  y = (2.0 * p1.second + p2.second) / 3.0;
  s = make_pair(x, y);

  x = (p1.first + 2.0 * p2.first) / 3.0;
  y = (p1.second + 2.0 * p2.second) / 3.0;
  t = make_pair(x, y);

  x = (t.first - s.first) * cos(60 * M_PI / 180)
    - (t.second - s.second) * sin(60 * M_PI / 180)
    + s.first;
  y = (t.first - s.first) * sin(60 * M_PI / 180)
    + (t.second - s.second) * cos(60 * M_PI / 180)
    + s.second;
  u = make_pair(x, y);

  kock(n-1, p1, s);
  printf("%.8lf %.8lf\n", s.first, s.second);
  kock(n-1, s, u);
  printf("%.8lf %.8lf\n", u.first, u.second);
  kock(n-1, u, t);
  printf("%.8lf %.8lf\n", t.first, t.second);
  kock(n-1, t, p2);

}
int main() {
  int n;
  cin >> n;
  printf("%.8lf %.8lf\n", 0.0, 0.0);
  kock(n, make_pair(0, 0), make_pair(100, 0));
  printf("%.8lf %.8lf\n", 100.0, 0.0);

  return 0;
}
