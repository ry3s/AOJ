#include <iostream>
using namespace std;

int main() {
  int n, x;
  int count;

  while (1) {
    cin >> n >> x;
    if (n == 0 and x == 0) break;

    count = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        for (int m = j+1; m <= n; m++) {
          if (i + j + m == x) {
            count += 1;
          }
        }
      }
    }

    cout << count << endl;
  }
  return 0;
}
