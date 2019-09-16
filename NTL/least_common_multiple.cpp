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
using LL = long long int;
using ULL = unsigned long long;

int gcd(int m, int n) {
    if (n > m) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}
int lcm(int m, int n) {
    return m * n / gcd(m, n);
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ans = a[0];
    rep(i, n - 1) {
        ans = lcm(ans, a[i + 1]);
    }
    cout << ans << endl;
}
