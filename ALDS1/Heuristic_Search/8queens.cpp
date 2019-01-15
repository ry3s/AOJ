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
vector<vector<bool> > board;
// backtracking
// http://www.cc.kyoto-su.ac.jp/~yamada/ap/backtrack.html
void print_board(int n) {
    rep(i, n) {
        rep(j, n) {
            if (board[i][j]) cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }
}

bool check(int y, int x, int n) {
    // 横
    rep(c, n) {
        if (c != x and board[y][c] == true) return false;
    }
    // 縦
    rep(r, n) {
        if (r != y and board[r][x] == true) return false;
    }
    // 右上
    int r = y - 1;
    int c = x + 1;
    while (r >= 0 and c < n) {
        if (board[r--][c++]) return false;
    }
    // 左上
    r = y - 1;
    c = x - 1;
    while (r >= 0 and c >= 0) {
        if (board[r--][c--]) return false;
    }
    // 左下
    r = y + 1;
    c = x - 1;
    while (r < n and c >= 0) {
        if (board[r++][c--]) return false;
    }
    // 右下
    r = y + 1;
    c = x + 1;
    while (r < n and c < n) {
        if (board[r++][c++]) return false;
    }
    return true;
}
bool solve(int n, int d) {


    if (d == n) {
        print_board(n);
        return true;
    } else {
        rep(i, n) {
            if (board[d][i]) {
                if (not solve(n, d + 1)) return false;
            }
        }
        rep(i, n) {
            if (board[d][i] == false and check(d, i, n)) {
                board[d][i] = true;
                if (not solve(n, d + 1)) {
                    board[d][i] = false;
                }
            }
        }
    }

    return false;
}
int main() {
    board = vector<vector<bool> >(8, vector<bool>(8, false));

    int k;
    cin >> k;
    rep(i, k) {
        int r, c;
        cin >> r >> c;
        board[r][c] = true;
    }
    solve(8, 0);
    return 0;
}
