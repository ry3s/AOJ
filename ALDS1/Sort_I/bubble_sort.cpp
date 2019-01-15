#include <iostream>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int bubble_sort(int* a, int n) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        count++;
        swap(a[i], a[i - 1]);
        flag = true;
      }
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) {
    cin >> a[i];
  }
  int count =  bubble_sort(a, n);
  rep(i, n) {
    if (i == n - 1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << count << endl;
  return 0;
}
