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

int next_combination(int sub) {
    int x = sub & -sub;
    int y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {

    int n, k;
    cin >> n >> k;

    int bit = (1 << k) - 1;
    for (; bit < (1 << n); bit = next_combination(bit)) {
        cout << bit << ":";
        rep(i, n) {
            if (bit >> i & 1) cout << " " << i;
        }
        cout << endl;
    }

    return 0;
}
