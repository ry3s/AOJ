// 「プログラミングコンテスト攻略のためのアルゴリズムとデータ構造 」を参照した
#include <iostream>
#include <set>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

int N, K;
long long int T[100005];

int check(long long int P) {
  int i = 0;
  rep(j, K) {
    long long int s = 0;
    while (s + T[i] <= P) {
      s += T[i];
      i++;
      if (i == N) return N;
    }
  }
  return i;
}

int solve() {
  long long int l = 0, r = 100000 * 10000;
  long long int mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    int v = check(mid);
    if (v >= N) r = mid;
    else l = mid;
  }
  return r;
}
int main() {
  cin >> N >> K;
  rep(i, N) {
    cin >> T[i];
  }

  cout << solve() << endl;
  return 0;
}
