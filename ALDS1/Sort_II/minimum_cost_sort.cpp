#include <iostream>
#include <map>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

// http://mayokoex.hatenablog.com/entry/2015/12/28/173348
const int MAXN = 1010;
int w[MAXN];
bool done[MAXN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, mini = 100000;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        cin >> w[i];
        mp[w[i]] = 0;
        mini = min(mini, w[i]);
    }
    {
        int k = 0;
        for (auto &p : mp) p.second = k++;
    }

    int ans = 0;
    rep(i, n) {
        if (done[i]) continue;

        int cnt = 0;
        int now = i;
        int mi = 100000;
        int sum = 0;

        while (1) {
            if (done[now]) break;

            cnt++;
            done[now] = true;
            mi = min(mi, w[now]);
            sum += w[now];
            now = mp[w[now]];
        }

        int tmp = sum + (cnt - 2) * mi;
        tmp = min(tmp, sum + mi + mini * (cnt + 1));
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
