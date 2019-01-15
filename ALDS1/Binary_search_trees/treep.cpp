#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Node {
  Node() {
    key = priority = 0;
    left = right = parent = 0;
  }
  LL key;
  LL priority;
  Node *left, *right, *parent;
};

class Treap {
public:
  Treap() {

  };

private:
  Node *root;

};

int main() {

  return 0;
}
