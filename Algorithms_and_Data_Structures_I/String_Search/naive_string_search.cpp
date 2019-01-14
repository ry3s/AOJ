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

int main() {
    string str_t, str_p;
    cin >> str_t >> str_p;

    rep(i, str_t.size() - str_p.size() + 1) {
        if (str_p == str_t.substr(i, str_p.size()))
            cout << i << endl;
    }

    return 0;
}
