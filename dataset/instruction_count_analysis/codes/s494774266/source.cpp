#include "stdc++.h"

using namespace std;



using ll = long long;



int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);

  

  // 無向(有向)グラフの隣接リスト

  int n, m; // n:頂点数 m:辺数

  cin >> n >> m;

  

  vector<vector<int>> G(n); // G:頂点数nのグラフの隣接リスト

  

  for (int i = 0; i < m; i++) {

    int u, v;

    cin >> u >> v;

    u--;

    v--;

    G[u].emplace_back(v);

  //G[v].emplace_back(u); // 有向グラフではコメントアウト

  }

  

  int s, t;

  cin >> s >> t;

  s--;

  t--;

  

  vector<vector<int>> dp(n, vector<int>(3, 1e9));

  dp.at(s).at(0) = 0;

  queue<pair<int, int>> q;

  q.push(make_pair(s, 0));

  while (!q.empty()) {

    pair<int, int> p = q.front();

    q.pop();

    for (int i = 0; i < G[p.first].size(); i++) {

      if (dp.at(G[p.first][i]).at((p.second + 1) % 3) <= dp.at(p.first).at(p.second) + 1) continue;

      dp.at(G[p.first][i]).at((p.second + 1) % 3) = dp.at(p.first).at(p.second) + 1;

      q.push(make_pair(G[p.first][i], (p.second + 1) % 3));

    }

  }

  

  if (dp.at(t).at(0) == 1e9) cout << "-1\n";

  else cout << dp.at(t).at(0) / 3 << '\n';

}