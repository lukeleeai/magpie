#include<cstdio>

#define maxn 100005

#define LL long long

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

#define INF (LL)1e16

int n,p1,p2,siz[maxn];

LL ans=0,e=INF;

struct node { int v,w; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;

void addedge(int u,int v,int w)

{

	ncnt++;

	ncnt->v=v,ncnt->w=w,ncnt->nxt=head[u];

	head[u]=ncnt;

}

void dfs1(int u,int fa)

{

	siz[u]=1;

	int msiz=0;

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(v==fa) continue;

		dfs1(v,u);

		siz[u]+=siz[v];

		msiz=max(msiz,siz[v]);

	}

	msiz=max(msiz,n-siz[u]);

	if(msiz<=n/2)

	{

		if(!p1) p1=u;

		else p2=u;

	}

}

void dfs2(int u,int fa,LL sum)

{

	ans+=2*sum;

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v,w=p->w;

		if(v==fa) continue;

		if(v==p2||(!p2&&u==p1)) e=min(e,1ll*w);

		dfs2(v,u,sum+w);

	}

}

int main()

{

	ncnt=&edge[0];

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int u,v,w;

		scanf("%d%d%d",&u,&v,&w);

		addedge(u,v,w); addedge(v,u,w);

	}

	dfs1(1,0);

	dfs2(p1,0,0);

	printf("%lld\n",ans-e);

}