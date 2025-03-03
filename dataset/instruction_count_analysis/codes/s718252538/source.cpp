#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 100000

using namespace std;

typedef long long LL;

struct node

{

	int to;

	node *nxt;

}edges[MAXN+5];

node *ncnt=&edges[0],*Adj[MAXN+5];

int a[MAXN+5],N,dep[MAXN+5],dep2[MAXN+5],K,maxdep[MAXN+5];

LL ans=0;

void AddEdge(int u,int v)

{

	node *p=++ncnt;

	p->to=v;

	p->nxt=Adj[u];

	Adj[u]=p;

}

void DFS(int u)

{

	dep[u]=1;

	for(node *p=Adj[u];p!=NULL;p=p->nxt)

	{

		int v=p->to;

		DFS(v);

		dep[u]=max(dep[u],dep[v]+1);

	}

	if(dep[u]==K&&a[u]!=1)

	{

		ans++;

		dep[u]=0;

	}

}

int main()

{

	scanf("%d %d",&N,&K);

	for(int i=1;i<=N;i++)

		scanf("%d",&a[i]);

	if(a[1]!=1)

		a[1]=1,ans+=1LL;

	for(int i=2;i<=N;i++)

		AddEdge(a[i],i);

	DFS(1);

	printf("%lld\n",ans);

	return 0;

}