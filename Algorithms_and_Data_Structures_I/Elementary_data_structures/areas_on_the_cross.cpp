#include <iostream>
#include <stack>
#include <vector>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

int main() {
  stack<int> s;
  stack<pair<int, int> > ss;
  char ch;
  int i = 1;
  int ans = 0;
  while (cin >> ch) {
    if (ch == '\\'){
      s.push(i);
    } else if (ch == '/' and s.size()) {
      int tmp = s.top();
      s.pop();
      int res = i - tmp;
      ans += res;
      while (ss.size() and ss.top().first > tmp) {
        res += ss.top().second;
        ss.pop();
      }
      ss.push(make_pair(tmp, res));
    }
    i++;
  }

  cout << ans << endl;
  vector<int> v;
  while (ss.size()) {
    v.push_back(ss.top().second);
    ss.pop();
  }
  cout << v.size();
  for (auto z = v.rbegin(); z != v.rend(); z++) {
    cout << " " << *z;
  }
  cout << endl;
          
  return 0;
}
