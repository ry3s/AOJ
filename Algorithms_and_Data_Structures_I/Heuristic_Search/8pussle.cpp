#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Puzzle{
    int field[9];
    int space;
    int turn;

    bool operator < (const Puzzle &a) const {
        rep(i, 9) {
            if (a.field[i] == field[i]) continue;
            return field[i] > a.field[i];
        }
        return false;
    }
};

bool check(Puzzle p) {
    rep(i, 9) {
        if (p.field[i] != i + 1) return false;
    }
    return true;
}
int solve(Puzzle in) {
    queue<Puzzle> q;
    map<Puzzle, bool> mp;

    q.push(in);
    mp[in] = true;

    // bfs
    while (not q.empty()) {
        Puzzle p = q.front();
        q.pop();
        if (check(p)) return p.turn;

        int x = p.space % 3;
        int y = p.space / 3;
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or 2 < nx or ny < 0 or 2 < ny) continue;

            Puzzle tmp = p;
            swap(tmp.field[p.space], tmp.field[3 * ny + nx]);
            tmp.space = 3 * ny + nx;
            if (mp[tmp] == false) {
                mp[tmp] = true;
                tmp.turn++;
                q.push(tmp);
            }
        }

    }
    return -1;
}
int main() {
    Puzzle in;

    rep(i, 9) {
        cin >> in.field[i];
        if (in.field[i] == 0) {
            in.field[i] = 9;
            in.space = i;
        }
    }
    in.turn = 0;
    cout << solve(in) << endl;
    return 0;
}
