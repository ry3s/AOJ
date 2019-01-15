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
	string target;
	string pattern;
  cin >> target;
  cin >> pattern;

	int n = pattern.length();
	vector<int> a(n + 1);

	a[0] = -1;
	int k = -1;
	rep(i, n) {
		for (; k != -1 && pattern[k] != pattern[i]; k = a[k]);
		a[i + 1] = ++k;
	}

	int m = target.length();
	int i = 0, j = 0;
	while (j <= m) {
      if (i < n and j < m and pattern[i] == target[j]) {
        i++;
        j++;
      }
      else {
          if (i == n) cout << j - n << endl;
          if (i) i = a[i];
          else j++;
      }
  }
  return 0;
}
