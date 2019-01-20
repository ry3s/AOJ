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

    vector<LL> ans;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
    rep(i, ans.size()){
        cout << ans[i] << endl;
    }
}
