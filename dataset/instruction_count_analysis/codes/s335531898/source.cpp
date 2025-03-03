#include "stdc++.h"

#define rep(i, n) for(int i = 0; i < (n); i++)

#define int long long

#define double long double

#define all(a) a.begin(), a.end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;



const int mod = 1000000007;

struct mint{ //modint

    int x;

    mint(int x = 0): x(x % mod) {}

    friend istream& operator >> (istream &s, mint& m){ return s >> m.x; }

    friend ostream& operator << (ostream &s, mint m){ return s << m.x; }

    inline mint& operator += (mint a){ if((x += a.x) >= mod)x -= mod; return *this; }

    inline mint& operator -= (mint a){ if((x += mod - a.x) >= mod)x -= mod; return *this; }

    inline mint& operator *= (mint a){ (x *= a.x) %= mod; return *this; }

    inline mint& operator /= (mint a){ return(*this) *= a.inv(); }

    inline mint operator + (mint a){ mint res(*this); return res += a; }

    inline mint operator - (mint a){ mint res(*this); return res -= a; }

    inline mint operator * (mint a){ mint res(*this); return res *= a; }

    inline mint operator / (mint a){ mint res(*this); return res /= a; }

    inline bool operator == (mint a){ return x == a.x; }

    inline bool operator != (mint a){ return x != a.x; }

    inline bool operator < (mint a){ return x < a.x; }

    inline bool operator > (mint a){ return x > a.x; }

    inline bool operator <= (mint a){ return x <= a.x; }

    inline bool operator >= (mint a){ return x >= a.x; }

    inline void takemod(){ x = ((x % mod) + mod) % mod; }

    mint inv(){ return pow(mod - 2); }

    mint pow(int p){

        mint res(1), tmp(x);

        for(; p; p >>= 1){ if(p & 1)res *= tmp; tmp *= tmp; }

        return res;

    }

};



struct mfact{ //modfact

    vector<mint> fact;

    mfact(int size = 200010){

        fact = vector<mint>(size + 1); fact[0] = 1;

        rep(i, size)fact[i + 1] = fact[i] * (i + 1);

    }

    inline mint operator [] (int i){ return fact[i]; }

    inline mint nPr(int n, int r){ return fact[n] / fact[r]; }

    inline mint nCr(int n, int r){ return fact[n] / (fact[n - r] * fact[r]); }

};



signed main(void){

    

    int N; cin >> N;

    vector<int> a(N);

    rep(i, N)cin >> a[i];



    vector<mint> vec(N + 1);

    rep(i, N){

        vec[i + 1] = vec[i] + mint(i + 1).inv();

    }



    mint fact = mfact(100010).fact[N];

    mint ans(0);

    rep(i, N){

        mint tmp = (vec[i + 1] + vec[N - i] - mint(1));

        ans += tmp * mint(a[i]) * fact;

    }



    cout << ans << endl;

    return 0;



}