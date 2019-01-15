#include <iostream>
using namespace std;

int main() {
  int m, f, r;

  while (1) {
    
    cin >> m >> f >> r;
    if (m == -1 and f == -1 and r == -1) break;

    if (m == -1 or f == -1) {
      cout << "F" << endl;
    } else if (m + f >= 80) {
      cout << "A" << endl;
    } else if (m + f >= 65 and m + f < 80) {
      cout << "B" << endl;
    } else if (m + f >= 50 and m + f < 65) {
      cout << "C" << endl;
    } else if (m + f >= 30 and m + f < 50) {
      if (r >= 50) {
        cout << "C" << endl;
      } else {
        cout << "D" << endl;
      }
    } else if (m + f < 30) {
      cout << "F" << endl;
    }
  }
  return 0;
}
