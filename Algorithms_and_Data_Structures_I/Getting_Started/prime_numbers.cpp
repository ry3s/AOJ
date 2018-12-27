#include <iostream>
#include <cmath>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

bool is_prime(long long int n) {
  if (n == 2) return true;

  if (n < 2 or n % 2 == 0) return false;

  int i = 3;
  while (i <= sqrt(n) ) {
    if (n % i == 0) return false;

    i += 2;
    
  }
  return true;
}
int main() {
  int n, x, cnt = 0;
  cin >> n;
  rep(i, n) {
    cin >> x;
    if (is_prime(x)) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
