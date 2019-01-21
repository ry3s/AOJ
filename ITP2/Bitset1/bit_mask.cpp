#include <cstdio>
#include <climits>
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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
int main() {
    bitset<64> flag(0);

    int n;
    cin >> n;
    vector<bitset<64> > masks(n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int x;
            cin >> x;
            masks[i].set(x, true);
        }
    }

    int q;
    cin >> q;
    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int x;
            cin >> x;
            cout << flag.test(x) << endl;
        } else if (cmd == 1) {
            int m;
            cin >> m;
            flag = flag | masks[m];
        } else if (cmd == 2) {
            int m;
            cin >> m;
            flag = flag & ~(masks[m]);
        } else if (cmd == 3) {
            int m;
            cin >> m;
            flag = flag ^ masks[m];
        } else if (cmd == 4) {
            int m;
            cin >> m;
            bitset<64> tmp = masks[m] & flag;
            cout << (tmp == masks[m]) << endl;
        } else if (cmd == 5) {
            int m;
            cin >> m;
            bitset<64> tmp = masks[m] & flag;
            cout << tmp.any() << endl;
        } else if (cmd == 6) {
            int m;
            cin >> m;
            bitset<64> tmp = masks[m] & flag;
            cout << tmp.none() << endl;
        } else if (cmd == 7) {
            int m;
            cin >> m;
            bitset<64> tmp = masks[m] & flag;
            cout << tmp.count() << endl;
        } else if (cmd == 8) {
            int m;
            cin >> m;
            bitset<64> tmp = masks[m] & flag;
            cout << tmp.to_ullong() << endl;
        }
    }
    return 0;
}
