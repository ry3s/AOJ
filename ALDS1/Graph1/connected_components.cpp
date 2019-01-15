#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
/*
https:algorithmbeginner.blogspot.com/2018/02/alds111dconnected-componentsc.html
上の記事を参考にして実装した
*/
#define MAX 1000000
#define NIL -1
vector<int> g_graph[MAX];
int color[MAX];

void dfs(int r, int c)
{
  stack<int> s;
  s.push(r); // stackに自身を入れる
  color[r] = c; // colorに自分のidを入れる

  while (not s.empty()) {
    int u = s.top();
    s.pop();

    rep(i, g_graph[u].size()) {
      int v = g_graph[u][i];
      if (color[v] == NIL) {
        color[v] = c;
        s.push(v);
      }

    }
  }
}

// 色を振り分けることで，同じグループに属するかどうかを判定
void assign_color(int number)
{
  int id = 1;
  rep(i, number) {
    color[i] = NIL;
  }
  rep(i, number) {
    if (color[i] == NIL) dfs(i, id++);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int s, t;
    cin >> s >> t;
    g_graph[s].push_back(t);
    g_graph[t].push_back(s);
  }

  assign_color(n);

  int q;
  cin >> q;
  rep(i, q) {
    int s, t;
    cin >> s >> t;
    if (color[s] == color[t]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
