#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 100010

int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c,n;

void AddEdge(int u,int v)

{

	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;

}

int dfs(int u,int p)

{

	int ret=0;

	for(int i=Adj[u];i;i=nxt[i])

		if(V[i]!=p)

		{

			ret^=dfs(V[i],u)+1;

		}

	return ret;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		AddEdge(u,v);

		AddEdge(v,u);

	}

	int ans=dfs(1,0);

	if(ans) printf("Alice\n");

	else printf("Bob\n");

}