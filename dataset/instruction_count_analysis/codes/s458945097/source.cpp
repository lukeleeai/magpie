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

  ll cnt[22][22]={};

  

  map<double, ll> mp;

  for(i=0; i<N; i++) {

    double tt;

    cin >> tt;

    a[i]=llround(tt*1e9);

    

    ll t=a[i];

    ll c2=0, c5=0;

    while(t%2==0) {c2++; t/=2;}

    while(t%5==0) {c5++; t/=5;}

    cnt[min(18LL, c2)][min(18LL, c5)]++;

    

  }

  

  

  ll ans=0;

  for(i=0; i<22; i++) {

    for(j=0; j<22; j++) {

      for(k=0; k<22; k++) {

        for(l=0; l<22; l++) {

          if(i==k && j==l) continue;

          

          if(i+k>=18 && j+l>=18) {

            ans+=cnt[i][j]*cnt[k][l];

          }

        }

      }

    }

  }

  ans/=2;

  

  for(i=9; i<22; i++) {

    for(j=9; j<22; j++) {

      ans+=cnt[i][j]*(cnt[i][j]-1)/2;

    }

  }

  pt(ans);

  

}
