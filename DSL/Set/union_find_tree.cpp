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
class UnionFindTree {
public:
    UnionFindTree(LL n) {
        init(n);
    };

    bool is_same(LL x, LL y) {
        return find_root(x) == find_root(y);
    };

    void unite(LL x, LL y) {
        x = find_root(x);
        y = find_root(y);

        if (x == y) return;

        parent[x] = y;
    }
private:
    // rootを求める
    LL find_root(LL x) {
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = find_root(parent[x]);
        }
    };
    void init(LL n) {
        rep(i, n) {
            parent.push_back(i);
        }
    };
    vector<LL> parent; // 親の番号
};
int main() {


    int n, q;
    cin >> n >> q;
    UnionFindTree tree(n);
    rep(i, q) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            tree.unite(x, y);
        } else if (cmd == 1) {
            cout << tree.is_same(x, y) << endl;
        }
    }
    return 0;
}
