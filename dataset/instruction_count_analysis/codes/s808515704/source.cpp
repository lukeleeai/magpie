#include "stdc++.h"

#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)

#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)

#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)

#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)

#define pb push_back

#define eb emplace_back

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define popcount __builtin_popcount

using ll = long long;

constexpr ll mod = 1e9 + 7;

constexpr ll INF = 1LL << 60;



template <class T>

inline bool chmin(T &a, T b)

{

	if (a > b)

	{

		a = b;

		return true;

	}

	return false;

}

template <class T>

inline bool chmax(T &a, T b)

{

	if (a < b)

	{

		a = b;

		return true;

	}

	return false;

}



ll gcd(ll n, ll m)

{

	ll tmp;

	while (m != 0)

	{

		tmp = n % m;

		n = m;

		m = tmp;

	}

	return n;

}



ll lcm(ll n, ll m)

{

	return abs(n) / gcd(n, m) * abs(m); //gl=xy

}



using namespace std;



template< int mod >

struct ModInt {

  int x;



  ModInt() : x(0) {}



  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}



  ModInt &operator+=(const ModInt &p) {

    if((x += p.x) >= mod) x -= mod;

    return *this;

  }



  ModInt &operator-=(const ModInt &p) {

    if((x += mod - p.x) >= mod) x -= mod;

    return *this;

  }



  ModInt &operator*=(const ModInt &p) {

    x = (int) (1LL * x * p.x % mod);

    return *this;

  }



  ModInt &operator/=(const ModInt &p) {

    *this *= p.inverse();

    return *this;

  }



  ModInt operator-() const { return ModInt(-x); }



  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }



  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }



  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }



  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }



  bool operator==(const ModInt &p) const { return x == p.x; }



  bool operator!=(const ModInt &p) const { return x != p.x; }



  ModInt inverse() const {

    int a = x, b = mod, u = 1, v = 0, t;

    while(b > 0) {

      t = a / b;

      swap(a -= t * b, b);

      swap(u -= t * v, v);

    }

    return ModInt(u);

  }



  ModInt pow(int64_t n) const {

    ModInt ret(1), mul(x);

    while(n > 0) {

      if(n & 1) ret *= mul;

      mul *= mul;

      n >>= 1;

    }

    return ret;

  }



  friend ostream &operator<<(ostream &os, const ModInt &p) {

    return os << p.x;

  }



  friend istream &operator>>(istream &is, ModInt &a) {

    int64_t t;

    is >> t;

    a = ModInt< mod >(t);

    return (is);

  }



  static int get_mod() { return mod; }

};



using modint = ModInt< mod >;





template< typename T >

struct Combination {

  vector< T > _fact, _rfact, _inv;



  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {

    _fact[0] = _rfact[sz] = _inv[0] = 1;

    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;

    _rfact[sz] /= _fact[sz];

    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);

    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];

  }



  inline T fact(int k) const { return _fact[k]; }



  inline T rfact(int k) const { return _rfact[k]; }



  inline T inv(int k) const { return _inv[k]; }



  T P(int n, int r) const {

    if(r < 0 || n < r) return 0;

    return fact(n) * rfact(n - r);

  }



  T C(int p, int q) const {

    if(q < 0 || p < q) return 0;

    return fact(p) * rfact(q) * rfact(p - q);

  }



  T H(int n, int r) const {

    if(n < 0 || r < 0) return (0);

    return r == 0 ? 1 : C(n + r - 1, r);

  }

};



void solve()

{

	ll n;

	cin>>n;

	ll ans=0;

	for(ll i=1;i<=n;++i){

		ll x=n/i;

		ll l=n/(x+1)+1,r=n/x;

		ll val=((l+r)*(r-l+1))/2;

		ans+=((1+x)*x*val)/2;

		i=r;

	}

	cout<<ans;

}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout << fixed << setprecision(15);

	solve();

	return 0;

}
