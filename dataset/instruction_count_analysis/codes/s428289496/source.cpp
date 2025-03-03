#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 100010

#define LL long long

#define INF 1000000000

int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],W[MAXN*2],c;

void AddEdge(int u,int v,int w)

{

	c++;V[c]=v,W[c]=w,nxt[c]=Adj[u];Adj[u]=c;

}

int siz[MAXN],mx[MAXN],rt,rt2,n,tmp=INF;

LL ans;

void dfs1(int u,int p)

{

	siz[u]=1;

	for(int i=Adj[u];i;i=nxt[i])

		if(V[i]!=p)

		{

			dfs1(V[i],u);

			siz[u]+=siz[V[i]];

			mx[u]=max(mx[u],siz[V[i]]);

		}

	mx[u]=max(mx[u],n-siz[u]);

	if(mx[u]<=n/2)

	{

		if(rt==0) rt=u;

		else rt2=u;

	}

}

void dfs2(int u,int p,LL dep)

{

	ans+=dep*2;

	for(int i=Adj[u];i;i=nxt[i])

		if(V[i]!=p)

		{

			dfs2(V[i],u,dep+W[i]);

			if(V[i]==rt2||(rt2==0&&u==rt))

				tmp=min(tmp,W[i]);

		}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int u,v,w;

		scanf("%d%d%d",&u,&v,&w);

		AddEdge(u,v,w);

		AddEdge(v,u,w);

	}

	dfs1(1,0);

	dfs2(rt,0,0);

	ans-=tmp;

	printf("%lld\n",ans);

}
