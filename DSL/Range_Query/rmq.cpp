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

const LL INF = (1LL << 31) - 1;
const LL sqrt_n = 512;
// struct SqrtDecomposition {
//   int N, K;
//   vector<int> data;
//   vector<int> bucketMin;
//   SqrtDecomposition(int n) : N(n) {
//     K = (N + sqrtN - 1) / sqrtN;
//     data.assign(K * sqrtN, INF);
//     bucketMin.assign(K, INF);
//   }
//   void update(int x, int y) {
//     int k = x / sqrtN;
//     int minVal = data[x] = y;
//     for(int i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
//       minVal = min(minVal, data[i]);
//     }
//     bucketMin[k] = minVal;
//   }
//   // [x, y)
//   int find(int x, int y) {
//     int minVal = INF;
//     for (int k = 0; k < K; ++k) {
//       int l = k * sqrtN, r = (k + 1) * sqrtN;
//       if (r <= x || y <= l)
//         continue;
//       if (x <= l && r <= y) {
//         minVal = min(minVal, bucketMin[k]);
//       } else {
//         for (int i = max(x, l); i < min(y, r); ++i) {
//           minVal = min(minVal, data[i]);
//         }
//       }
//     }
//     return minVal;
//   }
// };
class SqrtDecomposition{
private:
    LL num_data, bucket_size;
    vector<LL> data;
    vector<LL> bucket_min;
public:
    SqrtDecomposition(LL n) {
        num_data = n;
        bucket_size = (n + sqrt_n - 1) / sqrt_n;
        data.assign(bucket_size * sqrt_n, INF);
        bucket_min.assign(bucket_size, INF);
    };

    void update(LL x, LL y) {
        LL k = x / sqrt_n;
        LL min_val = data[x] = y;
        for (LL i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
            min_val = min(min_val, data[i]);
        }
        bucket_min[k] = min_val;
    };

    // [x, y)
    LL find(LL x, LL y) {
        LL min_val = INF;
        rep(k, bucket_size) {
            LL l = k * sqrt_n;
            LL r = (k + 1) * sqrt_n;
            if (r <= x or y <= l) {
                continue;
            }

            if (x <= l and r <= y) {
                min_val = min(min_val, bucket_min[k]);
            } else {
                for (LL i = max(x, l); i < min(y, r); i++) {
                    min_val = min(min_val, data[i]);
                }
            }
        }
        return min_val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    SqrtDecomposition rmq(n);
    rep(i, q) {
        int cmd;
        LL x, y;
        cin >> cmd >> x >> y;

        if (cmd == 0) {
            rmq.update(x, y);
        } else if (cmd == 1) {
            cout << rmq.find(x, y + 1) << endl;
        }
    }
    return 0;
}
