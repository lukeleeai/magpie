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



static vector<mint> mfact(1, 1); // n! (mod MOD)

mint nPr(int n, int r) {

  if (n < 0 || r < 0 || n < r) return 0;

  if (r == 0) return 1;

  int pn = mfact.size();

  if (pn < n + 1) {

    mfact.resize(n + 1);

    for (int i = pn; i <= n; i++) mfact[i] = mfact[i - 1] * i;

  }

  return mfact[n] * mfact[n - r].inv();

}

mint nCr(int n, int r) {

  if (n < 0 || r < 0 || n < r) return 0;

  if (r == 0) return 1;

  int pn = mfact.size();

  if (pn < n + 1) {

    mfact.resize(n + 1);

    for (int i = pn; i <= n; i++) mfact[i] = mfact[i - 1] * i;

  }

  return mfact[n] * mfact[r].inv() * mfact[n - r].inv();

}



void solve() {

  int n, m;

  cin >> n >> m;

  mint ans = 1;

  map<ll, int> prime;

  for (ll i = 2; i * i <= m; i++) {

    while (m % i == 0) {

      prime[i]++;

      m /= i;

    }

  }

  if (m != 1) prime[m] = 1;

  for (auto p : prime) {

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