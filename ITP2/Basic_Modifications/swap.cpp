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
        int b, e, t;
        cin >> b >> e >> t;
        rep(i, e - b) {
            swap(v[b + i], v[t + i]);
        }
    }

    rep(i, n) {
        if (i + 1 == n) cout << v[i] << endl;
        else cout << v[i] << " ";
    }
    return 0;
}
