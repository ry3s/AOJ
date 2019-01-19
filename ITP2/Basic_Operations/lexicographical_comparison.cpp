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
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<int> va;
    rep(i, n) {
        int x;
        cin >> x;
        va.push_back(x);
    }

    int m;
    cin >> m;
    vector<int> vb;
    rep(i, m) {
        int x;
        cin >> x;
        vb.push_back(x);
    }
    int i;
    for (i= 0; i < (n > m ? m : n); i++) {
        if (va[i] > vb[i]) {
            cout << 0 << endl;
            return 0;
        } else if (va[i] < vb[i]){
            cout << 1 << endl;
            return 0;
        }
    }
    if (i > (int)vb.size() - 1) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}
