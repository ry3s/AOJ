#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
int a[2000100], c[100001] = {0}, ans[2000100];

int main() {
  int i, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }

  for(int i = 0,j=0; i < 10001; i++){
    if(c[i] != 0){
      for(int k = 0; k < c[i]; k++){
        ans[j++] = i;
      }
    }
  }


  for (i = 0; i < n-1; i++) cout << ans[i] << " ";
  cout << ans[n-1] << endl;
  return 0;
}
