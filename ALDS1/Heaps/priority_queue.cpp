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
    priority_queue<LL> Q;

    while (1) {
        string cmd;
        cin >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "insert") {
            LL x;
            cin >> x;
            Q.push(x);
        } else if (cmd == "extract") {
            LL x = Q.top();
            Q.pop();
            cout << x << endl;
        }
    }
    return 0;
}
