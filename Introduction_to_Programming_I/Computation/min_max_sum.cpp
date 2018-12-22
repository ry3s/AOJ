#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  long long int n, a, min, max, sum;
  vector<long long int> v;

  cin >> n;
  for (long long int  i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  min = v[0];
  max = v[n-1];
  sum = accumulate(v.begin(), v.end(), 0LL);
  cout << min << " " << max << " " << sum << endl;

  return 0;
}
