#include <iostream>
#include <set>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

int main() {
  set<string> s;
  int n;
  string str1, str2;
  cin >> n;
  rep(i, n) {
    cin >> str1 >> str2;
    if (str1 == "insert") {
      s.insert(str2);
    } else if ( str1 == "find") {
      if (s.find(str2) != s.end()) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
