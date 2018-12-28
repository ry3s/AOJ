#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

int main() {
  int tmp, cnt = 0;
  long long n, q;
  vector<int> vs, vt;
  cin >> n;
  rep(i, n) {
    cin >> tmp;
    vs.push_back(tmp);
  }
  cin >> q;
  rep(i, q) {
    cin >> tmp;
    vt.push_back(tmp);
  }
  
  sort(vs.begin(), vs.end());
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  
  rep(i, q) {
    rep(j, vs.size()) {
      if (vt[i] == vs[j]) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
