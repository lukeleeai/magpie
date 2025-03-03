#include "stdc++.h"



using namespace std;



#define rep(i, a, b) for (int i = (a); i <= (b); i++)

#define pb push_back

#define fi first

#define se second

typedef long long ll;

const int N = 2e5 + 100;



inline ll rd() {

  ll s = 0, w = 1; char c = getchar();

  while (c < '0' || c > '9') { if (c == '-') w = -1; c = getchar(); }

  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();

  return s * w;

}



ll n, k, a[N], fst[N], tot, pos;

pair <ll, ll> p[N];

vector <ll> r[N], ans;



inline void calc() {

  rep(i, 1, N - 100) {

    if (!r[i].size()) continue ; int len = r[i].size();

    rep(j, 0, len - 1) {

      if (j != len - 1)

        p[r[i][j]].fi = (r[i][j + 1] + 1) % n,

        p[r[i][j]].se = r[i][j + 1] + 1 - r[i][j];

      else

        p[r[i][j]].fi = (r[i][0] + 1) % n,

        p[r[i][j]].se = n - r[i][j] + r[i][0] + 1;

    }

  }

}



int main() {

  n = rd(), k = rd(); memset(fst, -1, sizeof(fst));

  rep(i, 0, n - 1) r[a[i] = rd()].pb(i);

  calc(); tot = pos = 0; ll s = n * k - 1;

  while (tot + p[pos].se <= s) {

    if (fst[pos] != -1) {

      ll K = tot - fst[pos], h = (n * k - fst[pos]) % K;

      if (h == 1ll) { puts(""); return 0; }

      h = (!h ? K - 1 : h - 1);

      s =  fst[pos] + h, tot = fst[pos];

      break ;

    }

    else fst[pos] = tot;

    tot += p[pos].se, pos = p[pos].fi;

  }

  if (s == tot + p[pos].se - 1) { puts(""); return 0; }

  while (tot <= s) {

    while (tot + p[pos].se <= s) tot += p[pos].se, pos = p[pos].fi;

    if (tot + p[pos].se - 1 == s) break ;

    ans.pb(a[pos]), (++pos) %= n, tot++;

  }

  int len = ans.size(); if (!len) puts("");

  else {

    rep(i, 0, len - 1) printf("%lld ", ans[i]);

    puts("");

  }

  return 0;

}