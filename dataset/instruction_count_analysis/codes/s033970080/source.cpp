#include "stdc++.h"

#define ft first

#define sc second

#define pt(sth) cout << sth << "\n"

#define moca(a, s, b) a=((a)s(b)+MOD)%MOD

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}

template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}

static const ll INF=1e18;

static const ll MAX=101010;

static const ll MOD=1e9+7;





//for(i=0; i<N; i++) cin >> a[i];





int main(void) {

  ll i, j, k, l;

  

  ll N;

  cin >> N;

  ll a[MAX*2];

  ll cnt[66][66]={};

  pll f[MAX*2]={};

  

  map<double, ll> mp;

  for(i=0; i<N; i++) {

    double tt;

    cin >> tt;

    a[i]=llround(tt*1e9);

    

    ll t=a[i];

    ll c2=0, c5=0;

    while(t%2==0) {c2++; t/=2;}

    while(t%5==0) {c5++; t/=5;}

    cnt[c2][c5]++;

    f[i]={c2, c5};

  }

  

  

  ll ans=0;

  for(i=0; i<N; i++) {

    ll n2=max(18-f[i].ft, 0LL);

    ll n5=max(18-f[i].sc, 0LL);

    

    for(j=n2; j<66; j++) {

      for(k=n5; k<66; k++) {

        ans+=cnt[j][k];

      }

    }

    

    if(n2<=f[i].ft && n5<=f[i].sc) ans--;

  }

  ans/=2;

  pt(ans);

}
