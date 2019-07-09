#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
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
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long ULL;

void solve() {
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int> > dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    int n = s.length();
    int m = t.length();

    rep(i, n) {
        rep(j, m) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;;

}
int main() {
    int n;
    cin >> n;
    rep(i, n) {
        solve();
    }
}
