#include "stdc++.h"

 

#define rep(i, n)      for (int i = 0; i < (n); i++)

#define repr(i, n)     for (int i = (n) - 1; i >= 0; i--)

#define repe(i, l, r)  for (int i = (l); i < (r); i++)

#define reper(i, l, r) for (int i = (r) - 1; i >= (l); i--)

#define repi(i, l, r)  for (int i = (l); i <= (r); i++)

#define repir(i, l, r) for (int i = (r); i >= (l); i--)

#define range(a) a.begin(), a.end()

void init_io() { std::cin.tie(nullptr); std::ios::sync_with_stdio(false); std::cout << std::fixed << std::setprecision(15); }

 

using namespace std;

using ll = long long;



void chmin(ll &x, ll y) {

  x = min(x, y);

}



int main() { init_io();

  int N, K; cin >> N >> K;

  vector<int> H(N);

  rep(i, N) cin >> H[i];

  vector<int> dict(H);

  dict.push_back(0);

  sort(range(dict));

  dict.erase(unique(range(dict)), dict.end());

  rep(i, N) H[i] = lower_bound(range(dict), H[i]) - dict.begin();

  static ll dp[310][310];

  constexpr ll inf = 1e18;

  rep(j, 310) rep(k, 310) dp[j][k] = inf;

  dp[0][0] = 0;

  rep(i, N) {

    rep(j, K+1) rep(k, dict.size() - 1) {

      chmin(dp[j][k+1], dp[j][k] + dict[k+1] - dict[k]);

    }

    rep(j, K+1) reper(k, 1, dict.size()) {

      chmin(dp[j][k-1], dp[j][k]);

    }

    repr(j, K+1) rep(k, dict.size()) if (k != H[i]) {

      dp[j+1][k] = dp[j][k];

      dp[j][k] = inf;

    }

  }

  ll ans = inf;

  rep(j, K+1) rep(k, dict.size()) chmin(ans, dp[j][k]);

  cout << ans << endl;

}
