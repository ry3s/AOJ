#include <iostream>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  int sheet[r+1][c+1];
  for ( int i = 0; i < r; i++ ) {
    for ( int j = 0; j < c; j++ ) {
      cin >> sheet[i][j]; 
    }
  }

  for ( int i = 0; i < r; i++ ) {
    sheet[i][c] = 0;
    for ( int j = 0; j < c; j++ ) {
      sheet[i][c] += sheet[i][j];
    }
  }
  for ( int i = 0; i < c; i++ ) {
    sheet[r][i] = 0;
    for ( int j = 0; j < r; j++ ) {
      sheet[r][i] += sheet[j][i];
    }
  }
  sheet[r][c] = 0;
  for ( int i = 0; i < r; i++ ) {
    sheet[r][c] += sheet[i][c];
  }
  // for ( int i = 0; i < c; i++ ) {
  //   sheet[r][c] += sheet[r][i];
  // }
  

  for ( int i = 0; i < r+1; i++ ) {
    for ( int j = 0; j < c+1; j++ ) {
      if (j == c) {
        cout << sheet[i][j];
      } else {
        cout << sheet[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;

}
