#include<cstdio>

#include<cstring>

#define maxn 100005

int n,r1,r2,s1[maxn],s2[maxn],ans[maxn],st[maxn],tp;

bool vis[maxn];

struct node { int v; node *nxt; } edge[maxn*16],*head[3][maxn],*ncnt;

void addedge(int u,int v,int d)

{

	ncnt++;

	ncnt->v=v,ncnt->nxt=head[d][u];

	head[d][u]=ncnt;

}

void dfs(int d,int u)

{

	for(node *p=head[d][u];p;p=p->nxt) dfs(d,p->v);

	if(!s1[u]) st[++tp]=u;

	while(tp>1) { addedge(st[tp],st[tp-1],2); addedge(st[tp-1],st[tp],2); tp-=2; }

}

void dfs2(int u,int c)

{

	ans[u]=c,vis[u]=true;

	for(node *p=head[2][u];p;p=p->nxt)

	{

		int v=p->v;

		if(!vis[v]) dfs2(v,-c);

	}

}

int main()

{

	ncnt=&edge[0];

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		int fa;

		scanf("%d",&fa);

		if(fa>0) { addedge(fa,i,0); s1[fa]^=1; }

		else r1=i;

	}

	for(int i=1;i<=n;i++)

	{

		int fa;

		scanf("%d",&fa);

		if(fa>0) { addedge(fa,i,1); s2[fa]^=1; }

		else r2=i;

	}

	for(int i=1;i<=n;i++)

		if(s1[i]!=s2[i]) { printf("IMPOSSIBLE\n"); return 0; }

	printf("POSSIBLE\n");

	dfs(0,r1); 

	tp=0;

	dfs(1,r2);

	for(int i=1;i<=n;i++)

		if(!vis[i]) dfs2(i,1);

	for(int i=1;i<=n;i++) printf("%d ",s1[i]?0:ans[i]);

}