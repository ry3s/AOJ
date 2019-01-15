#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define MAX 300
using namespace std;

template <typename TYPE>
class Stack {
private:
  long long int top;
  TYPE* S;

public:
  Stack() {
    top = 0;
    S = new TYPE[MAX]; 
  };
  ~Stack() {
    delete [] S;
  };

  bool is_empty() {
    return top == 0;
  }
  bool is_full() {
    return top >= MAX - 1;
  }
  void push(TYPE x) {
    if (is_full()) exit(1); // error

    top++;
    S[top] = x;
  };
  TYPE pop() {
    if (is_empty()) exit(1); // error

    top--;
    return S[top + 1];
  };
  
};
int main() {
  Stack <long long int> stack;
  long long int x, y;
  string str;
  while (1) {
    cin >> str;
    if (cin.eof()) break;

    if (str == "+") {
      x = stack.pop();
      y = stack.pop();
      stack.push(y + x);
    } else if (str == "-") {
       x = stack.pop();
       y = stack.pop();
       stack.push(y - x);
    } else if (str == "*") {
       x = stack.pop();
       y = stack.pop();
      stack.push(y * x);
    } else {
      stack.push(stol(str));
    }
  }
  cout << stack.pop() << endl;
  return 0;
}
