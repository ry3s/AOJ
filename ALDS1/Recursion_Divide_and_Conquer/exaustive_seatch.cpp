#include <iostream>
#include <vector>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
typedef long long int LL;
using namespace std;
// i番目の要素を使うか使わないかで分岐・再帰
int n, w[20];
bool solve(int m, int now, int d) {
  if (now == m) return true;
  else if (now > m or d >= n) return false;
  else return solve(m, now + w[d], d + 1) or solve(m, now, d + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int m, q;
  cin >> n;
  rep(i, n) {
    cin >> w[i];
  }
  cin >> q;
  rep(i, q) {
    cin >> m;
    if (solve(m, 0, 0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
