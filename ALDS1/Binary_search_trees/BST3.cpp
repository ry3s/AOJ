#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Node {
  Node() {
    key = 0;
    left = right = 0;
    parent = 0;
  }
  LL key;
  Node *left, *right;
  Node *parent;
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
            tmp->right->parent = tmp;
            node_num++;
            break;
          } else {
            tmp = tmp->right;
          }
        } else {
          if (tmp->left == 0) {
            tmp->left = new Node();
            tmp->left->key = insert_data;
            tmp->left->parent = tmp;
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

  void deleteNode(long long delete_data){
		if(node_num == 0){
			return;
		}else{
			do_delete(root,delete_data);
		}
	}
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

  Node* findNextNode(Node* node){
		Node* tmp = node;
		while(tmp->left != 0) tmp = tmp->left;
		return tmp;
	}

  void do_delete(Node* node,long long delete_data){

		Node* tmp = node;
		while(true){
			if(tmp->key < delete_data){
				if(tmp->right == 0){
					//Do nothing
					break;
				}else{
					tmp = tmp->right;
				}
			}else if(tmp->key > delete_data){
				if(tmp->left == 0){
					//Do nothing
					break;
				}else{
					tmp = tmp->left;
				}
			}else{
				if(tmp->left == 0 && tmp->right == 0){
					if(tmp->parent->key < tmp->key){
						tmp->parent->right = 0;
					}else if(tmp->parent->key > tmp->key){
						tmp->parent->left = 0;
					}else{
						tmp->parent->right = 0;
					}
					delete tmp;
					node_num--;
					break;
				}else if(tmp->left == 0 && tmp->right != 0){

					if(tmp->parent->key < tmp->key){
						tmp->parent->right = tmp->right;
					}else if(tmp->parent->key > tmp->key){
						tmp->parent->left = tmp->right;
					}else{
						tmp->parent->right = 0;
					}
					tmp->right->parent = tmp->parent;
					delete tmp;
					node_num--;

					break;
				}else if(tmp->left != 0 && tmp->right == 0){

					if(tmp->parent->key < tmp->key){
						tmp->parent->right = tmp->left;
					}else if(tmp->parent->key > tmp->key){
						tmp->parent->left = tmp->left;
					}else{
						tmp->parent->right = 0;
					}
					tmp->left->parent = tmp->parent;
					delete tmp;
					node_num--;

					break;
				}else{
					Node* next_node = findNextNode(tmp->right);
					tmp->key = next_node->key;
					do_delete(tmp->right,next_node->key);
					break;
				}
			}
		}
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
    } else if (cmd == "delete") {
      LL delete_key;
      cin >> delete_key;
      tree.deleteNode(delete_key);
    }
  }

  return 0;
}
