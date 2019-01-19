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
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<LL> b(m);
    rep(i, m) {
        cin >> b[i];
    }

    if (n < m) {
        cout << 0 << endl;
        return 0;
    }
    bool ans = true;
    rep(i, m) {
        ans = ans and binary_search(a.begin(), a.end(), b[i]);
    }
    cout << ans << endl;
    return 0;
}
