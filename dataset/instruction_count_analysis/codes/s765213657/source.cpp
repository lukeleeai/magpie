#include "stdc++.h"

using namespace std;



#ifdef LOCAL

#include "dump.hpp"

#else

#define dump(...)

#define dumpv(...)

#endif



#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

typedef pair<int, int> P;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ll> vl;

typedef vector<vl> vvl;

const int MOD = 1e9 + 7;

const int INF = 1001001001;

const ll LINF = 1001002003004005006ll;



struct mint {

  ll v;

  mint() : v(0) {}

  mint(ll v) : v((v % MOD + MOD) % MOD) {}

  mint pow(ll t) const;

  mint inv() const;

};

mint& operator+=(mint& a, mint b) { return a = a.v + b.v; }

mint& operator-=(mint& a, mint b) { return a = a.v - b.v; }

mint& operator*=(mint& a, mint b) { return a = a.v * b.v; }

mint operator+(mint a, mint b) { return a += b; }

mint operator-(mint a, mint b) { return a -= b; }

mint operator*(mint a, mint b) { return a *= b; }

mint operator-(mint a) { return 0 - a; }

mint& operator/=(mint& a, mint b) { return a *= b.inv(); }

mint operator/(mint a, mint b) { return a /= b; }

mint mint::pow(ll t) const {

  if (!t) return 1;

  mint a = pow(t >> 1);

  a *= a;

  if (t & 1) a *= *this;

  return a;

}

mint mint::inv() const { return pow(MOD - 2); }

bool operator==(mint a, mint b) { return a.v == b.v; }

bool operator!=(mint a, mint b) { return a.v != b.v; }

istream& operator>>(istream& os, mint& a) { return (os >> a.v); }

ostream& operator<<(ostream& os, const mint& a) { return (os << a.v); }



struct mcount {

  vector<mint> fact;  // n! (mod MOD)

  vector<mint> ifact; // k!^{M-2} (mod MOD)

  mcount(int n) : fact(n + 1), ifact(n + 1) {

    fact[0] = 1;

    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

    ifact[n] = fact[n].inv();

    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;

  }

  mint perm(int n, int k) { // nPk (mod MOD)

    if (k < 0 || n < k) return 0;

    return fact[n] * ifact[n - k];

  }

  mint comb(int n, int k) { // nCk (mod MOD)

    dump(n, k);

    if (k < 0 || n < k) return 0;

    return fact[n] * ifact[k] * ifact[n - k];

  }

};



mint nCr(int n, int k) {

  static vector<mint> fact(1, 1); // n! (mod MOD)

  if (k < 0 || n < k) return 0;

  int pn = fact.size();

  if (pn < n + 1) {

    fact.resize(n + 1);

    for (int i = pn; i <= n; i++) fact[i] = fact[i - 1] * i;

  }

  return fact[n] * fact[k].inv() * fact[n - k].inv();

}



// mint nCr(int n, int r) {

//   if (n < 0 || r < 0 || n < r) return 0;

//   if (r == 0) return 1;

//   if (r > n - r) r = n - r;

//   return (nCr(n - 1, r - 1) + nCr(n - 1, r));

// }



void solve() {

  int n, m;

  cin >> n >> m;

  mint ans = 1;

  map<ll, int> prime;

  mcount mc(100050);

  for (ll i = 2; i * i <= m; i++) {

    while (m % i == 0) {

      prime[i]++;

      m /= i;

    }

  }

  if (m != 1) prime[m] = 1;

  for (auto p : prime) {

    // ans *= mc.comb(n + p.second - 1, n - 1);

    ans *= nCr(n + p.second - 1, n - 1);

  }

  cout << ans << endl;

}



int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(15);

  // freopen("temp.1", "r", stdin);

  solve();

  return 0;

}