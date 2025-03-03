#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

int main(){

  for(int c=1,w; cin>>w,w; c++){

    int n,tr[1001][2] = {0};

    cin >>n;

    for(int i=1; i<=n; i++){

      scanf("%d,%d",&tr[i][0],&tr[i][1]);

    }

    int dp[1001][1001] = {0};

    for(int i=1; i<=n; i++){

      for(int j=0; j<=w; j++){

	if(j>=tr[i][1]){dp[j][i] = max(dp[j][i-1],dp[j-tr[i][1]][i-1]+tr[i][0]);}

	else{dp[j][i] = dp[j][i-1];}

      }

    }

    int pr = dp[w][n], val;

    for(int j=0; j<=w; j++){

      if(pr == dp[j][n]){val = j;break;}

    }

    cout <<"Case "<<c<<":"<<endl;

    cout <<pr<<endl<<val<<endl;

  }

  return 0;

}