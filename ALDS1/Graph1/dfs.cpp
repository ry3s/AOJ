#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
int a[101][101];
bool visited[101];
int d[101];
int f[101];
int n;
int t = 0;

void dfs(int v) {
  if (visited[v]) return;
  t++;
  visited[v] = true;
  d[v] = t;

  rep(i, n) {
    if (a[v][i] == 1 and not visited[i])
      dfs(i);
  }
  t++;
  f[v] = t;
}
int main() {
  cin >> n;

  rep(i, n) {
    rep(j, n) {
      a[i][j] = 0;
    }
  }

  rep(i, n) {
    int u;
    int k;
    cin >> u >> k;
    rep(j, k) {
      int v;
      cin >> v;
      a[u - 1][v - 1] = 1;
    }
  }
  rep(i, n) {
    dfs(i);
  }
  rep(i, n) {
    cout << i+1 << " " <<  d[i] << " " << f[i] << endl;
  }

  return 0;
}
/*function 深さ優先探索(v)
 *   v に訪問済みの印を付ける
 *   v を処理する
 *   for each v に接続している頂点 i do
 *      if i が未訪問 then
 *          深さ優先探索(i)
 */
