#include"stdc++.h"

using namespace std;

const int N=20005;

int dp[N],a[N],b[N],n,h,ans=1e9;

int main()

{

	scanf("%d%d",&h,&n);

	for(int i=1;i<=n;i++)

		scanf("%d%d",&a[i],&b[i]);

	for(int j=1;j<=20000;j++)

		dp[j]=1e9;

	for(int i=1;i<=n;i++)

	{

		for(int j=a[i];j<=20000;j++)

		{

			dp[j]=min(dp[j],dp[j-a[i]]+b[i]);

			if(j>=h)

				ans=min(ans,dp[j]);

		}

	}

	printf("%d\n",ans);

	return 0;

}