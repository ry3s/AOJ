#include <iostream>

using namespace std;

int main() {
  long long n, m, l;
  cin >> n >> m >> l;
  long long A[n][m], B[m][l], C[n][l];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < l; j++) {
      cin >> B[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < l; j++) {
      C[i][j] = 0;
    }
  }

  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < l; j++) {
      for (long long k = 0; k < m; k++) {
        C[i][j] += A[i][k] * B[k][j];
        
      }
    }
  }  
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < l; j++) {
      if (j == l - 1) {
        cout << C[i][j];
      } else {
        cout << C[i][j] << " ";
      }
    }
    cout << endl;
  }
 
  return 0;
}
