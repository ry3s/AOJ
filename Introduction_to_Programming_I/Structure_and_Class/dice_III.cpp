#include <iostream>

#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

class Dice {
public:
  Dice() {
    number = new int[6];
    check_table = new int [101];
    rep(i, 101) check_table[i] = -1;
  };
  ~Dice() {
    delete[] number;
    delete[] check_table;
  };

  void set_label(int index, int num) {
    number[index] = num;
    check_table[num] = index;
  };

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

  bool is_valid_member(int input[]) {
    rep(i, 6) {
      if (check_table[input[i]] == -1) return false;
    }
    return true;
  }

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
private:
  int* number;
  int* check_table;
};
      
int main() {
  Dice dice;
  int tmp, input[6];
  rep(i, 6) {
    cin >> tmp;
    dice.set_label(i, tmp);
  }
  rep(i, 6) {
    cin >> input[i];
  }
  if (dice.is_valid_member(input) and dice.is_same_dice(input)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
      
  return 0;
}
