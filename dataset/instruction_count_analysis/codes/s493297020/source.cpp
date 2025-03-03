#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 100000

struct node

{

	int to;

	node *next;

}edge[MAXN*2+5];

node *ncnt=&edge[0],*Adj[MAXN+5];

int d[MAXN+5],root=MAXN+5,dp[MAXN+5];

bool vis[MAXN+5];

int n;

void AddEdge(int u,int v)

{

	node *p=++ncnt;

	p->to=v;

	p->next=Adj[u];

	Adj[u]=p;

	

	node *q=++ncnt;

	q->to=u;

	q->next=Adj[v];

	Adj[v]=q;

}

void dfs(int u)

{

	vis[u]=true;

	int chnum=0,nothave=0;

	for(node *p=Adj[u];p!=NULL;p=p->next)

	{

		int v=p->to;

		if(vis[v]==false)

		{

			chnum++;

			dfs(v);

			dp[u]+=dp[v];

			if(dp[v]==0)

				nothave++;

		}

	}

	if(nothave>=2)

		dp[u]+=nothave-1;

}

int main()

{

	scanf("%d",&n);

	int x,y;

	for(int i=1;i<n;i++)

	{

		scanf("%d %d",&x,&y);

		AddEdge(x,y);

		d[x]++,d[y]++;

	}

	for(int i=0;i<n;i++)

	{

		if(d[i]>=3)

		{

			root=i;

			break;

		}

	}

	if(root>MAXN)

	{

		printf("1\n");

		return 0;

	}

	dfs(root);

	printf("%d\n",dp[root]);

}