#include"stdc++.h"

using namespace std;

#define ll long long

#define inf 0x3f3f3f3f

const int N=1e5+10;

ll a[N],dp[N]={0};

int main()

{

	int n,k,i,j;

	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++)

	{

		scanf("%lld",&a[i]); 

	} 

	dp[1]=0;

	for(i=2;i<=n;i++)

	{

		dp[i]=inf;

		for(j=1;j<=k;j++)

		{

			if(i<=j) break;

			dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));

		}

	}

	printf("%lld\n",dp[n]);

	return 0;

}