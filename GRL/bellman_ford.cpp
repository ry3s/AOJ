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

struct BellmanFord {
    struct Edge {
        int from, to; LL cost;
        Edge() {}
        Edge(int from, int to, LL cost): from(from), to(to), cost(cost) {}
    };
    const LL INF = (1LL << 60);
    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    vector<LL> dist;
    BellmanFord(int n): n(n), graph(n), used(n, 0), reach(n, 0), dist(n, INF) {}

    vector<Edge> edges;
    void add_edge(int from, int to, LL cost) {
        edges.push_back(Edge(from, to, cost));
        graph[from].push_back(to);
    }
    void build(int s, bool &neg_loop) {
        neg_loop = false;
        dist[s] = 0;
        rep(i, n) {
            for (auto e : edges) {
                if (dist[e.from] != INF and dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;

                    if (i == n - 1) {
                        neg_loop = true;
                        return;
                    }
                }
            }
        }
    }
};

int main() {
    int n_vertex, n_edge, r; cin >> n_vertex >> n_edge >> r;

    BellmanFord bf(n_vertex);
    rep(i, n_edge) {
        int s, t, d; cin >> s >> t >> d;
        bf.add_edge(s, t, d);
    }
    bool neg_loop;
    bf.build(r, neg_loop);
    if (neg_loop) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    } else {
        for (auto d : bf.dist) {
            if (d == bf.INF) cout << "INF" << endl;
            else cout << d << endl;
        }
    }
    return 0;

}
