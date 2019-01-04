#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Node {
  Node () {
    left = right = parent = -1;
  }
  int left, right, parent;
};

void preorder(Node *node, int id) {
  cout << " " << id;
  if (node[id].left != -1) preorder(node, node[id].left);
  if (node[id].right != -1) preorder(node, node[id].right);
}

void inorder(Node *node, int id) {
  if (node[id].left != -1) inorder(node, node[id].left);
  cout << " " << id;
  if (node[id].right != -1) inorder(node, node[id].right);
}

void postorder(Node *node, int id) {
  if (node[id].left != -1) postorder(node, node[id].left);
  if (node[id].right != -1) postorder(node, node[id].right);
  cout << " " << id;
}

int main() {
  int n, id, left, right ,root;
  cin >> n;
  Node node[n];
  rep(i, n) {
    cin >> id >> left >> right;
    if (left != -1) {
      node[id].left = left;
      node[left].parent = id;
    }
    if (right != -1) {
      node[id].right = right;
      node[right].parent = id;
    }
  }
  for (root = 0; root < n; root++) {
    if (node[root].parent == -1) break;
  }
  cout << "Preorder" << endl;
  preorder(node, root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(node, root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(node, root);
  cout << endl;
  return 0;
}
