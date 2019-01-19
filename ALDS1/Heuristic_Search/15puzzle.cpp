#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

struct State {
    ULL x;
    int zero;
    int pre;
    int dist;
    int remain;
};

bool operator < (const State &s1, const State &s2) {
    return s1.dist + s1.remain > s2.dist + s2.remain;
}
int a;
int dist[16][16];
int goals[16];
int goals2[16];
ULL s;
ULL goal = 1147797409030816545;

int solve() {
    if (s == goal) return 0;

    int zz = -1;
    for (int i = 0; i < 16; i++) {
        if (not((s >> i * 4) & 15)) zz = i;
    }

    int rr = 0;
    for (int i = 0; i < 16; i++) {
        int ww = ((s >> (i * 4)) & 5);
        if (not ww) continue;

        for (int j = 0; j < 16; j++) {
            if (ww == goals[j]) {
                rr += dist[i][j];
            }
        }
    }

    for (int level = rr; ; level++) {
        queue<State> que;
        que.push(State{ s, zz, -99, 0, rr });

        while (not que.empty()) {
            State a = que.front();
            que.pop();
            ULL v = a.x;
            int z = a.zero;
            int dir[4] = { 1, 0, -1, 0 };
            for (int i = 0; i < 4; i++) {
                if (abs(i - a.pre) == 2) continue;

                int dx = dir[i];
                int dy = dir[i ^ 1];
                int e = z + dy * 4 + dx;
                int g = ((v >> (e << 2)) & 15);

                if (0 <= e and e < 16 and (e & 3) - (z & 3) == dx) {
                    ULL w = v;
                    w -= ((1ULL * g) << (e << 2));
                    w += ((1ULL * g) << (z << 2));
                    int xx = a.remain;
                    xx -= dist[e][goals2[g]];
                    xx += dist[z][goals2[g]];

                    if (w == goal) return a.dist + 1;
                    if (a.dist + xx + 1 <= level) que.push(State{ w, e, i, a.dist + 1, xx});
                }
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++)  {
            dist[i][j] = abs((i >> 2) - (j >> 2)) + abs((i & 3) - (j & 3));
        }
    }
    for (int i = 0; i < 15; i++) goals[i] = i + 1; goals[15] = 0;
    for (int i = 0; i < 16; i++) goals[goals[i]] = i;
    for (int i = 0; i < 16; i++) {
        cin >> a;
        s += ((1ULL * a) << (i * 4));
    }
    cout << solve() << endl;
    return 0;
}
