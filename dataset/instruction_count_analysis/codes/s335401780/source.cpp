#include<cstdio>

#include<cstring>



const int N=100,inf=0x5FFFFFFF;

struct node

{

	int x,y;

}R[N+5],B[N+5];

int n,ans;

bool vis[N+5];

int Ma[N+5][N+5],fa[N+5];



int Dfs(int u)

{

	for(int v=1;v<=n;v++)

		if(Ma[u][v]&&!vis[v])

		{

			vis[v]=1;

			if(fa[v]==-1||Dfs(fa[v]))

			{

				fa[v]=u;

				return true;

			}

		}

	return false;

}



void Solve()

{

	memset(fa,-1,sizeof(fa));

	for(int i=1;i<=n;i++)

	{

		memset(vis,0,sizeof(vis));

		ans+=Dfs(i);

	}

}



int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d %d",&R[i].x,&R[i].y);

	for(int i=1;i<=n;i++)

	{

		scanf("%d %d",&B[i].x,&B[i].y);

		for(int j=1;j<=n;j++)

			if(R[j].x<B[i].x&&R[j].y<B[i].y)

				Ma[j][i]=1;

	}

	Solve();

	printf("%d\n",ans);

	return 0;

}