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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

using Edges = vector<pair<int, int>>;
using Graph = vector<Edges>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const LL INF = (1LL << 60);
vector<LL> dijkstra(const Graph &g, int s) {
    int n = g.size();
    vector<LL> dist(n, INF);
    min_priority_queue<pair<LL, int>> que;

    que.push({0, s});
    dist[s] = 0;
    while(not que.empty()) {
        auto dv = que.top(); que.pop();
        LL d = dv.first;
        int v = dv.second;

        if (dist[v] < d) continue;
        for (auto e : g[v]) {
            if (dist[v] + e.second < dist[e.first]) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});
            }
        }
    }
    return dist;
}
int main() {
    int num_vertex, num_edge, r; cin >> num_vertex >> num_edge >> r;
    Graph graph(num_vertex);

    rep(i, num_edge) {
        int s, t, d; cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }
    auto dist = dijkstra(graph, r);
    for (auto d : dist) {
        if (d == INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}
