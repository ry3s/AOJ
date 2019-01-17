#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

struct Node {
    Node() {
        key = priority = 0;
        left = right = parent = nullptr;
    }
    int key;
    int priority;
    Node *left, *right, *parent;
};

class Treap {
public:
    bool find(int x) {
        Node *tmp = root;

        while (tmp != nullptr) {
            if (tmp->key == x) return true;
            else if (tmp->key > x) tmp = tmp->left;
            else tmp = tmp->right;
        }

        return false;
    };

    void print() {
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
        return;
    };

    void insert(int key, int priority) {
        root = insert_node(root, key, priority);
    }

    void delete_(int key) {
        root = delete_node(root, key);
    };

private:
    Node *root;

    void inorder(Node *p) {
        if (p == nullptr) return;
        inorder(p->left);
        cout << " " << p->key;
        inorder(p->right);
        return;
    };

    void preorder(Node *p) {
        if (p == nullptr) return;
        cout << " " << p->key;
        preorder(p->left);
        preorder(p->right);
        return;
    };

    Node *right_rotate(Node *t) {
        Node *s = t->left;
        t->left = s->right;
        s->right = t;
        return s;
    };

    Node *left_rotate(Node *t) {
        Node *s =  t->right;
        t->right = s->left;
        s->left = t;
        return s;
    };

    Node *insert_node(Node *t, int key, int priority) {
        if (t == nullptr) {
            Node *new_node = new Node();
            new_node->key = key;
            new_node->priority = priority;
            return new_node;
        }
        if (key == t->key) {
            return t;
        }

        if (key < t->key) {
            t->left = insert_node(t->left, key, priority);
            if (t->priority < t->left->priority) {
                t = right_rotate(t);
            }
        } else {
            t->right = insert_node(t->right, key, priority);
            if (t->priority < t->right->priority) {
                t = left_rotate(t);
            }
        }
        return t;
    };

     Node *delete_node(Node *t, int key) {
        if (t == nullptr) {
            return nullptr;
        }

        if (key < t->key) {
            t->left = delete_node(t->left, key);
        } else if (key > t->key) {
            t->right = delete_node(t->right, key);
        } else {
            return delete_node_(t, key);
        }
        return t;
    };
    Node *delete_node_(Node *t, int key) {
        if (t->left == nullptr and t->right == nullptr) {
            return nullptr;
        } else if (t->left == nullptr) {
            t = left_rotate(t);
        } else if (t->right == nullptr) {
            t = right_rotate(t);
        } else {
            if (t->left->priority > t->right->priority) {
                t = right_rotate(t);
            } else {
                t = left_rotate(t);
            }
        }
        return delete_node(t, key);
    };

};

int main() {
    Treap treap;

    int n;
    cin >> n;
    rep(i, n) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int k, p;
            cin >> k >> p;
            treap.insert(k, p);
        } else if (cmd == "find") {
            int k;
            cin >> k;
            if (treap.find(k)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (cmd == "delete") {
            int k;
            cin >> k;
            treap.delete_(k);
        } else if (cmd == "print") {
            treap.print();
        }
    }
    return 0;
}
