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
#define INF 2147483647

struct Edge {
     int src, dst;
     int weight;
     Edge(int src_, int dist_, int weight_ ) :
          src(src_), dst(dist_), weight(weight_) {}
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<int> Array;
typedef vector<Array> Matrix;

void dijkstra(const Graph &graph, int start, vector<int> &distance, vector<int> &prev) {
    int n = graph.size();
    distance.assign(n, INF);
    distance[start] = 0;
    prev.assign(n, -1);

    priority_queue<Edge> qu; // e < f <=> e.weight > f.weight

    for (qu.push(Edge(-2, start, 0)); not qu.empty(); ) {
        Edge e = qu.top(); qu.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;

        for (const Edge &f : graph[e.dst]) {
            if (distance[f.dst] > e.weight + f.weight) {
                distance[f.dst] = e.weight + f.weight;
                qu.push(Edge(f.src, f.dst, e.weight + f.weight));
            }
        }
    }
}

int main() {

    Graph graph;
    int n;
    cin >> n;
    rep(i, n) {
        int id, k;
        cin >> id >> k;
        Edges edges;
        rep(j, k) {
            int v, c;
            cin >> v >> c;
            Edge tmp = Edge(id, v, c);
            edges.push_back(tmp);
        }
        graph.push_back(edges);
    }
    vector<int> distance, prev;
    dijkstra(graph, 0, distance, prev);

    rep(i, n) {
        cout << i << " " << distance[i] << endl;
    }
    return 0;
}
