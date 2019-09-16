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

LL euler_phi(LL n) {
    LL ret = n;
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}
int main() {
    LL n; cin >> n;
    cout << euler_phi(n) << endl;
}
