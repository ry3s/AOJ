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
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    multiset<LL> a;
    rep(i, n) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            LL x;
            cin >> x;
            a.insert(x);
            cout << a.size() << endl;
        } else if (cmd == 1) {
            LL k;
            cin >> k;
            auto p = a.equal_range(k);
            cout << distance(p.first, p.second) << endl;
        } else if (cmd == 2) {
            LL k;
            cin >> k;
            a.erase(k);
        } else if (cmd == 3) {
            int l, r;
            cin >> l >> r;
            for (auto itr = a.lower_bound(l); itr != a.upper_bound(r);itr++) {
                cout << *itr << endl;
            }
        }

    }

    return 0;
}
