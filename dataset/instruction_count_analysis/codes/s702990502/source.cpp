// -----------------------------------

// Author     : MatsuTaku

// Country    : Japan

// Created    : 04/26/20 20:17:32

// -----------------------------------



#include "stdc++.h"



using namespace std;

using ll = long long;



int main() {

  cin.tie(nullptr); ios::sync_with_stdio(false);



  ll n,m,s; cin>>n>>m>>s;

  struct Train {

    ll s, c, d;

    Train(ll s,ll c,ll d):s(s),c(c),d(d){}

    bool operator>(const Train& x) const {return d>x.d;}

  };

  vector<Train> graph[n];

  for (int i = 0; i < m; i++) {

    ll u,v,a,b; cin>>u>>v>>a>>b; u--; v--;

    graph[u].emplace_back(v,a,b);

    graph[v].emplace_back(u,a,b);

  }

  for (int i = 0; i < n; i++) {

    int c,d; cin>>c>>d;

    graph[i].emplace_back(i,-c,d);

  }

  constexpr ll MAX = 2500;

  constexpr ll INF = 1e18;

  vector<array<ll, MAX+1>> dp(n);

  for (auto& arr:dp) arr.fill(INF);

  dp[0][min(s,MAX)] = 0;

  priority_queue<Train, vector<Train>, greater<>> qs;

  qs.emplace(0,s,0);

  while (not qs.empty()) {

    auto [s,c,d] = qs.top(); qs.pop();

    if (d > dp[s][min(c,MAX)]) continue;

    for (auto t:graph[s]) {

      if (c-t.c<0) continue;

      if (d+t.d >= dp[t.s][min(c-t.c,MAX)]) continue;

      dp[t.s][min(c-t.c,MAX)] = d+t.d;

      qs.emplace(t.s, c-t.c, d+t.d);

    }

  }

  for (int i = 1; i < n; i++) {

    cout << *min_element(dp[i].begin(), dp[i].end()) << endl;

  }



  return 0;

}
