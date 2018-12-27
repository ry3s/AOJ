#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

void insertion_sort(int* a, int n) {
  rep (i, n) {
    if (i == n - 1) {
      cout << a[i] << endl;
    } else {
      cout << a[i] << " ";
    }
  }
  for (int i = 1; i < n; i++) {
    int j;
    int v = a[i];
    j = i - 1;
    while (j >= 0 and a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    rep (i, n) {
      if (i == n - 1) {
        cout << a[i] << endl;
      } else {
        cout << a[i] << " ";
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  int array[n];
  rep(i, n) {
    cin >> array[i];
  }
  insertion_sort(array, n);
  return 0;
}
