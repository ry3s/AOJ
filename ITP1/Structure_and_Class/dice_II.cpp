#include <iostream>

#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)

using namespace std;

class Dice {
public:
  Dice() {
    number = new int[6];
    work = new int[6];
  };
  ~Dice() {
    delete[] number;
    delete[] work;
  };

  void setLabel(int index, int num) {
    number[index] = num;
  };

  void roll(char dst) {
    rep(i, 6) {
      work[i] = number[i];
    }
    switch(dst) {
    case 'E':
			setNumber(work[3],work[1],work[0],work[5],work[4],work[2]);
			break;
		case 'N':
			setNumber(work[1],work[5],work[2],work[3],work[0],work[4]);
			break;
		case 'S':
			setNumber(work[4],work[0],work[2],work[3],work[5],work[1]);
			break;
		case 'W':
			setNumber(work[2],work[1],work[5],work[0],work[4],work[3]);
			break;
    }
  };

  int returnPeek() {
    return number[0];
  };
  int returnRightSide(int top, int front) {
    rep(i, 6) {
      if (number[i]  == top) top = i+1;
    }
    rep(i, 6) {
      if (number[i]  == front) front = i+1;
    }
    switch(top) {
    case 1:
      switch(front) {
      case 2:
        return 3;
        break;
      case 3:
        return 5;
        break;
      case 4:
        return 2;
        break;
      case 5:
        return 4;
        break;
      }
      break;
    case 2:
      switch(front) {
      case 1:
        return 4;
        break;
      case 3:
        return 1;
        break;
      case 4:
        return 6;
        break;
      case 6:
        return 3;
        break;
      }
      break;
    case 3:
      switch(front) {
      case 1:
        return 2;
        break;
      case 2:
        return 6;
        break;
      case 5:
        return 1;
        break;
      case 6:
        return 5;
        break;
      }
      break;
    case 4:
      switch(front) {
      case 1:
        return 5;
        break;
      case 2:
        return 1;
        break;
      case 5:
        return 6;
        break;
      case 6:
        return 2;
        break;
      }
      break;
    case 5:
      switch(front) {
      case 1:
        return 3;
        break;
      case 3:
        return 6;
        break;
      case 4:
        return 1;
        break;
      case 6:
        return 4;
        break;
      }
      break;
    case 6:
      switch(front) {
      case 2:
        return 4;
        break;
      case 3:
        return 2;
        break;
      case 4:
        return 5;
        break;
      case 5:
        return 3;
        break;
      }
      break;
    }
  };
  

private:
  void setNumber(int n0, int n1, int n2, int n3, int n4, int n5) {
		number[0] = n0;
		number[1] = n1;
		number[2] = n2;
		number[3] = n3;
		number[4] = n4;
		number[5] = n5;
	}
public:
  int* number;
  int* work;
};
      
int main() {
  Dice dice;
  int label, n, a, b;
  string str;
  rep(i, 6) {
    cin >> label;
    dice.setLabel(i, label);
  }
  cin >> n;
  rep(i, n) {
    cin >> a >> b;
    cout << dice.number[dice.returnRightSide(a, b) - 1] << endl;
  }
  return 0;
}
