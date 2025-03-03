#include "stdc++.h"

#define ft first

#define sc second

#define pt(sth) cout << sth << "\n"

#define chmax(a, b) {if(a<b) a=b;}

#define chmin(a, b) {if(a>b) a=b;}

#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

static const ll INF=1e18;

static const ll MAX=101010;

static const ll MOD=1e9+7;



ll gcd(ll a, ll b) {

  if(b==0) return a;

  else return gcd(b, a%b);

}



ll lcm(ll a, ll b) {

  return a*b/gcd(a, b);

}





int main(void) {

  ll N, M;

  cin >> N >> M;

  ll a[MAX], b[MAX];

  ll cnt[MAX]={};

  ll i;

  

  for(i=0; i<N; i++) {

    cin >> a[i];

    b[i]=a[i]/2;

    

    ll t=b[i];

    while(t%2==0) {

      cnt[i]++;

      t/=2;

    }

    

  }

  sort(b, b+N);

  

  sort(cnt, cnt+N);

  if(cnt[0]!=cnt[N-1]) {

    pt(0);

    return 0;

  }

  

  ll L=1;

  for(i=0; i<N; i++) {

    L=lcm(L, b[i]);

  }

  

  pt((M/L+1)/2);

  

}
