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
// rolling hash
#define MOD 1000000007LL
const LL CoprimeNum1 = 401;
const LL CoprimeNum2 = 397;

int h, w, r, c;
vector<vector<LL> > gen_hash(const vector<string> v, int xs, int ys) {
    vector<vector<LL> > h1(xs, vector<LL>(ys, 0));
    vector<vector<LL> > h2(xs, vector<LL>(ys, 0));
    LL cn1 = 1;
    LL cn2 = 1;
    rep(i, c) cn1 = (cn1 * CoprimeNum1) % MOD;
    rep(i, r) cn2 = (cn2 * CoprimeNum2) % MOD;

    rep(i, xs) {
        LL B = 0;
        rep(j, c) B = (B * CoprimeNum1 +  v[i][j]) % MOD;
        rep(j, ys - c + 1) {
            h1[i][j] = B;
            if (j + c < ys) {
                B = (B * CoprimeNum1 - v[i][j] * cn1 + v[i][j + c]) % MOD;
            }
            B = (B < 0) ? B + MOD : B;
        }
    }
    rep(j, ys) {
        LL B = 0;
        rep(i, r) B = (B * CoprimeNum2 + h1[i][j]) % MOD;
        rep(i, xs - r + 1) {
            h2[i][j] = B;
            if (i + r < xs) {
                B = (B * CoprimeNum2 - h1[i][j] * cn2 + h1[i+r][j]) % MOD;
            }
            B = (B < 0) ? B + MOD : B;
        }
    }
    return h2;
}
int main() {

    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    cin >> r >> c;
    vector<string> b(r);
    rep(i, r) cin >> b[i];

    if (h < r or w < c) return 0;

    auto f = gen_hash(a, h, w);
    auto p = gen_hash(b, r, c);

    rep(i, h - r + 1) {
        rep(j, w - c + 1) {
            if (f[i][j] == p[0][0]) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
