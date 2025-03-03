#include "stdc++.h"



using namespace std;



struct edge

{

  int to, cost;

};



vector< edge > g[100000];

long long dist[100000];





void dfs1(int idx, int par)

{

  for(edge &e : g[idx]) {

    if(e.to == par) continue;

    dfs1(e.to, idx);

    dist[idx] = max(dist[idx], dist[e.to] + e.cost);

  }

}



int dfs2(int idx, int d_par, int par)

{

  vector< pair< int, int > > d_child;

  for(edge &e : g[idx]) {

    if(e.to == par) d_child.emplace_back(d_par + e.cost, e.to);

    else d_child.emplace_back(e.cost + dist[e.to], e.to);

  }

  sort(d_child.rbegin(), d_child.rend());

  int ret = d_child[0].first;

  for(edge &e : g[idx]) {

    if(e.to == par) continue;

    ret = max(ret, dfs2(e.to, d_child[d_child[0].second == e.to].first, idx));

  }

  return (ret);

}



int main()

{

  int N;

  cin >> N;

  for(int i = 0; i < N - 1; i++) {

    int a, b, w;

    cin >> a >> b >> w;

    g[a].push_back((edge) {b, w});

    g[b].push_back((edge) {a, w});

  }



  if(N == 1) {

    cout << 0 << endl;

  } else if(N == 2) {

    cout << g[0][0].cost << endl;

  } else {

    int root = 0;

    for(int i = 0; i < N; i++) if(g[i].size() >= 2) root = i;

    dfs1(root, -1);

    cout << dfs2(root, 1333, 1333) << endl;

  }

}