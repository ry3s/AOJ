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

// const ULL B = 100000007;
// bool contain(string a, string b) {
//     int an = a.length();
//     int bn = b.length();
//     if (an > bn) return false;

//     ULL tmp = 1;
//     rep(i, an) tmp *= B;

//     ULL a_hash = 0;
//     ULL b_hash = 0;
//     // an文字目までのハッシュを計算
//     rep(i, an) a_hash = a_hash * B + a[i];
//     rep(i, an) b_hash = b_hash * B + b[i];

//     rep(i, bn - an + 1) {
//         if (a_hash == b_hash) return true;
//         if (i + an < bn) b_hash = b_hash * B + b[i + an] - b[i] * tmp;
//     }
//     return false;
// }

struct Suffix {
    string suffix;
    LL index;
};
int main() {
    string target;
    cin >> target;
    LL target_len = target.length();
    string tarr[target_len];
    rep(i, target_len - 1) {
        tarr[i] = target.substr(i, target_len);
    }
    sort(tarr, tarr + target_len);

    string pattern;
    LL n;
    cin >> n;
    rep(i, n) {
        cin >> pattern;
        LL left = 0;
        LL right = target_len;
        while (right - left > 1) {
            LL mid = (left + right) / 2;
            if (target.compare(tarr[mid], pattern.size(), pattern) < 0) left = mid;
            else right = mid;
        }
        cout << target.compare(tarr[right], pattern.size(), pattern) == 0 << endl;
    }



    return 0;
}
