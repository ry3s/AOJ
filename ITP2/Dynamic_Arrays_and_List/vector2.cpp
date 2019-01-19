#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<vector<LL> > v(n);

    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int t;
            LL x;
            cin >> t >> x;
            v[t].push_back(x);
        } else if (cmd == 1) {
            int t;
            cin >> t;
            if (v[t].empty()) {
                cout << endl;
                continue;
            }
            rep(j, v[t].size()) {
                if (j == (long long)v[t].size() - 1) {
                    cout << v[t][j] << endl;
                } else {
                    cout << v[t][j] << " ";
                }
            }
        } else if (cmd == 2) {
            int t;
            cin >> t;
            v[t].clear();
        }
    }
    return 0;
}
