#ifdef LOCAL

//#define _GLIBCXX_DEBUG

#endif

//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;

typedef pair<int, int> Pi;

typedef vector<ll> Vec;

typedef vector<int> Vi;

typedef vector<string> Vs;

typedef vector<P> VP;

typedef vector<vector<ll>> VV;

typedef vector<vector<int>> VVi;

typedef vector<vector<vector<ll>>> VVV;

typedef vector<vector<vector<vector<ll>>>> VVVV;



#define REP(i, a, b) for(ll i=(a); i<(b); i++)

#define PER(i, a, b) for(ll i=(a); i>=(b); i--)

#define rep(i, n) REP(i, 0, n)

#define per(i, n) PER(i, n, 0)

const ll INF=1e18+18;

const ll MOD=1000000007;

#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;

#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

#define ALL(v) v.begin(), v.end()

#define rALL(v) v.rbegin(), v.rend()

#define pb(x) push_back(x)

#define mp(a, b) make_pair(a,b)

#define Each(a,b) for(auto &a :b)

#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)

#ifdef LOCAL

#define dbg(x_) cerr << #x_ << ":" << x_ << endl;

#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}

#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}

#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;

#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;

#define dbgarrmint(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j].x<<" ";}cerr<<endl;}

#else

#define dbg(...)

#define dbgmap(...)

#define dbgarr(...)

#define dbgdp(...)

#define dbgmint(...)

#define dbgarrmint(...)

#endif

#define out(a) cout<<a<<endl

#define out2(a,b) cout<<a<<" "<<b<<endl

#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl

#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())

#define fi first

#define se second



template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }



template<typename T1, typename T2>

ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }



template<typename T>istream& operator>>(istream&i,vector<T>&v)

{rep(j,v.size())i>>v[j];return i;}



// vector

template<typename T>

ostream &operator<<(ostream &s, const vector<T> &v) {

    int len=v.size();

    for(int i=0; i<len; ++i) {

        s<<v[i];

        if(i<len-1) s<<"	";

    }

    return s;

}



// 2 dimentional vector

template<typename T>

ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {

    int len=vv.size();

    for(int i=0; i<len; ++i) {

        s<<vv[i]<<endl;

    }

    return s;

}





//mint

struct mint {

    ll x; // typedef long long ll;

    mint(ll x=0):x((x%MOD+MOD)%MOD){}

    mint& operator+=(const mint a) {

        if ((x += a.x) >= MOD) x -= MOD;

        return *this;

    }

    mint& operator-=(const mint a) {

        if ((x += MOD-a.x) >= MOD) x -= MOD;

        return *this;

    }

    mint& operator*=(const mint a) {

        (x *= a.x) %= MOD;

        return *this;

    }

    mint operator+(const mint a) const {

        mint res(*this);

        return res+=a;

    }

    mint operator-(const mint a) const {

        mint res(*this);

        return res-=a;

    }

    mint operator*(const mint a) const {

        mint res(*this);

        return res*=a;

    }

    mint pow(ll t) const {

        if (!t) return 1;

        mint a = pow(t>>1);

        a *= a;

        if (t&1) a *= *this;

        return a;

    }



    // for prime MOD

    mint inv() const {

        return pow(MOD-2);

    }

    mint& operator/=(const mint a) {

        return (*this) *= a.inv();

    }

    mint operator/(const mint a) const {

        mint res(*this);

        return res/=a;

    }

};

typedef vector<mint> Vmint;



struct combination {

    vector<mint> fact, ifact;

    combination(int n):fact(n+1),ifact(n+1) {

        assert(n < MOD);

        fact[0] = 1;

        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;

        ifact[n] = fact[n].inv();

        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;

    }

    mint operator()(int n, int k) {

        if (k < 0 || k > n) return 0;

        return fact[n]*ifact[k]*ifact[n-k];

    }

};



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout<<std::setprecision(10);



    ll h,w;

    cin>>h>>w;



    Vs vs(h);

    cin>>vs;



    VV g(h,Vec(w));

    queue<P> q;



    auto in = [&](ll y, ll x) {

        return y >= 0 && y < h && x >= 0 && x < w;

    };

    Vec dx = {1,0,-1,0};

    Vec dy = {0,1,0,-1};



    rep(i,h){

        rep(j,w){

            if(vs[i][j]=='#'){

                q.push(mp(i,j));

            }

        }

    }



    while(!q.empty()){

        P now = q.front();

        q.pop();

        rep(k,4){

            ll ny = now.fi+dy[k];

            ll nx = now.se+dx[k];

            if(in(ny,nx) && vs[ny][nx]=='.'){

                vs[ny][nx] = '#';

                g[ny][nx] = g[now.fi][now.se]+1;

                q.push(mp(ny,nx));

            }

        }

    }



    ll ans = 0;

    dbg(vs);

    dbg(g);

    rep(i,h)rep(j,w)chmax(ans,g[i][j]);

    out(ans);

    return  0;

}
