#include"stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)

#define chmax(a, b) a = max(a, b)

#define chmin(a, b) a = min(a, b)

#define fi first

#define se second

#define INF 1000000009

#define LLINF 1000000000000000009LL

using ll = long long;



int main() {

  string s, t;

  cin >> s >> t;

  int n = s.size(), m = t.size();

  vector<vector<int>> is(26);

  rep(i,n) is[s[i]-'a'].push_back(i);

  rep(i,n) is[s[i]-'a'].push_back(i+n);

  ll ans = 0;

  int p = 0;

  rep(i,m) {

    int c = t[i] - 'a';

    if (is[c].size() == 0) {

      cout << -1 << endl;

      return(0);

    }

    p = *lower_bound(is[c].begin(), is[c].end(), p) + 1;

    if (p >= n) {

      p -= n;

      ans += n;

    }

  }

  ans += p;

  cout << ans << endl;

  return(0);

}
