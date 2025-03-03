#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<stack>

#include<map>

#include<set>

#include<bitset>

#include<functional>

#include<assert.h>

#include<numeric>

using namespace std;

typedef pair<int,int> P;

typedef long long ll;

typedef long double ld;

const int inf=1e9+7;

const ll longinf=1LL<<60;

#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )

#define rep(i,n) REP(i,0,n)

#define F first

#define S second

constexpr char ln = '\n';



const int mx=200010;

const ll mod=1e9+7;



struct mint {

    ll x; // typedef long long ll;

    mint(ll x=0):x((x%mod+mod)%mod){}

    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }

    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }

    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }

    mint operator+(const mint a) const { mint res(*this); return res+=a; }

    mint operator-(const mint a) const { mint res(*this); return res-=a; }

    mint operator*(const mint a) const { mint res(*this); return res*=a; }

    mint pow(ll t) const { if (!t) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }

    // for prime mod

    mint inv() const { return pow(mod-2); }

    mint& operator/=(const mint a) { return (*this) *= a.inv(); }

    mint operator/(const mint a) const { mint res(*this); return res/=a; }

};



int main(){

  int n,m;

  cin >> n >> m;

  vector<ll> x(n);

  vector<ll> y(m);

  rep(i,n){

    cin >> x[i];

  }

  rep(i,m){

    cin >> y[i];

  }



  mint xe=0, ye=0;

  REP(i,1,n){

    xe += (x[i]-x[i-1])*(n-i)*i;

  }

  REP(i,1,m){

    ye += (y[i]-y[i-1])*(m-i)*i;

  }

  mint ans = xe*ye;

  cout << ans.x << ln;

  return 0;

}