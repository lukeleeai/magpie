#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

int main(){

  int w,n,tre[1001][2],dp[1001][1001] = {0},x;

  for(int c = 1; cin >>w,w; c++){

    cin >>n;

    for(int i=1; i<=n; i++){

      scanf("%d,%d",&tre[i][0],&tre[i][1]);

    }

    for(int i=1; i<=n; i++){

      for(int j=1; j<=w; j++){

	dp[i][j] = dp[i-1][j];

	if(j>=tre[i][1]){dp[i][j] = max(dp[i][j],dp[i-1][j-tre[i][1]]+tre[i][0]);}

      }

    }

    for(int j=0; j<=w; j++){

      if(dp[n][j] == dp[n][w]){x = j;break;}

    }

    cout <<"Case "<<c<<":"<<endl<<dp[n][w]<<endl<<x<<endl;

  }

  return 0;

}