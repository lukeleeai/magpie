#include "stdc++.h"

 

using namespace std;

 

const int INF = 1 << 30;

typedef pair< int, int > Pi;

 

struct UnionFind

{

  vector< int > data;

 

  UnionFind(int sz)

  {

    data.assign(sz, -1);

  }

 

  int find(int k)

  {

    if(data[k] < 0) return (k);

    return (data[k] = find(data[k]));

  }

 

  void unite(int a, int b)

  {

    a = find(a);

    b = find(b);

    if(a == b) return;

    if(data[a] > data[b]) swap(a, b);

    data[a] += data[b];

    data[b] = a;

  }

};

 

struct edge

{

  int to, cost;

};

 

struct edgee

{

  int u, v, cost;

 

  bool operator<(const edgee& e) const

  {

    return (cost < e.cost);

  }

};

 

int N, M, K, Q;

int A[200000], B[200000], L[200000];

vector< edge > graph[100000];

int min_cost[100000];

vector< edgee > es;

int S[100000], T[100000];

int l[100000], r[100000];

 

int main()

{

  scanf("%d %d %d %d", &N, &M, &K, &Q);

  for(int i = 0; i < M; i++) {

    scanf("%d %d %d", &A[i], &B[i], &L[i]);

    --A[i], --B[i];

    graph[A[i]].push_back((edge) {B[i], L[i]});

    graph[B[i]].push_back((edge) {A[i], L[i]});

  }

 

  priority_queue< Pi, vector< Pi >, greater< Pi > > que;

  fill_n(min_cost, N, INF);

 

  while(K--) {

    int F;

    cin >> F;

    min_cost[--F] = 0;

    que.emplace(0, F);

  }

 

  while(!que.empty()) {

    auto p = que.top();

    que.pop();

    if(min_cost[p.second] > p.first) continue;

    for(auto& e : graph[p.second]) {

      if(min_cost[e.to] > p.first + e.cost) {

        min_cost[e.to] = p.first + e.cost;

        que.emplace(min_cost[e.to], e.to);

      }

    }

  }

 

  for(int i = 0; i < M; i++) {

    es.emplace_back((edgee) {A[i], B[i], min(min_cost[A[i]], min_cost[B[i]])});

  }

  sort(begin(es), end(es));

  reverse(begin(es), end(es));

 

  UnionFind uf(M);

 

  for(int i = 0; i < Q; i++) {

    scanf("%d %d", &S[i], &T[i]);

    --S[i], --T[i];

    l[0] = -1, r[i] = M - 1;

  }

 

  for(int i = 0; i < 19; i++) {

    UnionFind tree(N);

    vector< Pi > querys;

    for(int j = 0; j < Q; j++) {

      if(r[j] - l[j] > 1) querys.emplace_back((l[j] + r[j]) >> 1, j);

    }

    sort(begin(querys), end(querys));

    int tail = 0;

    for(int j = 0; j < M; j++) {

      tree.unite(es[j].u, es[j].v);

      while(tail < querys.size() && querys[tail].first <= j) {

        int idx = querys[tail].second;

        int u = S[idx], v = T[idx];

        if(tree.find(S[idx]) == tree.find(T[idx])) {

          r[idx] = querys[tail].first;

        } else {

          l[idx] = querys[tail].first;

        }

        ++tail;

      }

    }

  }

 

  for(int i = 0; i < Q; i++) {

    printf("%d\n", es[r[i]].cost);

  }

}