#include"stdc++.h"

using namespace std;

int dp(int now,int sum);

int n;

int a[109];

int memo[109][10009];



int main(){

  memset(memo,-1,sizeof(memo));

  cin>>n;

  for(int i=0;i<n;i++){

    cin>>a[i];

  }

  cout<<dp(0,0)<<endl;

}



int dp(int now,int sum){

  int rec=0;

  if(memo[now][sum]!=-1)return memo[now][sum];

  if(now==n){

    if(sum%10==0)return 0;

    else return sum;

  }

  rec=max(rec,dp(now+1,sum));

  rec=max(rec,dp(now+1,sum+a[now]));

  return memo[now][sum]=rec;

}

  
