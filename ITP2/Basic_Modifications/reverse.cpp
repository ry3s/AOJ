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
        int b, e;
        cin >> b >> e;
        reverse(v.begin() + b, v.begin() + e);
    }
    rep(i, v.size()) {
        if (i == (LL)v.size() - 1) {
            cout << v[i] << endl;
        } else {
            cout << v[i] << " ";
        }
    }
}
