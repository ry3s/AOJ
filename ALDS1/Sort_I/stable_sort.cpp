#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

struct Card {
  int value;
  char design;
};

void selection_sort(Card* a, int n) {
  rep(i, n) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j].value < a[minj].value) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(a[i], a[minj]);

    }
  }

}

void bubble_sort(Card* a, int n) {
  bool flag = true;
   while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (a[i].value < a[i - 1].value) {
         swap(a[i], a[i - 1]);
        flag = true;
      }
    }
  }

 }
bool is_stable(Card* in, Card* out, int n) {
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      rep(k, n) {
        for(int l = k + 1; l < n; l++) {
          if (in[i].value == in[j].value
              and in[i].design == out[l].design
              and in[i].value == out[l].value
              and in[j].design == out[k].design
              and in[j].value == out[k].value) {
            return false;
          }
        }
      }
    }
  }

  return true;
}
int main() {
  int n;
  cin >> n;
  Card card[n], a[n], b[n];
  rep(i, n) {
    scanf(" %c%d", &card[i].design, &card[i].value);
  }
  rep(i, n) {
    a[i] = card[i];
    b[i] = card[i];
  }
  bubble_sort(a, n);
  selection_sort(b, n);

  rep(i, n) {
    if (i == n - 1) cout << a[i].design << a[i].value << endl;
    else cout << a[i].design << a[i].value << " ";
  }
  if (is_stable(card, a, n)) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  
  rep(i, n) {
    if (i == n - 1) cout << b[i].design << b[i].value << endl;
    else cout << b[i].design << b[i].value << " ";
  }
  if (is_stable(card, b, n)) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  
  return 0;
}
