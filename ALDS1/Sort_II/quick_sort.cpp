#include <iostream>
#include <utility>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Card {
  char design;
  LL num;
  LL input_order;
};

LL partition(Card* a, LL p, LL r) {
  LL x = a[r].num;
  LL i = p - 1;
  for (LL j = p; j < r; j++) {
    if (a[j].num <= x) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i+1], a[r]);
  return i + 1;
}
void quick_sort(Card* a, LL p, LL r) {
  if (p < r) {
    LL q = partition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q+1, r);
  }
}

int main() {
  Card *cards;
  LL n, x;
  char ch;
  bool is_stable = true;
  cin >> n;
  cards = new Card[n];
  rep(i, n) {
    cin >> ch >> x;
    cards[i].design = ch;
    cards[i].num = x;
    cards[i].input_order = i;
  }
  quick_sort(cards, 0, n - 1);

  for (int i = 1; i < n; i++) {
    if (cards[i].num == cards[i - 1].num
        and cards[i].input_order < cards[i - 1].input_order){
      is_stable = false;
      break;
    }
  }
  if (is_stable) {
    cout << "Stable" << endl;
  }
  else {
    cout << "Not stable" << endl;
  }
  rep(i, n) {
    cout << cards[i].design << " " << cards[i].num << endl;
  }

  delete [] cards;
  return 0;
}
