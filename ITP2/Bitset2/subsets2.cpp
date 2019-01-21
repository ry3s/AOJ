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
    int T = 0;
    int k;
    cin >> k;
    rep(i, k) {
        int b;
        cin >> b;
        T |= (1 << b);
    }
    for (int i= T; i < (1 << n); i = (i + 1) | T) {
        cout << i << ":";
        rep(j, n) {

            if ((i >> j) & 1) cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}
