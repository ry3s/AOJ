#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<LL> v;
    v.push_back(0);
    rep(i, n) {
        LL x;
        cin >> x;
        v.push_back(x);
    }
    for(int i = 1; i <=n; i++) {
        LL parent = i / 2;
        LL left = 2 * i;
        LL right = 2 * i + 1;
        cout << "node " << i << ": key = " << v[i] << ", ";
        if (parent != 0) {
            cout << "parent key = " << v[parent] << ", ";
        }
        if (left < (LL)v.size()) {
            cout << "left key = " << v[left] << ", ";
        }
        if (right < (LL)v.size()) {
            cout << "right key = " << v[right] << ", ";
        }
        cout << endl;
    }
    return 0;
}
