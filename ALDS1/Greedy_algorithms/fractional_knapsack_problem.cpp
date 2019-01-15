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
    LL n, w;
    cin >> n >> w;
    LL value, weight;
    vector<pair<double, LL> > p;
    rep(i, n) {
        cin >> value >> weight;
        p.push_back(make_pair((double)value/ weight, weight));
    }
    sort(p.begin(), p.end(), greater<pair<double, LL> >());

    double max_value = 0.;
    for (const pair<double, LL> &x : p) {
        if (w <= 0) break;
        int tmp = min(x.second, w);
        max_value += x.first * tmp;
        w -= tmp;
    }
    printf("%.8lf\n", max_value);
    return 0;
}
