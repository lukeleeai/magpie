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



mint dp[700][2005];



int main() {

    int s; cin >> s;

    for (int j = 3; j <= s; j++) {

        dp[1][j] = 1;

    }

    for (int i = 2; i <= s/3; i++) {

        for (int j = 3*i; j <= s; j++) {

            dp[i][j] = dp[i][j-1] + dp[i-1][j-3];

        }

    }

    mint ans = 0;

    REP(i,s/3+1) ans += dp[i][s];

    cout << ans << endl;

}