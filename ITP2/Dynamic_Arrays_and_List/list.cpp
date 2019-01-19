#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    list<LL> lst;
    list<LL>::iterator itr = lst.end();
    rep(i, n) {
        int q;
        cin >> q;

        if (q == 0) {
            LL x;
            cin >> x;
            itr = lst.insert(itr, x);
        } else if (q == 1) {
            int b;
            cin >> b;
            if (b > 0) {
                rep(i,b) itr++;
            } else {
                rep(i,-b) itr--;
            }
        } else if (q == 2) {
            itr = lst.erase(itr);
        }
    }
    for (const auto &x : lst) {
        cout << x << endl;
    }
    return 0;
}
