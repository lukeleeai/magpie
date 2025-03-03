#include <algorithm>

#include <iostream>

#include <map>

#include <string>

#include <vector>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define all(x) (x).begin(), (x).end()

#define dbg(x) cerr << #x << ": " << x << endl



const int MAX_V = 200000;

vector<vector<int>> to(MAX_V);

vector<int> V, W;

vector<int> col(MAX_V);

int n;

void dfs(int v, int p, int c) {

  if(c == 0)

    V.push_back(v);

  else

    W.push_back(v);

  for(auto x : to[v]) {

    if(x == p) continue;

    dfs(x, v, 1 ^ c);

  }

  return;

}



int main() {

  cin >> n;

  to.resize(n);

  col.resize(n);

  rep(i, n - 1) {

    int a, b;

    cin >> a >> b;

    a--, b--;

    to[a].push_back(b);

    to[b].push_back(a);

  }

  dfs(0, -1, 0);

  if(V.size() < W.size()) {

    vector<int> temp = V;

    V = W;

    W = temp;

  }

  for(auto v : V) dbg(v + 1);

  for(auto w : W) dbg(w + 1);

  vector<int> col(n);

  int c[3] = {3, 1, 2};

  if(W.size() <= n / 3) {

    int iV = 0;

    rep(i, n / 3 - W.size()) {

      col[V[iV++]] = c[0];

      c[0] += 3;

    }

    rep(i, n / 3) {

      col[V[iV++]] = c[1];

      c[1] += 3;

    }

    rep(i, n / 3) {

      col[V[iV++]] = c[2];

      c[2] += 3;

    }

    if(n % 3 != 0) col[V[iV++]] = c[1];

    if(n % 3 == 2) col[V[iV++]] = c[2];



    rep(iW, W.size()) {

      col[W[iW]] = c[0];

      c[0] += 3;

    }



  } else {

    int iV = 0;

    rep(i, n / 3) {

      col[V[iV++]] = c[1];

      c[1] += 3;

    }

    if(n % 3 != 0) col[V[iV++]] = c[1];



    for(; iV < V.size(); iV++) {

      col[V[iV]] = c[0];

      c[0] += 3;

    }

    int iW = 0;

    rep(i, n / 3) {

      col[W[iW++]] = c[2];

      c[2] += 3;

    }

    if(n % 3 == 2) col[W[iW++]] = c[2];

    for(; iW < W.size(); iW++) {

      col[W[iW]] = c[0];

      c[0] += 3;

    }

  }

  rep(i, n) printf("%d%c", col[i], i == n - 1 ? '\n' : ' ');

  return 0;

}