#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Node {
  Node() {
    key = 0;
    left = right = 0;
  }
  LL key;
  Node *left, *right;
};

class BinarySearchTree {
public:
  BinarySearchTree() {
    root = new Node();
    node_num = 0;
  };

  void insert(LL insert_data) {
    if (node_num == 0) {
      root->key = insert_data;
      node_num++;
    } else {
      Node *tmp = root;
      while (1) {
        if (tmp->key < insert_data) {
          if (tmp->right == 0) {
            tmp->right = new Node();
            tmp->right->key = insert_data;
            node_num++;
            break;
          } else {
            tmp = tmp->right;
          }
        } else {
          if (tmp->left == 0) {
            tmp->left = new Node();
            tmp->left->key = insert_data;
            node_num++;
            break;
          } else {
            tmp = tmp->left;
          }
        }
      }
    }
  };

  Node* find(LL key) {
    Node *tmp = root;
    while (1) {
      if (tmp->key == key) {
        return tmp;
        // cout << "yes" << endl;
        // break;
      } else if (tmp->key < key) {
        if (tmp->right != 0) {
          tmp = tmp->right;
          continue;
        } else {
          return 0;
          // cout << "no" << endl;
          // break;
        }
      } else {
        if (tmp->left != 0) {
          tmp = tmp->left;
          continue;
        } else {
          return 0;
          // cout << "no" << endl;
          // break;
        }
      }
    }
  };
  void print() {
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
  };

private:
  Node *root;
  int node_num;
private:
  void preorder(Node *node) {
    cout << " " << node->key;
    if (node->left != 0) preorder(node->left);
    if (node->right != 0) preorder(node->right);
  }

  void inorder(Node *node) {
    if (node->left != 0) inorder(node->left);
    cout << " " << node->key;
    if (node->right != 0) inorder(node->right);
  }

};

int main() {
  int m;
  string cmd;
  LL insert_data;
  BinarySearchTree tree;
  cin >> m;

  rep(i, m) {
    cin >> cmd;
    if (cmd == "insert") {
      cin >> insert_data;
      tree.insert(insert_data);
    } else if (cmd == "print") {
      tree.print();
    } else if (cmd == "find") {
      LL key;
      cin >> key;
      if (tree.find(key) != 0) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
