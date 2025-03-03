#include<cstdio>

using namespace std;

#define N 305

int n,m,p,dp[N][N],su[N][N],c[N][N];

int main()

{

	scanf("%d%d%d",&n,&m,&p);n++;m++;

	for(int i=1;i<=m;i++)dp[1][i]=1,su[1][i]=i;

	for(int i=0;i<=n;i++)c[i][i]=c[i][0]=1;

	for(int i=2;i<=n;i++)for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;

	for(int i=2;i<=n;i++)

	{

		for(int k=1;k<=m;k++)

		for(int j=1;j<i;j++)

		dp[i][k]=(dp[i][k]+1ll*dp[i-j][k]*su[j][k-1]%p*c[i-2][j-1])%p;

		for(int k=1;k<=m;k++)su[i][k]=(su[i][k-1]+dp[i][k])%p;

	}

	printf("%d\n",dp[n][m]);

}//