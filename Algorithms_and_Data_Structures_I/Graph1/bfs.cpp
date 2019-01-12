#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int main()
{
  int k, t, m, x, cnt, dist[200];
  vector<int> v[200];
  bool visited[200];
  queue<int> q;

  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> t >> m;
    for (int j = 1; j <= m; j++) {
      cin >> x;
      v[t].push_back(x);
    }
  }
  q.push(1);

  while (not q.empty()) {
    int from = q.front();
    visited[from] = true;
    q.pop();

    rep(i, v[from].size()) {
      int to = v[from][i];
      if (not visited[to]) {
        visited[to] = true;
        dist[to] = dist[from] + 1;
        q.push(to);
      }
    }
  }


  for (int i = 1; i <= k; i++) {
    if (not visited[i]) cout << i << " " << -1 << endl;
    else cout << i << " " << dist[i] << endl;
  }
  return 0;
}
