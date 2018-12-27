#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

// m >= n
long long int gcd(long long m, long long n) {
  int tmp;
  tmp = m % n;
  if (tmp == 0) return n;
  return gcd(n, tmp);
}
int main() {
  long long x, y;
  cin >> x >> y;
  cout << gcd(x, y) << endl;
  return 0;
}
