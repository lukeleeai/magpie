#include "stdc++.h"

#define rep(i,n) for (int i = 0; i < (int)(n); i++)

#define REP(i,n) for (int i = 1; i < (int)(n); i++)

#define all(x) x.begin(),x.end()

#define rall(x) x.rbegin(),x.rend()

#define debug(var) do{cout << #var << " : "; view(var);}while(0)

template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}

template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}

using namespace std;

template<class T> void view(T e) {cout << e << endl;}

template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}

template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}

using vint = vector<int>;

using vvint = vector<vector<int>>;

using ll = long long;

using vll = vector<ll>;

using vvll = vector<vector<ll>>;

using P = pair<int,int>;

const int inf = 1<<31;

const ll inf_l = 1LL<<61;

const int MAX = 1e5;



const int mod = 1e9+7;

struct mint {

    ll x;

    mint (ll x = 0) : x((x%mod+mod)%mod) {}

    mint operator -() const {return mint(-x);}

    mint& operator +=(const mint a) {

        if ((x += a.x) >= mod) x -= mod;

        return *this;

    }

    mint& operator -=(const mint a) {

        if ((x += mod-a.x) >= mod) x -= mod;

        return *this;

    }

    mint& operator *=(const mint a) {(x *= a.x) %= mod; return *this;}

    mint operator +(const mint a) const {return mint(*this) += a;}

    mint operator -(const mint a) const {return mint(*this) -= a;}

    mint operator *(const mint a) const {return mint(*this) *= a;}

    mint pow(ll t) const {

        if (!t) return 1;

        mint a = pow(t>>1);

        a *= a;

        if (t&1) a *= *this;

        return a;

    }

    mint inv() const {return pow(mod-2);}

    mint operator /=(const mint a) {return *this *= a.inv();}

    mint operator /(const mint a) {return mint(*this) /= a;}

};

istream& operator >>(istream &is, const mint &a) {return is >> a.x;}

ostream& operator <<(ostream &os, const mint &a) {return os << a.x;}



struct combination {

    vector<mint> fact, ifact;

    combination(int n) : fact(n+1), ifact(n+1) {

        assert(n < mod);

        fact[0] = 1;

        for (int i = 1; i <= n; i++) fact[i] = fact[i-1]*i;

        ifact[n] = fact[n].inv();

        for (int i = n; i >= 1; i--) ifact[i-1] = ifact[i]*i;

    }

    mint operator()(int n, int k) {

        if (k < 0 || k > n) return 0;

        return fact[n]*ifact[k]*ifact[n-k];

    }

}; 



int main() {

    int s; cin >> s;

    combination cm(4005);

    mint ans = 0;

    for (int n = 1; n <= s/3; n++) {

        ans += cm(s-3*n+n-1,n-1);

    }

    cout << ans << endl;

}