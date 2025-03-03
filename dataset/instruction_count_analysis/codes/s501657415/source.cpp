



#include"stdc++.h"

using namespace std;

#define MAX 100005

#define INF (1e9+1)

 

int n,W;

int dp[MAX];

 

int main(){

  fill(dp,dp+MAX,INF);

  dp[0]=0;

   

  cin>>n>>W;

  for(int i=0;i<n;i++){

    int v,w;

    cin>>v>>w;

    for(int j=MAX-1;j>=v;j--){

      dp[j]=min(dp[j],dp[j-v]+w);

    }

  }

 

  for(int i=MAX-1;i>=0;i--){

    if(dp[i]<=W){

      cout<<i<<endl;

      break;

    }

  }

   

  return 0;

}