#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int MAXN=3005,MOD=1e9+7;

int n,m;

int dp[MAXN][MAXN][2];

int main()

{

	//freopen("piling.in","r",stdin);

	//freopen("piling.out","w",stdout);

	scanf("%d %d",&n,&m);

	dp[0][0][1]=1;

	for(int i=1;i<=n;i++)

	{

		dp[0][i][0]=1;

	}

	for(int i=0;i<m;i++)

	{

		for(int j=0;j<=n;j++)

		{

			for(int k=0;k<2;k++)

			{

				if(j>0)

				{

					dp[i+1][j-1][k|(j==1)]+=dp[i][j][k];

					dp[i+1][j-1][k|(j==1)]%=MOD;

				}

				if(j>0)

				{

					dp[i+1][j][k|(j==1)]+=dp[i][j][k];

					dp[i+1][j][k|(j==1)]%=MOD;

				}

				if(j<n)

				{

					dp[i+1][j][k]+=dp[i][j][k];

					dp[i+1][j][k]%=MOD;

					dp[i+1][j+1][k]+=dp[i][j][k];

					dp[i+1][j+1][k]%=MOD;

				}

			}

		}

	}

	int ans=0;

	for(int i=0;i<=n;i++)

	{

		ans+=dp[m][i][1];

		ans%=MOD;

	}

	printf("%d\n",ans);

	fclose(stdin);

	fclose(stdout);

}