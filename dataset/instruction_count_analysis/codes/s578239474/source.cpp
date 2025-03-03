#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(int)n;i++)

#define rep1(i,n) for(int i=1;i<=(int)n;i++)

#define sp(n) cout << fixed << setprecision(n)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;

using namespace std;

const ll mod = 998244353;

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

    int a,b,c,d;cin>>a>>b>>c>>d;

    vector<vector<mint>> dp(c+100,vector<mint>(d+100,0));

    dp[a][b]=1;

    for(int i=0;i<c;i++){

        for(int j=0;j<d;j++){

            dp[i+1][j+1]+=dp[i+1][j]*(i+1)+dp[i][j+1]*(j+1)-dp[i][j]*i*j;

        }

    }

    cout<<dp[c][d].x<<endl;

}