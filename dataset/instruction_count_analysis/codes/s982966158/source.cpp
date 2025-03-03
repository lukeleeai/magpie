#include "stdc++.h"

#define REP(i, s, e) for(int i = (int)(s); i < (int)(e); ++i)

#define rep(i, n) REP(i, 0, n)

using namespace std;

using ll = long long int;

int main() {

  int n, m;

  while(cin >> n >> m) {

    if(n == 0 && m == 0) break;

    vector<ll> x(n), y(m);

    rep(i, n) cin >> x[i];

    rep(i, m) cin >> y[i];

    REP(i, 1, n) x[i] += x[i-1];

    REP(i, 1, m) y[i] += y[i-1];

    map<ll, int> X, Y;

    rep(i, n) X[x[i]]++;

    rep(i, m) Y[y[i]]++;

    rep(i, n) rep(j, i) X[x[i] - x[j]]++;

    rep(i, m) rep(j, i) Y[y[i] - y[j]]++;

    ll ans = 0LL;

    for(auto&& p : X) {

      ans += p.second * Y[p.first];

    }

    cout << ans << endl;

  }

  return 0;

}


