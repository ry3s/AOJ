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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> c(m);
    rep(i, m) {
        cin >> c[i];
    }
    LL res_num = 1e9;
    rep(bit, (1 << m)) {
        LL sum = 0;
        LL num = 0;
        rep(i, m) if (bit & (1 << i)) {
            sum += c[i];
            num++;
        }
        if (sum == n) res_num = min(res_num, num);
    }
    cout << res_num << endl;
}
