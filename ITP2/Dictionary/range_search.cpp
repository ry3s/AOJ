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
    map<string, LL> mp;

    rep(i, n) {
        int cmd;
        cin >> cmd;

        string key;
        LL x;
        string l, r;
        auto itr = mp.end();
        switch (cmd) {
        case 0:
            cin >> key >> x;
            mp[key] = x;
            break;
        case 1:
            cin >> key;
            itr = mp.find(key);
            if (itr != mp.end()) {
                cout << (*itr).second << endl;
            } else {
                cout << 0 << endl;
            }

            break;
        case 2:
            cin >> key;
            mp.erase(key);
            break;
        case 3:
            cin >> l >> r;
            for (auto it = mp.lower_bound(l); it != mp.upper_bound(r); it++ ) {
                cout << (*it).first << " " <<  (*it).second << endl;
            }
            break;
        }
    }
    return 0;
}
