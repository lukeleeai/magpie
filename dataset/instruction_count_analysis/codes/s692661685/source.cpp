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



void solve() {

    ll n;

    cin >> n;



    if(n < 5) {

        cout << 0 << en;

        return;

    }



    n -= 5;

    ll ans = 0;

    REP(i, 12) {

        if(n < i or (n - i) % 2)

            continue;

        //2個セットで分割

        //奇数にしてもいい11区間のうちi箇所を奇数にする

        ans += nCr((n - i) / 2 + 15, 15) * nCr(11, i) % MOD;

        ans %= MOD;

    }

    cout << ans << en;

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
