#include"stdc++.h"

using namespace std;

int dp[1010][1010];

int main()

{

	int n,m,q,i,x,y,j,k;

	scanf("%d%d%d",&n,&m,&q);

	memset(dp,0,sizeof(dp));

	for(i=1; i<=m; i++)

	{

		scanf("%d%d",&x,&y);

		dp[x][y]++;

	}

	for(j=1; j<n; j++)

		for(i=1; i+j<=n; i++)

		{

			k=i+j;

			dp[i][k]=dp[i][k]+dp[i+1][k]+dp[i][k-1];

			if(j>1)dp[i][k]-=dp[i+1][k-1];

		}

	while(q--)

	{

		scanf("%d%d",&x,&y);

		printf("%d\n",dp[x][y]);

	}







	return 0;

}