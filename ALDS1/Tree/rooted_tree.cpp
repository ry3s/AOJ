#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i = a ; i < (int)n ; i++)
#define pb push_back
#define NIL -1
#define MAX 100001

using namespace std;

struct Node{
  int id;
  int parent;
  vector<int> child;
  int depth;
  
  void addChild(int c){
    child.pb(c);
  }
    
 void print(){
    cout << "node " << id << ": ";
    cout << "parent = " << parent << ", ";
    cout << "depth = " << depth << ", ";
    cout << (parent == -1?"root":child.size()==0?"leaf":"internal node") << ", ";
    cout << "[";
    if(child.size() != 0){
      rep(i, child.size()-1){
    cout << child[i] << ", ";
      }
      cout << child[child.size()-1];
    }
      cout << "]" << endl;
 }
};

Node node[MAX];

void init(int n){
  rep(i, n){
    node[i].depth = NIL;
    node[i].parent = NIL;
    node[i].child.clear();    
  }
}

signed main(){
  int n;
  int id, k, c, root;
  cin >> n;
  init(n);
  
  root = NIL;

  rep(i, n){
    cin >> id >> k;
    node[id].id = id;
    rep(j, k){
      cin >> c;
      node[id].addChild(c);
      node[c].parent = id;
      node[c].depth = node[id].depth + 1;
    }
  }

  rep(i, n){
    if(node[i].parent == NIL){
      root = i;
      break;
    }
  }
  
  queue<pair<Node, int> > q;
  q.push(make_pair(node[root], -1));
  while(!(q.empty())){
    pair<Node, int> p = q.front(); q.pop();
    node[p.first.id].depth = p.second + 1;
    rep(i, p.first.child.size()){
      q.push(make_pair(node[p.first.child[i]], p.second + 1));
    }
  }
  
  rep(i, n){
    node[i].print();
  }
}
