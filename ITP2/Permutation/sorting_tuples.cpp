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
struct Goods {
    LL value;
    LL weight;
    string type;
    LL date;
    string name;
};
bool operator <(const Goods &a, const Goods &b) {
    if (a.value != b.value) return a.value < b.value;
    else if (a.weight != b.weight) return a.weight < b.weight;
    else if (a.type != b.type) return a.type < b.type;
    else if (a.date != b.date) return a.date < b.date;
    return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    vector<Goods> vec(n);
    rep(i, n) {
        LL v, w, d;
        string t, s;
        cin >> v >> w >> t >> d >> s;
        Goods tmp;
        tmp.value = v;
        tmp.weight = w;
        tmp.type = t;
        tmp.date = d;
        tmp.name = s;
        vec[i] = tmp;
    }
    sort(vec.begin(), vec.end());

    for (auto &tmp : vec) {
        cout << tmp.value << " ";
        cout << tmp.weight << " ";
        cout << tmp.type << " ";
        cout << tmp.date << " ";
        cout << tmp.name << endl;

    }
    return 0;
}
