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
const LL INF = (1LL << 60);

bool warshall_floyd(vector<vector<LL>> &dist, int n) {
    rep(k, n) rep(i, n) if (dist[i][k] != INF) {
        rep(j, n) if (dist[k][j] != INF) {
            dist[i][j]= min(dist[i][j] , dist[i][k] + dist[k][j]);
            if (j == k and dist[j][k] < 0) return false;
        }
    }
    return true;
}
int main() {
    int n_vertex, n_edge; cin >> n_vertex >> n_edge;
    vector<vector<LL>> dist(n_vertex, vector<LL>(n_vertex, INF));

    rep(i, n_vertex) rep(j, n_vertex) if (i == j) dist[i][j] = 0;

    rep(i, n_edge) {
        int s, t; LL d; cin >> s >> t >> d;
        dist[s][t] = d;
    }
    if (not warshall_floyd(dist, n_vertex)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, n_vertex) {
            rep(j, n_vertex) {
                if (j == n_vertex - 1) {
                    if (dist[i][j] == INF) cout << "INF" << endl;
                    else cout << dist[i][j] << endl;
                } else {
                    if (dist[i][j] == INF) cout << "INF" << " ";
                    else cout << dist[i][j] << " ";
                }
            }
        }
    }
    return 0;
}
