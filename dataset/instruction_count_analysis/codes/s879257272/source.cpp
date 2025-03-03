//#define _GLIBCXX_DEBUG

#include"stdc++.h"



#define PI 3.14159265359

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/

const long long INF= 1e+18+1;

typedef long long ll;

typedef vector<ll> vl;

typedef vector<vector<ll> >vvl;

typedef pair<ll,ll> P;

typedef tuple<ll,ll,ll> T;

//const ll MOD=1000000007LL;

const ll MOD=998244353LL;

//const ll MAX_V=114514LL;

const ll MAX = 510000LL;

string abc="abcdefghijklmnopqrstuvwxyz";

string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vl dx={-1,-1,-1,0,0,1,1,1};

vl dy={1,-1,0,1,-1,1,0,-1};



ll dp[3010][3010];

int main(){

  ll n;cin>>n;

  ll s;cin>>s;

  vl a(n);

  rep(i,n)cin>>a[i];

  dp[0][0]=1;

  for(ll i=1;i<=n;i++){

    rep(j,3010){

      dp[i][j]+=dp[i-1][j]*2;

      dp[i][j]%=MOD;

      if(j>=a[i-1])dp[i][j]+=dp[i-1][j-a[i-1]];

      dp[i][j]%=MOD;

    }

  }

  //rep(i,n+1){

    //rep(j,s+1)cout<<dp[i][j]<<" ";

    //cout<<endl;

  //}

  cout<<dp[n][s]%MOD<<endl;

}