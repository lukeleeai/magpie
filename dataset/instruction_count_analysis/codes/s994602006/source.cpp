#include<cstdio>

#include<algorithm>

using namespace std;

int d[300+5][300+5];

int t[5][300+5],s[5][300+5];//3的余数为0,1,2——>枚举所有情况求最优值

int x,y,z,ans=(int)1E9;

int n,c;

int solve(int x,int y)

{

	int ret=0;

	for(int i=1;i<=c;i++)

		ret+=t[x][i]*d[i][y];

	return ret;

}

int main()

{

	scanf("%d %d",&n,&c);

	for(int i=1;i<=c;i++)

    	for(int j=1;j<=c;j++)

			scanf("%d",&d[i][j]);//颜色i变成颜色j的代价

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)

		{

			scanf("%d",&x);

			t[(i+j)%3][x]++;//余数为i,颜色为j的方格个数+1

		}

	for(int i=0;i<=2;i++)

		for(int j=1;j<=c;j++)

			s[i][j]=solve(i,j);

	for(int i=1;i<=c;i++)

		for(int j=1;j<=c;j++)

			for(int k=1;k<=c;k++)

			{

				if(i!=j&&i!=k&&j!=k)

					ans=min(ans,(s[0][i]+s[1][j]+s[2][k]));

			}

	printf("%d\n",ans);

	return 0;

}
