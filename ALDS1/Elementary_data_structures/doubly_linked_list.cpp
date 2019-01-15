#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define MAX 50005
using namespace std;

struct Node {
  long long int key;
  struct Node* prev;
  struct Node* next;
};
class DoublyLinkedList {
private:
  Node* init;
  
public:
  DoublyLinkedList() {
    init = new Node();
    init->key = -1;
    init->prev = init;
    init->next = init;
  };
  ~DoublyLinkedList() {
    Node* tmp = init->next;
    Node* next_node;
    while (tmp != init) {
      next_node = tmp->next;
      delete tmp;
      tmp = next_node;
    }
    delete init;
  };

  void insert_node(long long int x) {
    Node* tmp = init->next;
    init->next = new Node();
    init->next->key = x;
    init->next->next = tmp;
    init->next->prev = init;
    tmp->prev = init->next;
  };

  void delete_node(long long int x) {
    Node* tmp = init->next;
    while (tmp != init and tmp->key != x) {
      tmp = tmp->next;
    }
    if (tmp != init) {
      tmp->prev->next= tmp->next;
      tmp->next->prev = tmp->prev;
      delete tmp;
    }
  };

  void delete_first() {
    Node* tmp = init->next;
    init->next = init->next->next;
    init->next->prev = init;
    delete tmp;
  };

  void delete_last() {
    Node* tmp = init->prev;
    init->prev = init->prev->prev;
    init->prev->next = init;
    delete tmp;
  };
  void print_list() {
    Node* tmp = init->next;
    cout << tmp->key;
    tmp = tmp->next;
    while (tmp != init) {
      cout << " " << tmp->key;
      tmp = tmp->next;
    }
    cout << endl;
  };
};
int main() {
  DoublyLinkedList list;
  string str;
  long long int n, x;
  cin >> n;
  rep(i, n) {
    cin >> str;
    if (str == "insert") {
      cin >> x;
      list.insert_node(x);
    } else if (str == "delete") {
      cin >> x;
      list.delete_node(x);
    } else if (str == "deleteFirst") {
      //      cout << "!!!" << endl;
      list.delete_first();
    } else if (str == "deleteLast") {
      //cout << "///" << endl;
      list.delete_last();
    }
  }

  list.print_list();
  return 0;
}
