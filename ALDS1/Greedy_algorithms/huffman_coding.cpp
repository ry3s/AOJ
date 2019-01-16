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
    priority_queue<LL, vector<LL>, greater<LL> > qu;
    string s;
    cin >> s;
    vector<LL> dp(26, 0);
    rep(i, s.size()) {
        dp[s[i] -'a']++;
    }

    LL count = 0;
    rep(i, 26) {
        if (dp[i] != 0){
            qu.push(dp[i]);
            count++;
        }
    }
    LL sum = 0;
    for (int i = 1; i < count; i++) {
        LL a = qu.top();
        qu.pop();
        LL b = qu.top();
        qu.pop();
        sum += a + b;
        qu.push(a+b);
    }
    cout << max(sum, (LL) s.size()) << endl;
    return 0;
}
// int main() {
//     string str;
//     cin >> str;
//     if (str.length() == 1) {
//         cout << 1 << endl;
//         return 0;
//     }
//     vector<pair<char, int> > freq;
//     freq.push_back(make_pair(str[0], 1));
//     for (int i = 1; i < (int)str.size(); i++) {
//         bool is_new = true;
//         rep(j, freq.size()) {
//             if (freq[j].first == str[i]) {
//                 freq[j].second++;
//                 is_new = false;
//                 break;
//             }
//         }
//         if (is_new)
//             freq.push_back(make_pair(str[i], 1));

//     }
//     for(const auto &x : freq) {
//         cout << x.first << " " << x.second << endl;
//     }
//     sort(freq.begin(), freq.end(), [](pair<char, int> a, pair<char, int> b) {
//                                        return a.second < b.second;
//                                    });
//     int n = freq.size();
//     int ans = 0;

//     while (n > 1) {
//         int mini1 = 0;
//         int mini2 = 1;
//         if (freq[mini1].second > freq[mini2].second) swap(mini1, mini2);

//         for (int i = 2; i < n; i++) {
//             if (freq[i].second < freq[mini1].second) {
//                 mini2 = mini1;
//                 mini1 = i;
//             } else if (freq[i].second < freq[mini2].second) {
//                 mini2 = i;
//             }
//         }

//         // merge
//         int t = freq[mini1].second + freq[mini2].second;
//         ans += t;

//         if (mini1 == n - 1) swap(mini1, mini2);
//         freq[mini1].second = t;
//         freq[mini2].second = freq[n - 1].second;
//         n--;
//     }
//     cout << ans << endl;

//     return 0;
// }
