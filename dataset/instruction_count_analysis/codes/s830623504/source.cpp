#include<cstdio>

#include<cstring>

#include<algorithm>

#define maxn 200005

#define INF 2147483640

#define LL long long

using namespace std;

int n,sum,l[maxn],r[maxn],mx[maxn],sx[maxn],siz[maxn];

LL ans;

char s[maxn];

struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;

void addedge(int u,int v)

{

	ncnt++;

	ncnt->v=v,ncnt->nxt=head[u];

	head[u]=ncnt;

}

void dfs1(int u,int fa)

{

	siz[u]=s[u]-'0';

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(v==fa) continue;

		dfs1(v,u);

		siz[u]+=siz[v];

		if(mx[v]+1>mx[u]) sx[u]=mx[u],mx[u]=mx[v]+1;

		else if(mx[v]+1>sx[u]) sx[u]=mx[v]+1;

	}

}

void dfs2(int u,int fa,int len)

{

	r[u]=len>mx[u]?mx[u]:max(len,sx[u]);

	l[u]=s[u]-'0'?0:(sum-siz[u]?len:INF);

	if(fa)

	{

		if(len-1==mx[u]) ans++;

		else if(len-1<mx[u]) ans+=siz[u]<sum;

		else ans+=siz[u]>0;

	}

	for(node *p=head[u];p;p=p->nxt)

	{

		int v=p->v;

		if(v==fa) continue;

		if(siz[v]) l[u]=min(l[u],mx[v]+1);

		if(mx[u]==mx[v]+1) dfs2(v,u,max(len,sx[u])+1);

		else dfs2(v,u,max(len,mx[u])+1);

	}

}

int main()

{

	scanf("%d",&n);

	ncnt=&edge[0];

	for(int i=1;i<n;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		addedge(u,v); addedge(v,u);

	}

	scanf("%s",s+1);

	for(int i=1;i<=n;i++) sum+=s[i]-'0';

	dfs1(1,0); dfs2(1,0,0);

	for(int i=1;i<=n;i++)

		if(l[i]<=r[i]) ans+=1ll*(r[i]-l[i]+1);

	printf("%lld\n",ans);

}
