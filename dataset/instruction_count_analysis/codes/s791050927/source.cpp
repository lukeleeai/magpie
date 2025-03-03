#include"stdc++.h"

using namespace std;



const int maxn=100010;

int du[maxn];

int n,root;

struct Edge

{

	int v,next;

}	e[maxn<<1];

int g[maxn],tot;

int fa[maxn];

bool has[maxn];

int ans;

void addedge(int x,int y)

{

	tot++;

	e[tot].v=y;

	e[tot].next=g[x];

	g[x]=tot;

}

void dfs(int t)

{

	int son=du[t];

	if (fa[t]!=0)	son--;

	for (int i=g[t];i;i=e[i].next)

	if (e[i].v!=fa[t])

	{

		fa[e[i].v]=t;

		dfs(e[i].v);

		if (has[e[i].v])	son--,has[t]=true;

	}

	if (son>1)

	{

		ans+=son-1;

		has[t]=true;

	}

}

int main()

{

	scanf("%d",&n);

	for (int i=1;i<n;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		x++;y++;

		addedge(x,y);

		addedge(y,x);

		du[x]++;

		du[y]++;

		if (du[x]>2)	root=x;

	}

	if (!root)

	{

		printf("1\n");

		return 0;

	}

	ans=0;

	fa[root]=0;

	dfs(root);

	printf("%d\n",ans);

	return 0;

}