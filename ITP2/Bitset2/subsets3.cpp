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
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;

    int k;
    int T = 0;
    cin >> k;
    rep(i, k) {
        int b;
        cin >> b;
        T |= (1 << b);
    }
    for (int sub = 0; ; sub = (sub - T) & T) {
        cout << sub << ":";
        rep(i, n) {
            if ((sub >> i) & 1) cout << " " << i;
        }
        cout << endl;

        if (sub == T) break;
    }
    return 0;
}
