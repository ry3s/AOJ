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
#define mod 1000000007
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

    void unite(LL x, LL y, LL w) {
        w += weight(x);
        w += weight(y);

        x = find_root(x);
        y = find_root(y);

        if (x == y) return;

        parent[x] = y;
        diff_weight[x] = w;
    }
    LL diff(LL x, LL y) {
        if (find_root(x) != find_root(y)) return mod;
        return weight(x) - weight(y);
    }
private:
    // rootを求める
    LL find_root(LL x) {
        if (parent[x] == x) {
            return x;
        } else {
            LL r = find_root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    };
    LL weight(LL x) {
        find_root(x);
        return diff_weight[x];
    }
    void init(LL n) {
        rep(i, n) {
            parent.push_back(i);
            diff_weight.push_back(0);
        }
    };
private:
    vector<LL> parent; // 親の番号
    vector<LL> diff_weight;
};
int main() {


    int n, q;
    cin >> n >> q;
    UnionFindTree tree(n);
    rep(i, q) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            int z;
            cin >> z;
            tree.unite(x, y, z);
        } else if (cmd == 1) {
            if (tree.diff(x, y) == mod) {
                cout << "?" << endl;
            } else {
                cout << tree.diff(x, y) << endl;
            }

        }
    }
    return 0;
}
