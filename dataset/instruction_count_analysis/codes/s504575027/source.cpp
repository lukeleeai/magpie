#include "stdc++.h"



using namespace std;



template< typename T >

struct edge

{

  int src, to;

  T cost;



  edge(int to, T cost) : src(-1), to(to), cost(cost) {}



  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}



  operator int() const { return to; }

};



template< typename T >

using Edges = vector< edge< T > >;

template< typename T >

using WeightedGraph = vector< Edges< T > >;

using UnWeightedGraph = vector< vector< int > >;

template< typename T >

using Matrix = vector< vector< T > >;





template< typename T >

pair< int, int > dfs(const WeightedGraph< T > &g, int idx, int par)

{

  pair< T, int > ret(0, idx);

  for(auto &e : g[idx]) {

    if(e.to == par) continue;

    auto cost = dfs(g, e.to, idx);

    cost.first += e.cost;

    ret = max(ret, cost);

  }

  return ret;

}



template< typename T >

T tree_diameter(const WeightedGraph< T > &g)

{

  auto p = dfs(g, 0, -1);

  auto q = dfs(g, p.second, -1);

  return (q.first);

}



int main()

{

  int V;

  scanf("%d", &V);

  WeightedGraph< int > g(V);

  for(int i = 0; i < V - 1; i++) {

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    g[x].emplace_back(y, z);

    g[y].emplace_back(x, z);

  }

  cout << tree_diameter(g) << endl;

}






