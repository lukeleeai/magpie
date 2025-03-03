#include<cstdio>

#include<algorithm>

using namespace std;

const int mod=1e9+7;

int n,k,dp[2010];

int qpow(int x,int n){

	int ret=1;

	while(n){

		if(n&1)

			ret=1ll*ret*x%mod;

		x=1ll*x*x%mod;

		n>>=1;

	}

	return ret;

}

int main(){

	scanf("%d%d",&n,&k);

	dp[0]=1;

	for(int i=1;i<n;i++){

		for(int j=i;j;j--){

			dp[j]=dp[j-1]+dp[j+1];

			if(dp[j]>=mod)

				dp[j]-=mod;

		}

		dp[0]=dp[1];

	}

	printf("%d",1ll*dp[n-k]*qpow(2,max(n-k-1,0))%mod);

	return 0;

}