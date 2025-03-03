#include<cstdio>

#include<cstring>

#define maxn 3005

int n,a[maxn],ans[maxn],cnt;

bool f[maxn];

struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;

void addedge(int u,int v)

{

	ncnt++;

	ncnt->v=v,ncnt->nxt=head[u];

	head[u]=ncnt;

}

bool dfs(int u,int fa)

{

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(a[v]<a[u]&&!dfs(v,u)) return f[u]=true;

	}

	return f[u]=false;

}

int main()

{

	ncnt=&edge[0];

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	for(int i=1;i<n;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		addedge(u,v); addedge(v,u);

	}

	for(int i=1;i<=n;i++)

	{

		memset(f,0,sizeof(f));

		if(dfs(i,0)) ans[++cnt]=i;

	}

	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);

}
