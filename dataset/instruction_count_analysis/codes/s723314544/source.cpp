#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 2010

int sum1[MAXN][MAXN],sum2[MAXN][MAXN],cl[MAXN][MAXN],n,m,q;

char s[MAXN][MAXN];

int main()

{

	scanf("%d%d%d",&n,&m,&q);

	for(int i=1;i<=n;i++)

	{

		scanf("%s",s[i]+1);

		s[i][0]='0';

		for(int j=1;j<=m;j++)

		{

			sum1[i][j]=sum1[i][j-1];

			sum2[i][j]=sum2[i][j-1];

			if(s[i][j]=='1'&&s[i-1][j]=='1')

				sum1[i][j]++;

			if(s[i][j]=='1'&&s[i][j-1]=='0')

				sum2[i][j]++;

			if(s[i][j]=='1'&&s[i][j+1]=='1')

				cl[i][j]=1;

			cl[i][j]+=cl[i-1][j];

		}

		for(int j=1;j<=m;j++)

		{

			sum1[i][j]+=sum1[i-1][j];

			sum2[i][j]+=sum2[i-1][j];

		}

	}

	int x1,y1,x2,y2;

	while(q--)

	{

		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

		x1--,y1--;

		int ans=sum2[x2][y2]-sum2[x1][y2]-sum2[x2][y1]+sum2[x1][y1]+cl[x2][y1]-cl[x1][y1];

		ans-=sum1[x2][y2]-sum1[x1+1][y2]-sum1[x2][y1]+sum1[x1+1][y1];

		printf("%d\n",ans);

	}

}