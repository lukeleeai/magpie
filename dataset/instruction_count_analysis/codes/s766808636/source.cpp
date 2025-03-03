#include"stdc++.h"

using namespace std;

const int maxn=1e5+10;

struct edge{int v,nxt;}e[maxn<<1];

int head[maxn],ecnt=0;

void add(int u,int v)

{

	e[++ecnt]=(edge){v,head[u]},head[u]=ecnt;

	e[++ecnt]=(edge){u,head[v]},head[v]=ecnt;

}

int fa[maxn],n;

bool vis[maxn];

bool ans=1;

void dfs(int u,int pre)

{

	fa[u]=pre;

	for(int i=head[u];~i;i=e[i].nxt)

	{

		int v=e[i].v;

		if(v==pre)continue;

		dfs(v,u);

	}

	if(u==1)

	{

		if(vis[u]==0)ans=0;

	}

	else 

	{

		if(!vis[u])

		{

			if(!vis[fa[u]])vis[fa[u]]=1,vis[u]=1;

			else ans=0;

		}	

	}

	

}

int main()

{

	memset(head,-1,sizeof(head));

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		add(u,v);

	}

	dfs(1,0);

	printf("%s\n",!ans?"First":"Second");

}