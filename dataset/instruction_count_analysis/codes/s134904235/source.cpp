#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)

#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)

#define all(n) begin(n), end(n)

using ll = long long;

using P = pair<ll, ll>;

using vi = vector<int>;

using vl = vector<ll>;

using vs = vector<string>;

using vc = vector<char>;

using vb = vector<bool>;

using vd = vector<double>;

vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};



const int mod = 998244353;

struct mint {

  ll x;  // typedef long long ll;

  mint(ll x = 0) : x((x % mod + mod) % mod) {}

  mint operator-() const { return mint(-x); }

  mint& operator+=(const mint a) {

    if((x += a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator-=(const mint a) {

    if((x += mod - a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator*=(const mint a) {

    (x *= a.x) %= mod;

    return *this;

  }

  mint operator+(const mint a) const { return mint(*this) += a; }

  mint operator-(const mint a) const { return mint(*this) -= a; }

  mint operator*(const mint a) const { return mint(*this) *= a; }

  mint pow(ll t) const {

    if(!t) return 1;

    mint a = pow(t >> 1);

    a *= a;

    if(t & 1) a *= *this;

    return a;

  }

  // for prime mod

  mint inv() const { return pow(mod - 2); }

  mint& operator/=(const mint a) { return *this *= a.inv(); }

  mint operator/(const mint a) const { return mint(*this) /= a; }

};

istream& operator>>(istream& is, const mint& a) { return is >> a.x; }

ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

mint fact(int n) {

  if(n == 1 || n == 0) return 1;

  mint res = n;

  return res * fact(n - 1);

}



struct UnionFind {

  vector<int> d;

  UnionFind(int n) : d(n, -1) {}

  int root(int x) {

    if(d[x] < 0) return x;

    return d[x] = root(d[x]);

  }

  bool unite(int x, int y) {

    x = root(x);

    y = root(y);

    if(x == y) return false;

    if(d[x] > d[y]) swap(x, y);

    d[x] += d[y];

    d[y] = x;

    return true;

  }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -d[root(x)]; }

};



int main() {

  ll n;

  cin >> n;

  vector<P> p(n);

  rep(i, n) cin >> p[i].first >> p[i].second;

  sort(all(p));

  UnionFind uf(n);

  vl num(n, 0);

  for(int i = n - 1; i >= 0; i--) {

    ll x = p[i].first, d = p[i].second;

    ll l = -1, r = n;

    while(l + 1 < r) {

      ll now = (l + r) / 2;

      if(p[now].first < x + d)

        l = now;

      else

        r = now;

    }

    rep2(j, i + 1, l + 1) {

      int nj = j + uf.size(j) - 1;

      uf.unite(i, j);

      j = nj;

    }

    num[n - i - 1] = uf.size(i) - 1;

  }

  vector<mint> dp(n + 1, 0);

  dp[0] = 1;

  rep(i, n) dp[i + 1] = dp[i] + dp[i - num[i]];

  cout << dp[n] << endl;

}