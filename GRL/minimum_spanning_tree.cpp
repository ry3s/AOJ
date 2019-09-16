#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

struct Edge {
    int from, to;
    LL weight;
    Edge (int from, int to, LL weight) : from(from), to(to), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
      e.from != f.from ? e.from < f.from : e.to < f.to;
}
using Edges = vector<Edge>;
using Graph = vector<Edges>;

const LL INF = (1LL << 60);

pair<LL, Edges> prim(const Graph &g) {
    int n = g.size();
    LL total = 0;
    Edges tree;
    vector<bool> visited(n, false);

    priority_queue<Edge> que;
    que.push(Edge(-1, 0, 0));
    while (not que.empty()) {
        Edge e = que.top(); que.pop();

        if (visited[e.to]) continue;
        tree.push_back(e);
        total += e.weight;
        visited[e.to] = true;

        for (auto f : g[e.to]) {
            if (not visited[f.to]) que.push(f);
        }
    }
    return pair<LL, Edges>(total, tree);
}
int main() {
    int v, e; cin >> v >> e;
    Graph graph(v);
    rep(i, e) {
        int s, t, w; cin >> s >> t >> w;
        graph[s].push_back(Edge(s, t, w));
        graph[t].push_back(Edge(t, s, w));
    }
    auto res = prim(graph);
    cout << res.first << endl;
    return 0;
}
