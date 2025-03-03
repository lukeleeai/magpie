// 2020-07-30 20:29:20

#include"stdc++.h"

#ifdef LOCAL

#include "lib/debug.hpp"

#else

#define debug(...) 1

#endif

#define ALL(a) (a).begin(), (a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define rep(i, n) REP(i, 0, (n))

#define repc(i, n) REPC(i, 0, (n))

#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)

#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)

#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)

using namespace std;

using ll = long long;

using ld = long double;

using pr = pair<ll, ll>;

using vll = vector<ll>;

using vpr = vector<pr>;

using P = pair<int, int>;

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }



const int lim = 80*160*2+10;

using bs = bitset<lim>;

void answer() {

  int h, w;

  cin >> h >> w;

  vector<vector<int> > c(h+1, vector<int>(w+1, 0));

  rep(i, h) rep(j, w) cin >> c[i][j];

  rep(i, h) rep(j, w) {

    int b;

    cin >> b;

    c[i][j] = abs(b-c[i][j]);

  }

  vector<bs> dp(w+1, bs());

  dp[0][lim/2+c[0][0]] = 1;

  dp[0][lim/2-c[0][0]] = 1;

  rep(i, h) {

    vector<bs> p(w+1, bs());

    swap(p, dp);

    rep(j, w) {

      p[j+1] |= p[j] << c[i][j+1];

      p[j+1] |= p[j] >> c[i][j+1];

      dp[j] |= p[j] << c[i+1][j];

      dp[j] |= p[j] >> c[i+1][j];

    }

  }

  int ans = lim;

  rep(x, lim) if(dp[w-1][x]) chmin(ans, abs(lim/2-x));

  cout << ans << '\n';

}

int main() {

  std::ios::sync_with_stdio(false);

  std::cin.tie(0);

  answer();

  return 0;

}