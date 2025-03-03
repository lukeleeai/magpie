#include<cstdio>

#include<cstring> 

#include<iostream>

#include<algorithm>

using namespace std;

const int M=1200000;

int n,m,w[M],v[M],sum;long long dp[M];

int main(){

	scanf("%d%d",&n,&m);

	dp[0]=0;

	for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]),sum+=v[i];

	for(int i=1;i<=sum;i++) dp[i]=1000000000ll*100ll+1ll;

	for(int i=1;i<=n;i++)

	for(int j=sum;j>=v[i];j--)

		dp[j]=min(dp[j-v[i]]+w[i],dp[j]);

	for(int i=sum;i>=0;i--) if(dp[i]<=m){

		printf("%d",i) ;break;

	}

	

}