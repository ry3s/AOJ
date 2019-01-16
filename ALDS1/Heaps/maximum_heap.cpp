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
    int h;
    while (cin >> h) {
        vector<int> node;
        for (int i = 0 ; i < h ; i++) {
            int tmp;
            cin >> tmp;
            node.push_back(tmp);
        }
        make_heap(node.begin(), node.end());
        for (int i = 0 ; i < h ; i++) {
            cout << " " << node[i];
        }
        cout << endl;
    }
    return 0;
}
// void max_heapify(vector<LL> &a, int i, int n) {
//     LL l = i * 2;
//     LL r = i * 2 + 1;
//     LL largest;
//     if (l <= n and a[l] > a[r]) {
//         largest = l;
//     } else {
//         largest = i;
//     }

//     if (r <= n and a[r] > a[largest]) {
//         largest = r;
//     }

//     if (largest != i) {
//         swap(a[i], a[largest]);
//         max_heapify(a, largest, n);
//     }
// }

// void build_max_heap(vector<LL> &a, int n) {
//     for (int i = n / 2; i == 1; i--) {
//         max_heapify(a, i, n);
//     }
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<LL> v;
//     v.push_back(0);
//     rep(i, n) {
//         LL x;
//         cin >> x;
//         v.push_back(x);
//     }
//     build_max_heap(v, n);

//     for (int i = 1; i <= n; i++) {
//         cout << " " << v[i] << endl;
//     }
//     return 0;

// }
