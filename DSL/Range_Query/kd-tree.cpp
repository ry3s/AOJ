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

struct Point {
    LL x, y;
    int i;
};

bool comp_x(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
bool comp_y(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}
struct Node {
    Node *left, *right;
    Point p;

    Node(Node *left, Node *right, Point p) : left(left), right(right), p(p) {}
};

class kDTree {
private:
    LL n;

public:
    Node *root;
    vector<Point> p;
    kDTree(LL n_) : n(n_) {
        p = vector<Point>(n);
    }

    Node *make(LL l, LL r, LL depth) {
        if (not (l < r)) {
            return nullptr;
        }

        LL mid = (l + r) >> 1;
        if (depth % 2) {
            sort(p.begin() + 1, p.begin() + r, comp_x);
        } else {
            sort(p.begin() + 1, p.begin() + r, comp_y);
        }

        return new Node(make(l, mid, depth + 1)
                        , make(mid + 1, r, depth + 1)
                        , p[mid]);
    }

    void find(Node *node, vector<LL> &result, LL sx, LL tx, LL sy, LL ty, LL depth) {
        Point &p = node->p;

        if (sx <= p.x and p.x <= tx and sy <= p.y and p.y <= ty) {
            result.push_back(p.i);
        }

        if (depth % 2) {
            if (node->left != nullptr and sx <= p.x) {
                find(node->left, result, sx, tx, sy, ty, depth + 1);
            }

            if (node->right != nullptr and p.x <= tx) {
                find(node->right, result, sx, tx, sy, ty, depth + 1);
            }

        } else {
            if (node->left != nullptr and sy <= p.y) {
                find (node->left, result, sx, tx, sy, ty, depth + 1);
            }

            if (node->right != nullptr and p.y <= ty) {
                find(node->right, result, sx, tx, sy, ty, depth + 1);
            }
        }
    }

};
int main() {
    LL n;
    cin >> n;
    kDTree tree(n);

    rep(i, n) {
        cin >> tree.p[i].x >> tree.p[i].y;
        tree.p[i].i = i;
    }
    tree.root = tree.make(0, n, 0);

    int q;
    cin >> q;
    rep(i, q) {
        int sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        vector<LL> result;

        tree.find(tree.root, result, sx, tx, sy, ty, 0);
        sort(result.begin(), result.end());
        for(auto &x : result) {
            cout << x << endl;
        }
        cout << endl;
    }
    return 0;
}
