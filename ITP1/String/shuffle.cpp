#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
  string text;
  int n, h;
  

  while (1) {
    cin >> text;

    if ( text == "-" ) break;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
      cin >> h;
      rotate(text.begin(), text.begin() + h, text.end());
    }

    cout << text << endl;
  }

  return 0;
}
