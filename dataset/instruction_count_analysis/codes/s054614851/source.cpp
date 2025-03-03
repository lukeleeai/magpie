//#define _GLIBCXX_DEBUG

#include"stdc++.h"



#define PI 3.14159265359

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/

#define pb push_back

#define eb emplace_back

#define SZ(x) ((ll)(x).size())

#define all(x) (x).begin(),(x).end()

#define rall(x) (x).rbegin(),(x).rend()

const long long INF= 1e+18+1;

typedef long long ll;

typedef vector<ll> vl;

typedef vector<vector<ll> >vvl;

typedef pair<ll,ll> P;

typedef tuple<ll,ll,ll> T;

//const ll MOD=1000000007LL;

//ll MOD=1000000007LL;

const ll MOD=998244353LL;

//const ll MOD=1777777777LL;

//const ll MAX_V=114514LL;

//const ll MAX = 500010LL;

const ll mod=MOD;

string abc="abcdefghijklmnopqrstuvwxyz";

string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vl dx={0,0,1,-1};

vl dy={1,-1,0,0};



//素因数分解O(√n)

map<ll,ll>prime_factor(ll n){

  map<ll,ll>res;

  for(ll i=2;i*i<=n;i++){

    while(n%i==0){

      res[i]++;

      n/=i;

    }

  }

  if(n!=1)res[n]=1;

  return res;

}



const ll MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

//finvが階乗の逆元



// テーブルを作る前処理

void COMinit() {

    fac[0] = fac[1] = 1;

    finv[0] = finv[1] = 1;

    inv[1] = 1;

    for (ll i = 2; i < MAX; i++){

        fac[i] = fac[i - 1] * i % MOD;

        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

        finv[i] = finv[i - 1] * inv[i] % MOD;

    }

}



// 二項係数計算

long long COM(ll n, ll k){

    if (n < k) return 0;

    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

}



ll modpow(ll a, ll n, ll mod) {

  

    ll res = 1;

    while (n > 0) {

        if (n & 1) res = res * a % mod;

        a = a * a % mod;

        n >>= 1;

    }

    return res;

}







int main(){

  ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  cout << fixed << setprecision(10);

  /*--------------------------------*/

  ll n;cin>>n;

  ll s;cin>>s;

  vl a(n);

  rep(i,n)cin>>a[i];

  vvl dp(n+1,vl(s+1,0));

  ll ans=0;

  dp[0][0]=1;

  rep(i,n){

    rep(j,s+1){

      dp[i+1][j]+=2*dp[i][j];

      dp[i+1][j]%=MOD;

      if(j>=a[i]){

        dp[i+1][j]+=dp[i][j-a[i]];

        dp[i+1][j]%=MOD;

      }

    }

  }

  cout<<dp[n][s]<<endl;

}