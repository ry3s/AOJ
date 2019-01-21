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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

void print_binary32(uint32_t x) {

}
int main() {
    uint32_t x;
    cin >> x;
    cout << static_cast<bitset<32> >(x) << endl;
    cout << static_cast<bitset<32> >(~x) << endl;
    cout << static_cast<bitset<32> >(x << 1) << endl;
    cout << static_cast<bitset<32> >(x >> 1) << endl;
    return 0;
}
