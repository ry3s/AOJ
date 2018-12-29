#include <iostream>
#include <utility>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

LL partition(LL* a, LL p, LL r) {
  LL x = a[r];
  LL i = p - 1;
  for (LL j = p; j < r; j++) {
    if (a[j] <= x) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i+1], a[r]);
  return i + 1;
}

int main() {
  LL n;
  cin >> n;
  LL a[n];
  rep(i, n) {
    cin >> a[i];
  }
  LL q = partition(a, 0, n-1);

  rep(i, n-1) {
    if (i == n - 1) cout << a[i] << endl;
    else if (i == q) cout << "[" << a[i] << "] ";
    else cout << a[i] << " ";
  }
  if (q == n - 1) cout << "[" << a[n-1] << "]" << endl;
  else cout << a[n-1] << endl;
  return 0;
}
