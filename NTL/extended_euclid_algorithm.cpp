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

LL extgcd(LL a, LL b, LL &x, LL &y) {
    // if (a < b) return extgcd(b, a, x, y);
    if (b != 0) {
        LL g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return g;
    } else {
        x = 1; y = 0;
        return a;
    }

}
int main() {
    LL a, b; cin >> a >> b;
    LL x, y;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}
