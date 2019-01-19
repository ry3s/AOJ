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
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<LL> v;
    rep(i, n) {
        LL x;
        cin >> x;
        v.push_back(x);
    }

    int q;
    cin >> q;
    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int b, e;
            cin >> b >> e;
            LL mini = LLONG_MAX;
            for (int j = b; j < e; j++) {
                mini = min(v[j], mini);
            }
            cout << mini << endl;
        } else if (cmd == 1) {
            int b, e;
            cin >> b >> e;
            LL maxi = LLONG_MIN;
            for (int j = b; j < e; j++) {
                maxi = max(v[j], maxi);
            }
            cout << maxi << endl;
        }
    }
    return 0;
}
