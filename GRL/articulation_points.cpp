#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

struct ArticulationPoint {
    vector<int> prenum, parent, lowest;
    vector<vector<int>> graph;
    vector<bool> visited;
    int timer;
    ArticulationPoint(int n) {
        prenum.assign(n, 0);
        parent.assign(n, 0);
        lowest.assign(n, 0);
        visited.assign(n, false);
        graph.assign(n, vector<int>());
    }

    void add_edge(int from, int to) {
        graph[from].push_back(to);
    }

    void dfs(int cur, int pre) {
        prenum[cur] = lowest[cur] = timer;
        ++timer;
        visited[cur] = true;
        for (const auto &e: graph[cur]) {
            if (not visited[e]) {
                parent[e] = cur;
                dfs(e, cur);
                lowest[cur] = min(lowest[cur], lowest[e]);
            } else if (e != pre) {
                lowest[cur] = min(lowest[cur], prenum[e]);
            }
        }
    }

    set<int> get_articulation_point() {
        timer = -1;
        dfs(0, -1);

        set<int> ap;

        int np = 0;
        for (int i = 1; i < static_cast<int>(graph.size()); i++) {
            int par = parent[i];
            if (par == 0) ++np;
            else if (prenum[par] <= lowest[i]) ap.insert(par);
        }

        if (np > 1) ap.insert(0);
        return ap;
    }
};
int main() {
    int n, m; cin >> n >> m;
    ArticulationPoint ap(n);
    rep(i, m) {
        int s, t; cin >> s >> t;
        ap.add_edge(s, t);
        ap.add_edge(t, s);
    }
    for (auto it: ap.get_articulation_point()) {
        cout << it << endl;
    }
}
