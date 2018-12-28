#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
int cnt;
void insertion_sort(int* a, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 and a[j] > v) {
      a[j + g] = a[j];
        j = j - g;
        cnt++;
    }
    a[j + g] = v;
  }
}
void shell_sort(int* a, int n) {
  cnt = 0;
  int r = 1;
  vector<int> g;
  while (r <= n) {
    g.push_back(r);
    r *= 2;
  }
  int m = g.size();
  reverse(g.begin(), g.end());
  
  cout << m << endl;
  rep(i, m) {
    cout << g[i] << " \n"[i == m-1];
  }
  
  rep(i, m) {
    insertion_sort(a, n, g[i]);
  }
  cout << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) {
    cin >> a[i];
  }
  shell_sort(a, n);
  rep(i, n) {
    cout << a[i] << endl;
  }
  return 0;
}
