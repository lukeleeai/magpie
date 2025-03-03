#include "stdc++.h"

#define REP(i,s,e) for(int i=(s); i<(e);i++)

#define rep(i,n) REP(i,0,n)

#define rep1(i,n) REP(i,1,n)

#define repe(i,n) for(auto &&i:n)

#define all(v) (v).begin(),(v).end()

#define decimal fixed<<setprecision(20)

#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

//#define int long long

using LL = long long;

using namespace std;

using Graph = vector<vector<int>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

const LL LLINF = 1e16;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};



// うしさんのライブラリを少し改造した

template<int mod>

struct ModInt {

    int x;



    ModInt() : x(0) {}

    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}



    ModInt &operator+=(const ModInt &p) {

        if((x += p.x) >= mod) x -= mod;

        return *this;

    }

    ModInt &operator-=(const ModInt &p) {

        if((x += mod - p.x) >= mod) x -= mod;

        return *this;

    }

    ModInt &operator*=(const ModInt &p) {

        x = (int)(1LL * x * p.x % mod);

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



    ModInt inverse() const{

        int a = x, b = mod, u = 1, v = 0, t;

        while(b > 0) {

            t = a / b;

            a -= t * b;

            swap(a, b);

            u -= t * v;

            swap(u, v);

        }

        return ModInt(u);

    }



    ModInt pow(int e){

        long long a = 1, p = x;

        while(e > 0) {

            if(e%2 == 0) {p = (p*p) % mod; e /= 2;}

            else {a = (a*p) % mod; e--;}

        }

        return ModInt(a);

    }



    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {

        return os << p.x;

    }

    friend istream &operator>>(istream &is, ModInt<mod> &a) {

        long long x;

        is >> x;

        a = ModInt<mod>(x);

        return (is);

    }

};



const int mod = 2019;

using modint = ModInt<mod>;



modint fact[200010];



modint nCr(int n, int r){

    return fact[n]/(fact[n-r]*fact[r]);

}



// 初期化

// fact[0] = 1; rep(i, 200001) fact[i] = (fact[i-1] * i);



modint dp[202020];



signed main(){

    fastcin();



    string s;

    cin >> s;



    int n = s.size();

    reverse(all(s));

    rep(i, n){

        int x = s[i]-'0';

        dp[i+1] = dp[i] + modint(10).pow(i)*x;

        // cout << dp[i+1] << endl;

    }

    map<int, int> mp;

    rep(i, n+1){

        mp[dp[i].x]++;

    }

    LL ans = 0;

    rep(i, 2019){

        ans += mp[i]*(mp[i]-1)/2;

    }

    cout << ans << endl;

}