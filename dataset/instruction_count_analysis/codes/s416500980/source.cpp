#include<cstdio>

#include<cstring>

#include<algorithm>

#include<vector>

using namespace std;

int n,m,i,j,k,r,a[1005],ans,map[256][256][2],dp[10005][256];//map:0?路，1水路,dp[i][j]在送到i个?子船在j??的最少花?

int main()

{

	//freopen("1.in","r",stdin);

	//freopen("1.out","w",stdout);

	while(~scanf("%d %d",&n,&m)&&n&&m)

	{

		for(i=1;i<=n;i++)

		{

			for(j=1;j<=n;j++)

			{

				map[i][j][0]=1000000;

				map[i][j][1]=1000000;

			}

			map[i][i][0]=0;

			map[i][i][1]=0;

		}

		int x,y,t,o;

		char s;

		for(i=1;i<=m;i++)

		{

			scanf("\n%d %d %d %c",&x,&y,&t,&s);

			if(s=='L')

				o=0;

			if(s=='S')

				o=1;

			map[x][y][o]=min(map[x][y][o],t);

			map[y][x][o]=map[x][y][o];

		}

		for(k=1;k<=n;k++)

			for(i=1;i<=n;i++)

				for(j=1;j<=n;j++)

				{

						map[i][j][0]=min(map[i][j][0],map[i][k][0]+map[k][j][0]);

						map[i][j][1]=min(map[i][j][1],map[i][k][1]+map[k][j][1]);	

				}

		scanf("%d",&r);

		for(i=1;i<=r;i++)

			scanf("%d",&a[i]);

		for(i=1;i<=r;i++)

			for(j=1;j<=n;j++)

				dp[i][j]=1000000;

		dp[1][a[1]]=0;

		for(i=1;i<=n;i++)

		{

			if(map[a[0]][i][1]<2147483647&&map[i][a[0]][0]<2147483647)

			dp[0][i]=map[a[0]][i][1]+map[i][a[0]][0];

		}

		for(i=2;i<=r;i++)

		{

			for(k=1;k<=n;k++)

			{

				dp[i][k]=min(dp[i][k],dp[i-1][k]+map[a[i-1]][a[i]][0]);

				for(j=1;j<=n;j++)

					dp[i][j]=min(dp[i][j],dp[i-1][k]+map[a[i-1]][k][0]+map[k][j][1]+map[j][a[i]][0]);

			}

		}

		ans=2147483647;

		for(i=1;i<=n;i++)

			ans=min(ans,dp[r][i]);

		printf("%d\n",ans);

	}

}