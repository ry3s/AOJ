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

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n + 1) {
        dp[i][0] = i;
    }
    rep(j, m + 1) {
        dp[0][j] = j;
    }
    rep(i, n) rep(j, m){
        if (s1[i] == s2[j]) {
            dp[i + 1][j + 1] = dp[i][j];
        } else {
            dp[i + 1][j + 1] = min({dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1});
        }
    }
    cout << dp[n][m] << endl;

}
