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
    vector<int> v;
    rep(i, n) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> v1(n), v2(n);
    copy(v.begin(), v.end(), v1.begin());
    copy(v.begin(), v.end(), v2.begin());
    if (prev_permutation(v1.begin(), v1.end())) {
        rep(i, n - 1) {
            cout << v1[i] << " ";
        }
        cout << v1[n - 1] << endl;
    }

    rep(i, n - 1) {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
    if (next_permutation(v2.begin(), v2.end())) {
        rep(i, n - 1) {
            cout << v2[i] << " ";
        }
        cout << v2[n - 1] << endl;
    }

    return 0;
}
