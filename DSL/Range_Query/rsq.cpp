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

// range sum query
class SqrtDecomposition {
private:
    const LL sqrt_n = 512; // bucket size
    LL num_data, num_bucket;
    vector<LL> data;
    vector<LL> bucket_sum;

public:
    SqrtDecomposition(LL n) : num_data(n) {
        num_bucket = (num_data + sqrt_n - 1) / sqrt_n;
        data.assign(num_bucket * sqrt_n, 0);
        bucket_sum.assign(num_bucket, 0);
    }

    void add(LL x, LL y) {
        LL k = x / sqrt_n;
        data[x] += y;
        LL sum = 0;
        for (LL i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
            sum += data[i];
        }
        bucket_sum[k] = sum;
    };
    // [x, y)
    LL get_sum(LL x, LL y) {
        LL sum = 0;
        rep(k, num_bucket) {
            LL left = k * sqrt_n;
            LL right = (k + 1) * sqrt_n;

            if (right <= x or y <= left) continue;

            if (x <= left and right <= y) {
                sum += bucket_sum[k];
            } else {
                for (LL i = max(x, left); i < min(y, right); i++) {
                    sum +=data[i];
                }
            }
        }
        return sum;
    };
};
int main() {
    int n, q;
    cin >> n >> q;
    SqrtDecomposition rsp(n);
    rep(i, q) {
        int cmd;
        LL x, y;
        cin >> cmd >> x >> y;

        if (cmd == 0) {
            rsp.add(x, y);
        } else if (cmd == 1) {
            cout << rsp.get_sum(x, y + 1) << endl;
        }
    }

    return 0;
}
