#include <iostream>
#include <vector>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
typedef long long int LL;
using namespace std;
int cnt = 0;
template <typename Itr>
void merge(Itr l, Itr m, Itr r) {
  vector<int> tmp(r - l);
  Itr it = tmp.begin(), it1 = l, it2 = m;
  while (it1 != m and it2 != r) {
    cnt++;
    if (*it1 < *it2) *it++ = *it1++;
    else *it++ = *it2++;
  }
  while (it1 != m) {
    *it++ = *it1++;
    cnt++;
  }
  while (it2 != r) {
    *it++ = *it2++;
    cnt++;
  }
  copy(tmp.begin(), tmp.end(), l);
}
template <typename Itr>
void my_merge_sort(Itr l, Itr r) {
  if (r - l <= 1) return;
  Itr m = l + (r - l) / 2;
  my_merge_sort(l, m);
  my_merge_sort(m, r);
  merge(l, m, r);
}
int main() {
  int n;
  int tmp;
  vector<int> v;
  cin >> n;
  rep(i, n) {
    cin >> tmp;
    v.push_back(tmp);
  }
  my_merge_sort(v.begin(), v.end());

  rep(i, n) {
    if (i == n - 1) cout << v[i] << endl;
    else cout << v[i] << " ";
  }
  cout << cnt << endl;
  return 0;
  
}
