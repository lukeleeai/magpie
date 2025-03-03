#include"stdc++.h"

using namespace std;

int dp[109][10009];



int main(){

  int n,s=10000;

  int a[109];

  cin>>n;

  for(int i=0;i<n;i++){

    cin>>a[i];

  }

  dp[0][0]=true;

  for(int i=0;i<n;i++){

    for(int j=0;j<=s;j++){

      if(j-a[i]<0){

	dp[i+1][j]=dp[i][j];

      }

      else{

	dp[i+1][j]=dp[i][j]|dp[i][j-a[i]];

      }

    }

  }

  int ans=0;

  for(int i=0;i<=s;i++){

    if(dp[n][i]&&i%10!=0){

      ans=i;

    }

  }

  cout<<ans<<endl;

  return(0);

}
