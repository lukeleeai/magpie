#include "stdc++.h"

#define rep(i,n) for(long long i=0; i<n; i++)

#define Rep(i,n) for(long long i=1; i<n; i++)

#define ll long long

#include <math.h>

#include <cmath>

#include <iomanip>

#include <iostream>

#include <numeric>

#include <queue>

#include <set>

#include <vector>





using namespace std;

#define PI acos(-1)

using P =pair<ll,ll>;





ll m=1000000007;



ll mod=1e9+7;

ll dp[2000+4];





int main()

{

  ll n,m,k;

  cin>>n>>m>>k;

  vector<ll>a(n);

  rep(i,n)cin>>a[i];

  vector<ll>b(m);

  rep(i,m)cin>>b[i];

  vector<ll>aa(n+1);

  aa[0]=0;

  Rep(i,n+1)aa[i]=aa[i-1]+a[i-1];

  vector<ll>bb(m+1);

  bb[0]=0;

  Rep(i,m+1)bb[i]=bb[i-1]+b[i-1];

  ll ans=0;

  ll sum=0;

  ll j=m;

  for(ll i=0;i<=n;i++){

      sum=aa[i];

      if(k<sum)break;

      while(k<sum+bb[m]){

          m--;

      }

      ans=max(ans,i+m);

  }

  cout<<ans<<endl;

}

 





 



 




