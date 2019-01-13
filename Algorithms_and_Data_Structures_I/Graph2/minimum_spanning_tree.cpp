#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
#define MAX 10000
struct Edge {
  int cost;
  int u;
  int v;
};

int find(int u, int *parent)
{
  if (parent[u] == u) {
    return u;
  } else {
    return parent[u] = find(parent[u], parent);
  }
}

void merge(int u, int v, int *parent) {
  if (parent[u] < parent[v]) {
    if (v != parent[v]) merge(u, parent[parent[v]], parent);
    parent[v] = parent[u];
  } else {
    if (u != parent[u]) merge(v, parent[parent[u]], parent);
    parent[u] = parent[v];
  }
  return;
}
int main()
{
  int num_edge = 0;
  int n;
  cin >> n;
  int a[n][n];
  int parent[n];
  Edge edge[MAX];

  rep(i, n) parent[i] = i;

  rep(i, n) {
    rep(j, n) {
      cin >> a[i][j];
      if (a[i][j] != -1 and j >= i + 1) {
        edge[num_edge].cost = a[i][j];
        edge[num_edge].u = i;
        edge[num_edge++].v = j;
      }
    }
  }

  sort(edge, edge + num_edge, [](Edge a, Edge b){
                                  return a.cost < b.cost;
                                });
  int ans = 0;
  rep(i, num_edge) {
    if (find(edge[i].u, parent) != find(edge[i].v, parent)) {
      merge(edge[i].u, edge[i].v, parent);
      ans += edge[i].cost;
    }
  }
  cout << ans << endl;
  return 0;
}
