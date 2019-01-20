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

    int q;
    cin >> q;
    rep(i, q) {
        LL k;
        cin >> k;
        auto lr = lower_bound(a.begin(), a.end(), k);
        auto ur = upper_bound(a.begin(), a.end(), k);
        cout << distance(a.begin(), lr) <<  " " << distance(a.begin(), ur) << endl;
    }
}
