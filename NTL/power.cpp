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
const LL MOD = 1e9+7;

LL power(LL a, LL n) {
    LL ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret *  a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}
int main() {
    LL m, n; cin >> m >> n;
    cout << power(m, n) << endl;
    return 0;
}
