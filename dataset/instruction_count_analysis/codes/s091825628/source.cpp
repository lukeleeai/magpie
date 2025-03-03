#include "stdc++.h"

using namespace std;



static const int MAX = 300000;

static const int INF = 1e9;



// 隣接リストを用いた幅優先探索 O(|V|+|E|)

vector<int> G[MAX], d(MAX, INF); // 始点sから頂点iまでの最短距離をd[i]に記録

// main関数からこれらを削除すること



void bfs(int s) {

  queue<int> q;

  q.push(s);

  d[s] = 0;

  while (!q.empty()) {

    int u = q.front();

    q.pop();

    for (int v = 0; v < G[u].size(); v++) {

      if (d[G[u][v]] == INF) {

        d[G[u][v]] = d[u] + 1;

        q.push(G[u][v]);

      }

    }

  }

}



int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);

  

  // 無向(有向)グラフの隣接リスト

  int n, m; // n:頂点数 m:辺数

  cin >> n >> m;

  

  // vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト

  

  int u, v;

  for (int i = 0; i < m; i++) {

    cin >> u >> v;

    u--;

    v--;

    G[u].emplace_back(v + 100000);

    G[u + 100000].emplace_back(v + 200000);

    G[u + 200000].emplace_back(v);

  }

  

  int s, t;

  cin >> s >> t;

  s--;

  t--;

  

  bfs(s);

  

  if (d[t] == INF) cout << "-1\n";

  else cout << d[t] / 3 << '\n';

}