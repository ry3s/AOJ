#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main() {
  string str, cmd, p;
  int n, a, b;
  cin >> str;
  cin >> n;
  rep(i, n) {
    cin >> cmd;
    if ( cmd == "print" ) {
      cin >> a >> b;
      cout << str.substr(a, b - a + 1) << endl;
      //      cout << str << endl;
    } else if ( cmd == "reverse" ) {
      cin >> a >> b;
      reverse(str.begin() + a, str.begin() + b + 1);
      //      cout << str << endl;
    } else if ( cmd == "replace" ) {
      cin >> a >> b >> p;
      str.replace(a, b - a + 1, p);
      //      cout << str << endl;
    }
  }
  return 0;
}
