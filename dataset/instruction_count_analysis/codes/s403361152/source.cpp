// #include "avlarray.hpp"



#include <memory>

#include <cassert>

#include <vector>

#include <stack>



template<typename a>

struct Node {

  Node() : left(nullptr), right(nullptr), n(0), rank(0), val(0) {}

  Node(a v_) : left(nullptr), right(nullptr), n(1), rank(1), val(v_) {}

  Node(std::shared_ptr< Node<a> > l, std::shared_ptr< Node<a> > r)

    : left(l), right(r), n(l->n + r->n), rank(std::max(l->rank, r->rank) + 1), val(mergeInfo(l->val, r->val)) {} 

  std::shared_ptr< Node<a> > left;

  std::shared_ptr< Node<a> > right;

  int n;

  int rank;

  a val;

};



template<typename a>

using AVLArray = std::shared_ptr< Node<a> >;



template<typename a>

std::shared_ptr<Node<a>> merge(std::shared_ptr<Node<a>> left, std::shared_ptr<Node<a>> right) {

  if( left.get() == nullptr and right.get() == nullptr ) assert(0);

  if( left.get() == nullptr ) return right;

  if( right.get() == nullptr ) return left;

  if( left->rank - right->rank >= 2 ) {

    if( left->left->rank >= left->right->rank ) {

      return std::shared_ptr<Node<a>>(new Node<a>(left->left, merge(left->right, right)));

    }

    else {

      return std::shared_ptr<Node<a>>(new Node<a>(merge(left->left, left->right->left), merge(left->right->right, right)));

    }

  }

  if( left->rank - right->rank <= -2 ) {

    if( right->right->rank >= right->left->rank ) {

      return std::shared_ptr<Node<a>>(new Node<a>(merge(left, right->left), right->right));

    }

    else {

      return std::shared_ptr<Node<a>>(new Node<a>(merge(left, right->left->left), merge(right->left->right, right->right)));

    }

  }

  return std::shared_ptr<Node<a>>(new Node<a>(left, right));

}



template<typename a>

std::pair<std::shared_ptr<Node<a>>, std::shared_ptr<Node<a>>> split(std::shared_ptr<Node<a>> root, int k) {

  if( root.get() == nullptr ) return std::make_pair(std::shared_ptr<Node<a>>(nullptr), std::shared_ptr<Node<a>>(nullptr));

  if( k == 0 ) return std::make_pair(std::shared_ptr<Node<a>>(nullptr), root);

  if( k == root->n ) return std::make_pair(root, std::shared_ptr<Node<a>>(nullptr));

  assert( root->n != 1 );

  if( k <= root->left->n ) {

    auto s = split(root->left, k);

    return std::make_pair(s.first, merge(s.second, root->right));

  }

  else {

    auto s = split(root->right, k - root->left->n);

    return std::make_pair(merge(root->left, s.first), s.second);

  }

}



template<typename a>

std::shared_ptr<Node<a>> newNode(a v) {

  return std::shared_ptr<Node<a>>(new Node<a>(v));

}



template<typename a>

void dumpTree(std::shared_ptr<Node<a>> tree) {

  if( tree.get() == nullptr ) return;

  dumpTree2(tree->left);

  dumpInfo(tree->val);

  fprintf(stderr, "[n=%d,rank=%d]", tree->n, tree->rank);

  dumpTree2(tree->right);

  fprintf(stderr, "\n");

}



template<typename a>

void dumpTree2(std::shared_ptr<Node<a>> tree) {

  if( tree.get() == nullptr ) return;

  fputc('{', stderr);

  dumpTree2(tree->left);

  dumpInfo(tree->val);

  fprintf(stderr, "[n=%d,rank=%d]", tree->n, tree->rank);

  dumpTree2(tree->right);

  fputc('}', stderr);

}



template<typename a>

void dumpArray(std::shared_ptr<Node<a>> tree) {

  if( tree.get() == nullptr ) return;

  if( tree->rank == 1 ) {

    dumpInfo(tree->val);

    return;

  }

  dumpArray2(tree->left);

  dumpArray2(tree->right);

  fprintf(stderr, "\n");

}



template<typename a>

void dumpArray2(std::shared_ptr<Node<a>> tree) {

  if( tree.get() == nullptr ) return;

  if( tree->rank == 1 ) {

    dumpInfo(tree->val);

    return;

  }

  dumpArray2(tree->left);

  dumpArray2(tree->right);

}







struct Info {

  Info() {}

  Info(int min_) : min(min_) {}

  int min;

};

Info mergeInfo(Info x, Info y) {

  return Info(std::min(x.min, y.min));

}

void dumpInfo(Info x) {

  fprintf(stderr, "[min=%d]", x.min);

}



void test() {

  AVLArray<Info> root;

  for(int i = 0; i < 200000; ++i) {

    root = merge(root, newNode(Info(1)));

  }

  printf("%d\n", root->rank);

}



AVLArray<Info> xs[212345];

int main() {

  // test();return 0;

  

  AVLArray<Info> root;

  int n, q;

  scanf("%d %d", &n, &q);    

  // for(int i = 0; i < n; ++i) {

  //   int a;

  //   scanf("%d", &a);

  //   root = merge(root, newNode(Info(a)));

  // }

  for(int i = 0; i < n; ++i) {

    int a;

    scanf("%d", &a);

    xs[i] = newNode(Info(a));

  }

  for(int d = 1; d <= 2 * n; d*=2) {

    for(int i = 0; i+d < n; i+=2*d) {

      // fprintf(stderr, "^^ : %d, %d\n", i, i + d);

      assert( xs[i].get() != nullptr and xs[i+d].get() != nullptr );

      xs[i] = merge(xs[i], xs[i+d]);

      xs[i+d] = nullptr;

    }

  }

  root = xs[0];

  // dumpArray(root);

  for(int i = 0; i < q; ++i) {

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    if( x == 0 ) {

      auto x1t = split(root, y);

      auto x2t = split(x1t.second, z - y);

      auto x3x4 = split(x2t.second, 1);

      root = merge(merge(x1t.first, x3x4.first), merge(x2t.first, x3x4.second));

    }

    if( x == 1 ) {

      auto x1t = split(root, y);

      auto x2x3 = split(x1t.second, z - y + 1);

      printf("%d\n", x2x3.first->val.min);

    }

    if( x == 2 ) {

      auto x1t = split(root, y);

      auto x2x3 = split(x1t.second, 1);

      root = merge(merge(x1t.first, newNode(Info(z))), x2x3.second);

    }

    // fprintf(stderr, "rank : %d\n", root->rank);

    // dumpArray(root);

    // fprintf(stderr, "\n");

    // dumpTree(root);

    // fprintf(stderr, "\n");

  }

  

  return 0;

}