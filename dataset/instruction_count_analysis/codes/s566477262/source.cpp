#include "stdc++.h"



class Node {

public:

  Node() : left(nullptr), right(nullptr) {}

  int val;

  int min;

  int num;

  int rank;

  Node *left, *right;

};



void dump(Node* p) {

  if( p == nullptr ) {

    fprintf(stderr, "(nil)");

    return;

  }

  if( p->left == nullptr and p->right == nullptr ) {

    fprintf(stderr, "{n%d}(%d)", p->num, p->val);

    return;

  }

  fprintf(stderr, "{n%d,r%d,m%d}[", p->num, p->rank, p->min);

  dump(p->left);

  fprintf(stderr, ",");

  dump(p->right);

  fprintf(stderr, "]");

}



void dumpLine(Node* p) {

  return;

  dump(p);

  puts("");

}



template<typename T, int chunksize = 262144>

class Heap {

public:

  Heap() : n(chunksize) {}

  std::vector<T*> ptrs;

  std::stack<T*>  stack;

  int n;

  T* next() {

    if( not stack.empty() ) {

      T* res = stack.top(); stack.pop();

      return res;

    }

    if( n == chunksize ) {

      T* p = new T[chunksize];

      ptrs.push_back(p);

      n = 0;

    }

    T* res = &ptrs[ptrs.size()-1][n];

    n += 1;

    return res;

  }

  void push(T* p) {

    stack.push(p);

  }

};

Heap<Node> heap;



Node* initNode(int val) {

  Node *p = heap.next();

  p->left = p->right = nullptr;

  p->min = p->val = val;

  p->num = 1;

  p->rank = 1;

  return p;

}



Node* initNode(Node* left, Node* right) {

  Node *p = heap.next();

  p->left = left;

  p->right = right;

  return p;

}



bool isLeaf(Node *p) {

  assert( p != nullptr );

  return p->left == nullptr and p->right == nullptr;

}



Node* update(Node* p) {

  if( p == nullptr ) return nullptr;

  if( isLeaf(p) ) return p;

  p->min = (1<<30);

  p->num = 0;

  p->rank = 1;

  if( p->left != nullptr ) {

    p->min = std::min(p->min, p->left->min);

    p->num += p->left->num;

    p->rank = std::max(p->rank, p->left->rank + 1);

  }

  if( p->right != nullptr ) {

    p->min = std::min(p->min, p->right->min);

    p->num += p->right->num;

    p->rank = std::max(p->rank, p->right->rank + 1);

  }

  return p;

}





Node* rotate(Node *v, int d) {

  //fprintf(stderr, "rotate : %d\n", d);

  assert( not isLeaf(v) );

  if( d < 0 ) {

    Node *w = v->right;

    if( isLeaf(w) ) return v;

    if( w == nullptr ) return v;

    Node *a = w->left;

    v->right = a;

    w->left = v;

    update(v);

    update(w);

    return w;

  }

  if( d > 0 ) {

    Node *w = v->left;

    if( isLeaf(w) ) return v;

    if( w == nullptr ) return v;

    Node *a = w->right;

    v->left = a;

    w->right = v;

    update(v);

    update(w);

    return w;

  }

  assert(0);

}



inline int getRank(Node* p) {

  if( p == nullptr ) return 0;

  return p->rank;

}



Node* merge(Node* a, Node* b, int d) {

  if( a == nullptr and b == nullptr ) return nullptr;

  if( a == nullptr or b == nullptr ) return a == nullptr ? b : a;

  int rL = getRank(a);

  int rR = getRank(b);

  if( rL == rR ) {

    Node *p = initNode(a, b);    

    return update(p);

  }

  assert( a != nullptr and b != nullptr );

  Node *v, *w;

  if( rL < rR ) {

    v = b;

    w = merge(a, b->left, -1);

    v->left = w;

  }

  else {

    v = a;

    w = merge(a->right, b, 1);

    v->right = w;

  }

  assert( v->left != nullptr and v->right != nullptr );

  int rD = getRank(v->right) - getRank(v->left);

  if( rD < -1 ) v = rotate(v, 1);

  else if( 1 < rD ) v = rotate(v, -1);

  else if( rD < 0 and 0 < d ) v = rotate(v, 1);

  else if( 0 < rD and d < 0 ) v = rotate(v, -1); 

  return update(v);

}



std::tuple<Node*, Node*> split(Node* p, int n) {

  if( p == nullptr ) return std::make_tuple(nullptr, nullptr);

  if( isLeaf(p) ) {

    if( n == 0 ) return std::make_tuple(nullptr, p);

    else return std::make_tuple(p, nullptr);

  }

  assert( p->left != nullptr and p->right != nullptr );

  int m = p->left->num;

  if( n <= m ) {

    auto t = split(p->left, n);

    auto res = std::make_pair(std::get<0>(t), merge(std::get<1>(t), p->right, 0));

    heap.push(p);

    return res;

  }

  else {

    auto t = split(p->right, n - p->left->num);

    auto res = std::make_pair(merge(p->left, std::get<0>(t), 0), std::get<1>(t));

    heap.push(p);

    return res;

  }

}



// [l, r)

int minimum(Node* p, int l, int r) {

  //fprintf(stderr, "(l, r) = (%d, %d)\n", l, r);

  if( p == nullptr ) return (1 << 30);

  assert( p != nullptr );

  assert( r <= p->num );

  if( isLeaf(p) ) return p->min;

  if( l == 0 and r == p->num ) return p->min;

  assert( p->left != nullptr and p->right != nullptr );

  int m = p->left->num;

  if( r <= m ) return minimum(p->left, l, r);

  if( m <= l ) return minimum(p->right, l - m, r - m);

  assert( l < m and m < r );

  return std::min(minimum(p->left, l, m), minimum(p->right, m - m, r - m));

}



Node* updateVal(Node* p, int k, int v) {

  if( isLeaf(p) and k == 0 ) {

    p->min = p->val = v;

    p->num = 1;

    return p;

  }

  assert( not ( isLeaf(p) and k != 0 ) );

  int m = p->left == nullptr ? 0 : p->left->num;

  if( k < m ) {

    p->left = updateVal(p->left, k, v);

    return update(p);

  }

  else {

    p->right = updateVal(p->right, k - m, v);

    return update(p);

  }

}



int main() {



  Node* root = nullptr;



  int n; scanf("%d", &n);

  int q; scanf("%d", &q);

  for(int i = 0; i < n; ++i) {

    int a; scanf("%d", &a);

    root = merge(root, initNode(a), 1);

    dumpLine(root);

  }

  dumpLine(root);

  for(int i = 0; i < q; ++i) {

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    if( x == 0 ) {

      Node *n1, *n2, *n3, *n4;

      std::tie(n1, n2) = split(root, y);

      dumpLine(n1);

      std::tie(n2, n3) = split(n2, z - y);

      dumpLine(n2);

      std::tie(n3, n4) = split(n3, 1);

      dumpLine(n3);

      dumpLine(n4);

      root = merge(merge(merge(n1, n3, 1), n2, 1), n4, 1);

    }

    if( x == 1 ) {

      int res = minimum(root, y, z + 1);

      printf("%d\n", res);

    }

    if( x == 2 ) {

      root = updateVal(root, y, z);

    }

    dumpLine(root);

  }

  

  return 0;

}