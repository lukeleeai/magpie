#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int MAXN=100005,MAXM=200005;

int n,m;

struct edge

{

	int v,nxt;

	edge(){}

	edge(int vv,int nn)

	{

		v=vv,nxt=nn;

	}

}E[MAXM];

int w[MAXN],ncnt,ans[2][MAXN];

bool vis[MAXN];

void addedge(int u,int v)

{

	E[++ncnt]=edge(v,w[u]);

	w[u]=ncnt;

	E[++ncnt]=edge(u,w[v]);

	w[v]=ncnt;

}

void dfs(int u,int id)

{

	vis[u]=1;

	ans[id][++ans[id][0]]=u;

	for(int i=w[u];i;i=E[i].nxt)

	{

		int v=E[i].v;

		if(!vis[v])

		{

			dfs(v,id);

			return ;

		}

	}

}

int main()

{

	//freopen("path.in","r",stdin);

	//freopen("path.out","w",stdout);

	scanf("%d %d",&n,&m);

	for(int i=1;i<=m;i++)

	{

		int u,v;

		scanf("%d %d",&u,&v);

		addedge(u,v);

	}

	dfs(1,0);

	dfs(1,1);

	

	int zans=ans[1][0]+ans[0][0]-1;

	printf("%d\n",zans);

	int key=0;

	for(int i=ans[1][0];i>=2;i--)

	{

		if(key)

			printf(" ");

		printf("%d",ans[1][i]);

		key=1;

	}

	for(int i=1;i<=ans[0][0];i++)

	{

		if(key)

			printf(" ");

		printf("%d",ans[0][i]);

		key=1;

	}

	printf("\n");

	fclose(stdin);

	fclose(stdout);

}