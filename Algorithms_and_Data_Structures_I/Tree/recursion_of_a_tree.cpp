#include <iostream>
#include <queue>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
int n, inputed_order[41] = {0};
queue<int> Queue;

struct Node {
  Node () {
    left = right = -1;
  };
  int left, right;
};
void postorder(Node *node, int id) {
  if (node[id].left != -1) postorder(node, node[id].left);
  if (node[id].right != -1) postorder(node, node[id].right);
  Queue.push(id+1);
}

int find_root(int inorder[], int left, int right) {
  int root = inorder[left];
  for (int i = left + 1; i <= right; i++) {
    if(inputed_order[root] > inputed_order[inorder[i]]) {
      root = inorder[i];
    }
  }
  return root;
}

void reconstruct(int inorder[], Node order[], int root, int left, int right) {
  int root_index;
  for (root_index = left; inorder[root_index] != root; root_index++);
  if (left < root_index) {
    int new_root = find_root(inorder, left, root_index - 1);
    order[root -1].left = new_root - 1;
    if (left < root_index - 1) reconstruct(inorder, order, new_root, left, root_index - 1);
  }
  if (root_index < right) {
    int new_root = find_root(inorder, root_index + 1, right);
    order[root -1].right = new_root - 1;
    if (root_index + 1 < right) reconstruct(inorder, order, new_root, root_index + 1, right);
  }
}
int main() {
  cin >> n;
  int preorder[n], inorder[n];
  Node order[n];

  rep(i, n) {
    cin >> preorder[i];
    inputed_order[preorder[i]] = i;
  }
  rep(i, n) {
    cin >> inorder[i];
  }
  if (n == 1) {
    cout << preorder[0] << endl;
  } else {
    reconstruct(inorder, order, preorder[0], 0, n - 1);
    postorder(order, preorder[0] - 1);
    while (not Queue.empty()) {
      if (Queue.size() != 1) {
        cout << Queue.front() << " ";
        Queue.pop();
      } else {
        cout << Queue.front() << endl;
        Queue.pop();
      }
    }
  }
  return 0;
}
