#include<cstdio>

#include<cstring>

#include<algorithm>

#define maxn 100005

using namespace std;

struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;

int n,m,dist[maxn],cirlen,spx,spy,sum[maxn],xs[maxn],st[maxn],t;

bool vis[maxn];

void addedge(int u,int v)

{

	ncnt++;

	ncnt->v=v,ncnt->nxt=head[u];

	head[u]=ncnt;

}

void dfs(int u,int fa)

{

	vis[u]=true;

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(v==fa) continue;

		if(vis[v]) spx=u,spy=v,cirlen=dist[u]-dist[v]+1;

		else { dist[v]=dist[u]+1; dfs(v,u); }

	}

}

void getxs(int u,int fa)

{

	vis[u]=true;

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(vis[v]) continue;

		getxs(v,u);

		xs[u]+=xs[v],sum[u]+=sum[v];

	}

}

int main()

{

	ncnt=&edge[0];

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		addedge(u,v); addedge(v,u);

	}

	dfs(1,0);

	int ans=0,tot=0;

	for(int i=1;i<=n;i++)

	{

		if(dist[i]&1) sum[i]=-1;

		else sum[i]=1;

		tot+=sum[i];

	}

	if(m==n-1&&tot) { printf("-1\n"); return 0; }

	else if(m==n)

	{

		if(cirlen%2)

		{

			if(tot%2) { printf("-1\n"); return 0; }

			sum[spx]-=tot/2,sum[spy]-=tot/2;

			ans+=abs(tot)/2;

		}

		else

		{

			if(tot) { printf("-1\n"); return 0; }

			xs[spx]=1,xs[spy]=-1;

		}

	}

	memset(vis,0,sizeof(vis));

	getxs(1,0);

	for(int i=1;i<=n;i++)

	{

		if(!xs[i]) ans+=abs(sum[i]);

		else

		{

			if(xs[i]==1) sum[i]=-sum[i];

			st[++t]=sum[i];

		}

	}

	st[++t]=0;

	sort(st+1,st+t+1);

	int k=st[(t+1)/2];

	for(int i=1;i<=t;i++) ans+=abs(st[i]-k);

	printf("%d\n",ans);

}