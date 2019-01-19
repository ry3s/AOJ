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
    int n;
    LL q;
    cin >> n >> q;
    vector<stack<LL> > vs(n);
    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int t;
            LL x;
            cin >> t >> x;
            vs[t].push(x);
        } else if (cmd == 1) {
            int t;
            cin >> t;
            if (not vs[t].empty()) {
                cout << vs[t].top() << endl;
            }
        } else if (cmd == 2) {
            int t;
            cin >> t;
            if (not vs[t].empty()) {
                vs[t].pop();
            }
        }
    }
    return 0;
}
