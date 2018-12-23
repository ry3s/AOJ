#include <iostream>

using namespace std;

int main() {
  int n;
  int b, f, r, v;
  cin >> n;
  int room[4][3][10] = {{{0}}}; //4棟3階10番目の部屋
  for (int i = 0; i < n; i++) {
    cin >> b >> f >> r >> v;
    //printf("!%d %d %d %d\n", b, f, r, v);
    room[b-1][f-1][r-1] += v;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      for(int m = 0; m < 10; m++) {
        cout << " " << room[i][j][m];
      }
      cout << endl;
    }
    if (i < 3) {
      cout << "####################" << endl;
    }
  }
  
    
    
  return 0;
}
