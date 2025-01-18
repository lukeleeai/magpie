#include"stdc++.h"

using namespace std;

#define INF 1000000000

int dp(int i);

int n,k;

int h[100009],memo[100009];



int main(){

  memset(memo,-1,sizeof(memo));

  cin>>n>>k;

  for(int i=0;i<n;i++)cin>>h[i];

  cout<<dp(0)<<endl;

  return(0);

}



int dp(int i){

  int rec=INF;

  if(memo[i]!=-1)return memo[i];

  if(i==n-1)return 0;

  for(int j=1;j<=k;j++){

    if(i+j<n)rec=min(rec,dp(i+j)+abs(h[i]-h[i+j]));

  }

  return memo[i]=rec;

}
