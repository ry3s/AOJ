#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;
bool my_binary_search(int key, vector<int> v) {
  long long int left = 0, right = v.size();
  while (left < right) {
    long long int mid = (left + right) / 2;
    if (v[mid] == key) return true;
    else if (key < v[mid]) right = mid;
    else left = mid + 1;
  }
  return false;
}

int main() {
  int tmp, cnt = 0;
  long long n, q;
  vector<int> vs, vt;
  cin >> n;
  rep(i, n) {
    cin >> tmp;
    vs.push_back(tmp);
  }
  cin >> q;
  rep(i, q) {
    cin >> tmp;
    vt.push_back(tmp);
  }
  
  sort(vs.begin(), vs.end());
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  
  rep(i, q) {
    if (my_binary_search(vt[i], vs)) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}
