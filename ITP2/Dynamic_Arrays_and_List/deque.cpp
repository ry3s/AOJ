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
    rep(i, n) {
        string cmd;
        cin >> cmd;
        if (cmd == "0") {
            LL x;
            cin >> x;
            v.push_back(x);
        } else if (cmd == "1") {
            LL p;
            cin >> p;
            cout << v[p] << endl;
        } else {
            v.pop_back();
        }
    }
    return 0;
}
