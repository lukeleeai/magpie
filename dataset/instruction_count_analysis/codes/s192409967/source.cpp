#include<cstdio>

using namespace std;

#define N 3005

#define mod 1000000007

#define inv 500000004

int n,dp[N][N],v[N],q,a,b;

int main()

{

	scanf("%d%d",&n,&q);

	for(int i=1;i<=n;i++)scanf("%d",&v[i]);

	for(int i=1;i<=n;i++)

	for(int j=1;j<=n;j++)dp[i][j]=(v[i]<v[j]);

	for(int i=1;i<=q;i++)

	{

		scanf("%d%d",&a,&b);

		int tp=dp[a][b]+dp[b][a];

		for(int j=1;j<=n;j++)

		{

			dp[j][a]=dp[j][b]=1ll*(dp[j][a]+dp[j][b])*inv%mod;

			dp[a][j]=dp[b][j]=1ll*(dp[a][j]+dp[b][j])*inv%mod;

		}

		dp[a][b]=dp[b][a]=1ll*tp*inv%mod;

	}

	int as=0;

	for(int i=2;i<=n;i++)

	for(int j=1;j<i;j++)as=(as+dp[i][j])%mod;

	for(int i=1;i<=q;i++)as=as*2%mod;

	printf("%d\n",as);

}

//111222333