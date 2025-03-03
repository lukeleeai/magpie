#include<cstdio>

using namespace std;

int n,sum[2005][2005],u[2005][2005],m,l[2005][2005],t[2005][2005];

char map[2005][2005];

int main()

{

	int q,x1,y1,x2,y2;

	scanf("%d%d%d",&n,&m,&q);

	for(int i=1;i<=n;i++) scanf("%s",map[i]+1);

	for(int i=1;i<=n;i++)

	for(int j=1;j<=m;j++){

		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

		u[i][j]=u[i-1][j]+u[i][j-1]-u[i-1][j-1];

		l[i][j]=l[i-1][j];t[i][j]=t[i][j-1];

		if(map[i][j]=='1'){

			sum[i][j]++;

			if(map[i-1][j]=='1') u[i][j]++,t[i][j]++;

			if(map[i][j-1]=='1') u[i][j]++,l[i][j]++;

		}

	}

	while(q--)

	{

		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

		printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]-(u[x2][y2]-u[x1-1][y2]-u[x2][y1-1]+u[x1-1][y1-1]-t[x1][y2]-l[x2][y1]+t[x1][y1-1]+l[x1-1][y1]));

	}

	return 0;

}