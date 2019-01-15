#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int sum;
  string str;
  
  while (1) {
    cin >> str;
    if (str == "0") break;
    
    sum = 0;
    for (int i = 0; i < str.size(); i++) {
      sum += str[i] - '0';
    }

    cout << sum << endl;
  }
  
  return 0;
}
