#include <iostream>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int selection_sort(int* a, int n) {
  int cnt = 0;
  rep(i, n) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(a[i], a[minj]);
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) {
    cin >> a[i];
  }
  int cnt = selection_sort(a, n);

  rep(i, n) {
    if (i == n - 1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << cnt << endl;
  return 0;
}
