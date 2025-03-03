#include"stdc++.h"

using namespace std;

using Int = long long;

signed main(){

  int n;

  cin>>n;

  vector<int> t(n),v(n);

  for(int i=0;i<n;i++) cin>>t[i],t[i]*=2;

  for(int i=0;i<n;i++) cin>>v[i],v[i]*=2;

  vector<vector<int> > dp(222,vector<int>(2,-1));

  dp[0][0]=0;

  int cur=0;

  for(int i=0;i<n;i++){

    for(int j=0;j<t[i];j++){

      bool f=cur%2;

      for(int k=0;k<222;k++) dp[k][!f]=-1;

      for(int k=0;k<=v[i];k++){

	if(dp[k][f]<0) continue;

	dp[k][!f]=max(dp[k][!f],dp[k][f]+k+k);

	if(k+1<=v[i])

	  dp[k+1][!f]=max(dp[k+1][!f],dp[k][f]+k+(k+1));

	if(k-1>=0)

	  dp[k-1][!f]=max(dp[k-1][!f],dp[k][f]+k+(k-1));

      }

      cur++;

    }

  }

  //assert(sum==cur);

  cout<<fixed<<setprecision(12)<<(double)dp[0][cur%2]/8.0<<endl;

  return 0;

}