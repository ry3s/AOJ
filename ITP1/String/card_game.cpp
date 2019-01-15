#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main() {
  string taro, hanako;
  int n;
  int taro_score = 0, hanako_score = 0;

  cin >> n;
  rep(i, n) {
    cin >> taro >> hanako;
    if (taro == hanako) {
      taro_score++;
      hanako_score++;
    } else if (taro > hanako) {
      taro_score += 3;
    } else {
      hanako_score += 3;
    }
      
  }
  cout << taro_score << " " << hanako_score << endl;
  return 0;
}
