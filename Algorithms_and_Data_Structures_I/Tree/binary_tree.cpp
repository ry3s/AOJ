#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

typedef struct {
  int p, s, deg, dep, h, left, right;
} Node;

Node tree[100000];
int n;

void set_depth(int x) {
  if (tree[x].p == -1) {
    tree[x].dep = 0;
    return;
  }
  if (tree[x].dep == -1) {
    set_depth(tree[x].p);
    tree[x].dep = tree[tree[x].p].dep + 1;
  }
}

void set_height(int x) {
  int l = tree[x].left;
  int r = tree[x].right;
  if (tree[x].deg == 0) {
    tree[x].h = 0;
    return;
  }
  if (tree[x].h == -1) {
    if (l != -1) {
      set_height(l);
      tree[x].h = max(tree[x].h, tree[l].h + 1);
    }
    if (r != -1) {
      set_height(r);
      tree[x].h = max(tree[x].h, tree[r].h + 1);
    }
  }
}

void init() {
  rep(i, 100000) {
    tree[i].p = tree[i].s = tree[i].deg = tree[i].dep = tree[i].h = tree[i].left = tree[i].right = -1;
  }
}

int main() {
  init();
  int id, a, b;

  cin >> n;
  rep(i, n) {
    cin >> id >> a >> b;
    if(a!=-1){
      tree[id].left=a;
      tree[a].p=id;
    }
    if(b!=-1){
      tree[id].right=b;
      tree[b].p=id;
    }
    if(a!=-1&&b!=-1){
      tree[a].s=b;
      tree[b].s=a;
    }
    tree[id].deg=(a!=-1)+(b!=-1);
    
  }
  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,tree[i].p,tree[i].s,tree[i].deg);
    set_depth(i);
    set_height(i);
    printf("depth = %d, height = %d, ",tree[i].dep,tree[i].h);
     
    if(tree[i].p==-1)printf("root\n");
    else if(tree[i].deg!=0)printf("internal node\n");
    else printf("leaf\n");
     
  }
  return 0;
}
