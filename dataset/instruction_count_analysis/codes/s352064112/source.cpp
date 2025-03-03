#include<cstdio>

#include<algorithm>

#include<queue>

#include<vector>

using namespace std;

#define MAXN 100010

#define MAXM 200010

#define MAXK 2000100

#define INF 1000000000

struct edge

{

	int u,v,c;

}e[MAXM];

bool cmp(edge a,edge b)

{

	return a.c<b.c;

}

int fa[MAXN],n,N,m,u,v,c,im[MAXN];

vector<int>A;

int Find(int x)

{

	return fa[x]==x?x:fa[x]=Find(fa[x]);

}

void Union(int x,int y)

{

	x=Find(x),y=Find(y);

	fa[x]=y;

}

int Adj[MAXK],V[MAXK],nxt[MAXK],p;

void AddEdge(int u,int v)

{

	p++;V[p]=v;nxt[p]=Adj[u];

	Adj[u]=p;

}

int dis[MAXK];

bool vis[MAXK];

void SPFA()

{

	for(int i=1;i<=N;i++)

		dis[i]=INF;

	queue<int>Q;

	Q.push(1);

	dis[1]=0;

	vis[1]=1;

	while(!Q.empty())

	{

		int u=Q.front();Q.pop();

		vis[u]=0;

		for(int i=Adj[u];i;i=nxt[i])

			if(dis[V[i]]>dis[u]+1)

			{

				dis[V[i]]=dis[u]+1;

				if(!vis[V[i]])

				{

					vis[V[i]]=1;

					Q.push(V[i]);

				}

			}

	}

}

int main()

{

	scanf("%d%d",&n,&m);

	N=n;

	for(int i=0;i<m;i++)

		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);

	sort(e,e+m,cmp);

	for(int i=1;i<=n;i++)

		fa[i]=i;

	int ls=0,lc=e[0].c;

	for(int i=0;i<=m;i++)

		if(e[i].c!=lc)

		{

			for(int j=ls;j<i;j++)

				Union(e[j].u,e[j].v);

			for(int j=ls;j<i;j++)

			{

				int y=Find(e[j].v);

				if(!im[y])

					im[y]=++N,A.push_back(y);

				AddEdge(e[j].u,im[y]);

				AddEdge(im[y],e[j].u);

				AddEdge(e[j].v,im[y]);

				AddEdge(im[y],e[j].v);

			}

			for(int j=ls;j<i;j++)

				fa[e[j].v]=e[j].v,fa[e[j].u]=e[j].u;

			for(int j=0;j<A.size();j++)

				im[A[j]]=0;

			A.clear();

			ls=i,lc=e[i].c;

		}

	SPFA();

	if(dis[n]==INF) printf("-1\n");

	else printf("%d\n",dis[n]/2);

}