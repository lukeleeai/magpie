#include "stdc++.h"

using namespace std;



#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)

#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)

#define REP(i, n) rep(i, 0, n)

#define REP2(i, n) rep2(i, 0, n)

#define all(hoge) (hoge).begin(), (hoge).end()

#define en '\n'

using ll = long long;

using ull = unsigned long long;

template <class T>

using vec = vector<T>;

template <class T>

using vvec = vector<vec<T>>;

typedef pair<ll, ll> P;

constexpr long long INF = 1LL << 60;

constexpr int INF_INT = 1 << 25;

constexpr long long MOD = (ll)1e9 + 7;

// constexpr long long MOD = 998244353LL;

using ld = long double;

static const ld pi = 3.141592653589793L;

typedef vector<ll> Array;

typedef vector<Array> Matrix;



template <class T>

inline bool chmin(T &a, T b) {

    if(a > b) {

        a = b;

        return true;

    }

    return false;

}

template <class T>

inline bool chmax(T &a, T b) {

    if(a < b) {

        a = b;

        return true;

    }

    return false;

}



struct Edge {

    ll to, rev;

    long double cap;

    Edge(ll _to, long double _cap, ll _rev) {

        to = _to;

        cap = _cap;

        rev = _rev;

    }

};

using Edges = vector<Edge>;

using Graph = vector<Edges>;



void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,

              long double revCap) {

    G[from].push_back(Edge(to, cap, (ll)G[to].size()));

    if(revFlag)

        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));

}



ll mod_pow(ll x, ll n, ll mod) {

    ll res = 1LL;

    while(n > 0) {

        if(n & 1)

            res = res * x % mod;

        x = x * x % mod;

        n >>= 1;

    }

    return res;

}



ll mod_inv(ll x, ll mod) {

    return mod_pow(x, mod - 2, mod);

}



//ラグランジュ補間(d+1)点をとおるd次式を求める

ll LagrangeInterpolation(vector<ll> y, ll t) {

    int n = y.size() - 1;

    if(t <= n)

        return y[t];

    ll fi = 1, ft = 1;

    for(ll i = 0; i <= n; i++) {

        if(i)

            (fi *= MOD - i) %= MOD;

        (ft *= t - i) %= MOD;

    }

    ll ret = 0;

    for(ll i = 0; i <= n; i++) {

        (ret += y[i] * ft % MOD * mod_inv(t - i, MOD) % MOD * mod_inv(fi, MOD) % MOD) %= MOD;

        (fi *= (i + 1) * mod_inv(MOD - n + i, MOD) % MOD) %= MOD;

    }

    return ret;

}



ll nCr(int n, int r) {

    if(n < r)

        return 0;



    ll ret = 1;

    REP(i, r) {

        (ret *= n - i) %= MOD;

        (ret *= mod_inv(i + 1, MOD)) %= MOD;

    }

    return ret;

}



ll f(int n) {

    ll ret = 0;

    REP(i, (n - 5) / 2 + 1) {

        ret += nCr(i + 4, 4) * nCr(n - 2 * i + 5, 10) % MOD;

        ret %= MOD;

    }

    return ret;

}



void solve() {

    ll n;

    cin >> n;



    if(n < 5) {

        cout << 0 << en;

        return;

    }



    vec<ll> y(16); //15次式になるので16点取れば十分

    REP(i, 16) {

        y[i] = f(2 * i + 5 + (n - 5) % 2);

    }

    cout << LagrangeInterpolation(y, (n - 5) / 2) << en;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    ll t;

    cin >> t;

    while(t--)

        solve();



    return 0;

}
