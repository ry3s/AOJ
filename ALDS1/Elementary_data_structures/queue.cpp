#include <iostream>
#include <string>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define MAX 50005
using namespace std;

template <typename TYPE>
class Queue {
private:
  long long int head;
  long long int tail;
  TYPE* Q;

public:
  Queue() {
    head = 0;
    tail = 0;
    Q = new TYPE[MAX];
  };
  ~Queue() {
    delete [] Q;
  };

  bool is_empty() {
    return head == tail;
  };

  bool is_full() {
    return head == (tail + 1) % MAX;
  };

  void enqueue(TYPE x){
    if (is_full()) exit(1);

    Q[tail] = x;
    if (tail + 1 == MAX) {
      tail = 0;
    } else {
      tail++;
    }
  };
  
  TYPE dequeue() {
    if (is_empty()) exit(1);

    TYPE x = Q[head];
    if (head + 1 == MAX) {
      head = 0;
    } else {
      head++;
    }
    return x;
  };
};

struct process {
  string name;
  long long time;
};

int main() {
  Queue<process> pq;
  long long n, q;
  struct process tmp;
  long long x, total_time = 0;
  string str;
  cin >> n >> q;

  rep(i, n) {
    cin >> str >> x;
    tmp.name = str;
    tmp.time = x;
    pq.enqueue(tmp);
  }
  // rep(i, n) {
  //   tmp = pq.dequeue();
  //   cout << tmp.name << endl;
  // }
  while (not pq.is_empty()) {
    tmp = pq.dequeue();
    if (tmp.time <= q) {
      total_time += tmp.time;
      cout << tmp.name << " " <<  total_time << endl;
    } else {
      tmp.time -= q;
      total_time += q;
      pq.enqueue(tmp);
    }
  }
  return 0;
}
