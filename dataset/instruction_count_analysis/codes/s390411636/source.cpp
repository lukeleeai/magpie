#include<cstdio>

#include<cstring>

#include<iostream>

#include<vector>

#define debug(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

const int inf=1e9;

const int maxn=1e5+50;

const int maxp=maxn<<1;

int n,m;

int N;

int a[maxn];

int b[maxn];

int P[maxn];

int Q[maxn];

int head[maxp];

struct edge

{

	int to,nex,cap,flow;

	edge(int to=0,int nex=0,int cap=0,int flow=0):to(to),nex(nex),cap(cap),flow(flow){}

};

vector<edge> G;

inline void addedge(int u,int v,int c)

{

	G.push_back(edge(v,head[u],c,0)),head[u]=G.size()-1;

	G.push_back(edge(u,head[v],0,0)),head[v]=G.size()-1;

}

namespace dinic

{

	int cur[maxp];

	int dis[maxp];

	bool BFS(int s,int t)

	{

		static int que[maxp];

		int hd=0,tl=0;

		memset(dis,-1,sizeof(dis));

		que[tl++]=s;

		dis[s]=0;

		while(hd<tl)

		{

			int u=que[hd++];

			for(int i=head[u];~i;i=G[i].nex) if(G[i].cap!=G[i].flow)

			{

				int v=G[i].to;

				if(dis[v]==-1)

				{

					dis[v]=dis[u]+1;

					que[tl++]=v;

				}

			}

		}

		return dis[t]!=-1;

	}

	int DFS(int u,int flow,int t)

	{

		if(u==t||flow==0) return flow;

		int rec=flow;

		for(int &i=cur[u];~i;i=G[i].nex)

		{

			int v=G[i].to;

			if(dis[v]==dis[u]+1)

			{

				int d=DFS(v,min(flow,G[i].cap-G[i].flow),t);

				G[i].flow+=d,G[i^1].flow-=d;

				flow-=d;

				if(flow==0) break;

			}

		} 

		return rec-flow;

	}

	int maxflow(int s,int t)

	{

		int flow=0;

		while(BFS(s,t))

		{

			memcpy(cur,head,sizeof(head));

			flow+=DFS(s,inf,t);

		}

		return flow;

	}

}

void findcircle(int &n,int *a,int *P)

{

	for(int i=0;i<N;++i) if(!a[i])

	{

		a[i]=++n;

		for(int u=P[i];u!=i;u=P[u]) a[u]=n;

	}

}

int solve()

{

	findcircle(n,a,P);

	findcircle(m,b,Q);

	memset(head,-1,sizeof(head));

	int an=N;

	int p=n+m;

	for(int i=0;i<N;++i)

	{

		if(P[i]==i&&Q[i]==i) --an;

		else if(P[i]==i)

		{

			addedge(n+b[i],p+1,1);

		}

		else if(Q[i]==i)

		{

			addedge(0,a[i],1);

		}

		else

		{

			addedge(n+b[i],a[i],1);

			if(P[i]==Q[i])

			{

				addedge(a[i],n+b[i],1);

			}

		}

	}

	an-=dinic::maxflow(0,p+1);

	return an;

}

int main()

{

	scanf("%d",&N);

	for(int i=0;i<N;++i) scanf("%d",&P[i]);

	for(int i=0;i<N;++i) scanf("%d",&Q[i]);

	printf("%d\n",solve());

	return 0;

} 