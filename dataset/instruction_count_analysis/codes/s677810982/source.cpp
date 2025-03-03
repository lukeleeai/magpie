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

  ll h,w,k;

  cin>>h>>w>>k;

  vector<string>s(h);

  rep(i,h)cin>>s[i];

  ll ans=0;

  rep(i,1<<h){

      rep(j,1<<w){

          ll cnt=0;

          for(ll ii=0;ii<h;ii++){

              for(ll jj=0;jj<w;jj++){

                  if(i>>ii&1)continue;

                  if(j>>jj&1)continue;

                  if(s[ii][jj]=='#')cnt++;

              }

          }

          if(cnt==k)ans++;

      }

  }

  cout<<ans<<endl;

}

 





 



 




