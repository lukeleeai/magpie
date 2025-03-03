#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(int)n;i++)

#define rep1(i,n) for(int i=1;i<=(int)n;i++)

#define sp(n) cout << fixed << setprecision(n)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;

using namespace std;

const ll mod=998244353;

struct mint {

  ll x; // typedef long long ll;

  mint(ll x=0):x((x%mod+mod)%mod){}

  mint& operator+=(const mint a) {

    if ((x += a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator-=(const mint a) {

    if ((x += mod-a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator*=(const mint a) {

    (x *= a.x) %= mod;

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



  // for prime mod

  mint inv() const {

    return pow(mod-2);

  }

  mint& operator/=(const mint a) {

    return (*this) *= a.inv();

  }

  mint operator/(const mint a) const {

    mint res(*this);

    return res/=a;

  }

};

int main(void){

    ll a,b,c,d;cin>>a>>b>>c>>d;

    vector<vector<mint>> t(c+10,vector<mint>(d+10,0));

    t[a][b]=1;

    rep(i,c+1)rep(j,d+1){

        if(i==0||j==0)continue;

        if(i<=a&&j<=b)continue;

        t[i][j]=t[i-1][j]*j+t[i][j-1]*i-t[i-1][j-1]*(i-1)*(j-1);

    }

    cout<<t[c][d].x<<endl;

}