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
void dump(const list<LL> &list) {
	bool is_not_first = false;
	for (const auto &l : list) {
		if (is_not_first) cout << ' ';
		cout << l;
		is_not_first = true;
	}
	cout << endl;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    LL q;
    cin >> n >> q;
    vector<list<LL> > vl(n);
    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int t;
            LL x;
            cin >> t >> x;
            vl[t].push_back(x);
        } else if (cmd == 1) {
            int t;
            cin >> t;
            dump(vl[t]);
        } else if (cmd == 2) {
            int s, t;
            cin >> s >> t;
            vl[t].splice(vl[t].end(), move(vl[s]));
            vl[s] = list<LL>();
        }
    }

    return 0;
}
