#include <cstdio>
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
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<pair<LL, LL> > vp;
    rep(i, n) {
        LL s, t;
        cin >> s >> t;
        vp.push_back(make_pair(t, s));
    }
    sort(vp.begin(), vp.end());
    LL ans = 0;
    LL tmp = -1;

    rep(i, n) {
        if (vp[i].second <= tmp) continue;
        tmp = vp[i].first;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
