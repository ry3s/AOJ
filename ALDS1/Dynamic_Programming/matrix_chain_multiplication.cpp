#include <iostream>
#include <climits>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
int dp[101][101];
int *p;

int rec(int row, int column) {
  int minimum = INT_MAX;
  int num = column - row;
  rep(i, num) {
    minimum = min(minimum, dp[row][row + i]
               + dp[row + i + 1][column]
               + p[row - 1] * p[row + i] * p[column]);
  }
  return minimum;
}
int main() {
  int n;
  cin >> n;
  rep(i, n+1) dp[i][i] = 0;

  p = (int *)malloc(sizeof(int) * (n+1));
  cin >> p[0];
  cin >> p[1];
  int tmp;
  for (int i = 2; i <= n; i++) {
    cin >> tmp;
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++)
    dp[i][i + 1] = p[i - 1] * p[i] * p[i + 1];

  for (int j = 0; j <= n - 3; j++) {
    for (int i = 3 + j; i <= n; i++) {
      dp[i - 2 - j][i] = rec(i - 2 - j, i);
    }
  }
  cout << dp[1][n] << endl;

  return 0;
}
