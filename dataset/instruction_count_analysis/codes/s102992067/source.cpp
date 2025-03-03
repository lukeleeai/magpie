// 2020-07-30 18:10:26

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



const int MX = 85;

int a[MX][MX], b[MX][MX], c[MX][MX];

void answer() {

  int h, w;

  cin >> h >> w;

  rep(hi, h) rep(wi, w) {

    cin >> a[hi][wi];

  }

  rep(hi, h) rep(wi, w) {

    cin >> b[hi][wi];

  }

  rep(hi, h) rep(wi, w) c[hi][wi] = a[hi][wi] - b[hi][wi];

  int lim = 80*160*2+10;

  vector<vector<int> > dp(w+1, vector<int>(lim, 0));

  dp[0][lim/2+c[0][0]] = 1;

  dp[0][lim/2-c[0][0]] = 1;

  rep(hi, h) {

    vector<vector<int> > p(w+1, vector<int>(lim, 0));

    swap(p, dp);

    rep(wi, w) {

      int xl = lim/2-80*(hi+wi+1);

      int xr = lim/2+80*(hi+wi+1);

      REPC(x, xl, xr) {

        p[wi+1][x+c[hi][wi+1]] |= p[wi][x];

        p[wi+1][x-c[hi][wi+1]] |= p[wi][x];

        dp[wi][x+c[hi+1][wi]] |= p[wi][x];

        dp[wi][x-c[hi+1][wi]] |= p[wi][x];

      }

    }

  }

  int ans = 1e9;

  rep(x, lim) if(dp[w-1][x]) {

    chmin(ans, abs(x-lim/2));

  }

  cout << ans << '\n';

}

int main() {

  std::ios::sync_with_stdio(false);

  std::cin.tie(0);

  answer();

  return 0;

}