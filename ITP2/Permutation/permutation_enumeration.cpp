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
        v.push_back(i + 1);
    }
    do {
        rep(i, n - 1) {
            cout << v[i] << " ";
        }
        cout << v[n - 1] << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
