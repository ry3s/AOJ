#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    deque<LL> deq;
    rep(i, n) {
        int x;
        cin >> x;
        if (x == 0) {
            int d;
            cin >> d;
            if (d == 0) {
                int y;
                cin >> y;
                deq.push_front(y);
            } else if (d == 1) {
                int y;
                cin >> y;
                deq.push_back(y);
            }
        } else if (x == 1) {
            int p;
            cin >> p;
            cout << deq.at(p) << endl;
        } else if (x == 2) {
            int d;
            cin >> d;
            if (d == 0) {
                deq.pop_front();
            } else if (d == 1) {
                deq.pop_back();
            }

        }
    }
    return 0;
}
