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
            int x;
            cin >> x;
            flag.set(x, true);
        } else if (cmd == 2) {
            int x;
            cin >> x;
            flag.reset(x);
        } else if (cmd == 3) {
            int x;
            cin >> x;
            flag.flip(x);
        } else if (cmd == 4) {
            cout << flag.all() << endl;
        } else if (cmd == 5) {
            cout << flag.any() << endl;
        } else if (cmd == 6) {
            cout << flag.none() << endl;
        } else if (cmd == 7) {
            cout << flag.count() << endl;
        } else if (cmd == 8) {
            cout << flag.to_ullong() << endl;
        }
    }
    return 0;
}
