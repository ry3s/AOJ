#include <iostream>

#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

class Dice {
public:
  int number[6];

  void roll(char dst) {
    switch(dst) {
    case 'E':
			set_number(number[3],number[1],number[0],number[5],number[4],number[2]);
			break;
		case 'N':
			set_number(number[1],number[5],number[2],number[3],number[0],number[4]);
			break;
		case 'S':
			set_number(number[4],number[0],number[2],number[3],number[5],number[1]);
			break;
		case 'W':
			set_number(number[2],number[1],number[5],number[0],number[4],number[3]);
			break;
    }
  };

  bool is_same_dice (int input[]) {
    char order[25] = "NNNNWNNNWNNNENNNENNNWNNN";
    rep(i, 24) {
      roll(order[i]);
      rep(j, 6) {
        if (input[j] != number[j]) break;
        if (j == 5) return true;
            
      }
    }
    return false;
  }
private:
  void set_number(int n0, int n1, int n2, int n3, int n4, int n5) {
		number[0] = n0;
		number[1] = n1;
		number[2] = n2;
		number[3] = n3;
		number[4] = n4;
		number[5] = n5;
	}

};
      
int main() {
  int n, tmp;
  cin >> n;
  Dice ndice[n];
  
  rep(i, n) {
    rep(j, 6) {
      cin >> tmp;
      ndice[i].number[j] = tmp;
    }
  }
  int i, j;
  for (i = 0; i <  n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ( ndice[i].is_same_dice(ndice[j].number) ) break;
    }
    if (j < n) break;
  }
  if (i == n - 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
