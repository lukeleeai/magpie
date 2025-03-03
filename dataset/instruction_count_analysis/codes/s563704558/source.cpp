#include"stdc++.h"

using namespace std;

int dp[1010][1010];

int main()

{

	int n,m,q,x,y,k;

	scanf("%d%d%d",&n,&m,&q);

	memset(dp,0,sizeof(dp));

	for(int i=1; i<=m; i++)

	{

		scanf("%d%d",&x,&y);

		dp[x][y]++;

	}

	for(int j=1;j<n;j++)

		for(int i=1;i+j<=n;i++)

		{

			dp[i][i+j]=dp[i][i+j]+dp[i+1][i+j]+dp[i][i+j-1];

			if(j>1)dp[i][i+j]-=dp[i+1][i+j-1];

		}

	while(q--)

	{

		scanf("%d%d",&x,&y);

		printf("%d\n",dp[x][y]);

	}

	return 0;

}