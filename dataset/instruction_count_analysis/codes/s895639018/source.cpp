#include"stdc++.h"

using namespace std;

using ll = long long;



vector<int> g[212345];



int main() {

  std::ios::sync_with_stdio(false), std::cin.tie(0);

  int n, m; cin>>n>>m;

  string s;

  cin >> s;

  for(int i = 0; i < m; i++) {

    int a, b;

    cin >> a >> b; a--; b--;

    g[a].push_back(b);

    g[b].push_back(a);

  }

  vector<int> ok(n, 1);

  // vector<int> used(n);

  // int col = 1;

  function<void(int)> check = [&](int i) {

    if(!ok[i]) return;

    int f[2] = {};

    for(int j : g[i]) {

      if(ok[j]) f[s[j] == 'A']++;

    }

    if(!(f[0] && f[1])) ok[i] = 0;

    if(!ok[i]) {

      auto newg = g[i];

      for(int j : g[i]) {

        if(!ok[j]) continue;

        check(j);

        if(ok[j]) newg.push_back(j);

      }

      g[i] = newg;

    }

  };

  for(int i = 0; i < n; i++) check(i);

  cout << (find((ok).begin(), (ok).end(), 1) != ok.end() ? "Yes" : "No") << endl;

  return 0;

}
