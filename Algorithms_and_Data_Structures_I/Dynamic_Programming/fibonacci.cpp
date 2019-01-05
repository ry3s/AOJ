#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int memo[100] = {0};

int fib(int n) {
  if (n == 0) return 1;
  else if (n == 1) return 1;
  else if (memo[n] != 0) return memo[n];
  else return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
