#include<cstdio>

#include<algorithm>

#include<map>

#include<queue>

using namespace std;

#define MAXN 810

#define MAXM 640010

#define INF 1000000000

#define PII pair<int,int>

char s[MAXN][MAXN];

int n,m,K,sx,sy,ans=INF;

int dis[MAXN][MAXN];

int d[]={1,0,-1,0,1};

queue<PII>Q;

void BFS()

{

	int l=0,r=0;

	dis[sx][sy]=K+1;

	Q.push(PII(sx,sy));

	while(!Q.empty())

	{

		PII p=Q.front();Q.pop();

		int nx=p.first,ny=p.second;

		ans=min(ans,min(nx-1,min(ny-1,min(n-nx,m-ny))));

		if(dis[nx][ny]==1) continue;

		for(int i=0;i<4;i++)

		{

			int px=nx+d[i],py=ny+d[i+1];

			if(px==0||py==0||px>n||py>m||s[px][py]=='#'||dis[px][py]!=0) continue;

			dis[px][py]=dis[nx][ny]-1;

			Q.push(PII(px,py));

		}

	}

}

int main()

{

	scanf("%d%d%d",&n,&m,&K);

	for(int i=1;i<=n;i++)

	{

		scanf("%s",s[i]+1);

		for(int j=1;j<=m;j++)

			if(s[i][j]=='S')

				sx=i,sy=j;

	}

	if(sx==1||sx==n||sy==1||sy==m)

	{

		printf("0\n");

		return 0;

	}

	BFS();

	ans=(ans+K-1)/K+1;

	printf("%d\n",ans);

}