#include "stdc++.h"

using namespace std;

using ll = long long;

using PII = pair<int, int>;

using VI = vector<int>;



const int N = 2e5 + 100;

VI val[N];



struct DSU {

  VI sz, par;

  DSU(int n) {

    par.resize(n);

    iota(par.begin(), par.end(), 0);

    sz.resize(n, 1);

  }

  int find(int u) {

    if (par[u]  == u) return u;

    return par[u] = find(par[u]);

  }

  void merge(int u, int v) {

    u = find(u), v = find(v);

    if (u != v) {

      par[u] = v;

      sz[v] += sz[u];

    }

  }

  int get(int u) {

    return sz[find(u)];

  }

};



int main() {

#ifdef LOCAL_EXEC

//	freopen("sample.in", "r", stdin);

//	freopen("sample.out", "w", stdout);

#else

  ios_base::sync_with_stdio(false); cin.tie(NULL);

#endif



  int n; cin >> n;

  int m; cin >> m;

  for (int i = 0; i < n; i++) {

    int sz; cin >> sz;

    while (sz--) {

      int x; cin >> x;

      val[x].push_back(i);

    }

  }

  DSU dsu(N + 100);

  for (int x = 1; x <= m; x++) {

    for (int i: val[x]) {

      dsu.merge(i, val[x][0]);

    }

  }

  if (dsu.get(0) == n) {

    cout << "YES\n";

  } else {

    cout << "NO\n";

  }



  return 0;

}
