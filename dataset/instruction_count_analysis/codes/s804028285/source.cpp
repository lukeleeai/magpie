#include "stdc++.h"

#define maxn 109

#define maxm 1009

using namespace std;

struct Edge

{

	int v,w,next;

}edge[maxm];

int n,m,tot,head[maxn];

int d[maxn][maxm],inq[maxn][maxm];

inline void addedge(int u,int v,int w)

{

	edge[tot].v=v;

	edge[tot].w=w;

	edge[tot].next=head[u];

	head[u]=tot++;

}

queue<pair<int,int> >Q;

void spfa()

{

	memset(d,0x3f,sizeof(d));

	d[1][0]=0;

	Q.push(make_pair(1,0));

	pair<int,int>tmp;

	while(!Q.empty())

	{

		tmp=Q.front();

		Q.pop();

		int x=tmp.first;

		int y=tmp.second;

		inq[x][y]=0;

		for(int e=head[x];e!=-1;e=edge[e].next)

		{

			int v=edge[e].v;

			if(y<m&&d[v][y+1]>d[x][y])

			{

				d[v][y+1]=d[x][y];

				if(!inq[v][y+1])

				{

					inq[v][y+1]=1;

					Q.push(make_pair(v,y+1));

				}

			}

			if(d[v][y]>d[x][y]+edge[e].w)

			{

				d[v][y]=d[x][y]+edge[e].w;

				if(!inq[v][y])

				{

					inq[v][y]=1;

					Q.push(make_pair(v,y));

				}

			}

		}

	}

}

int main()

{

	int u,v,w,c;

	while(scanf("%d%d%d",&n,&m,&c),n+m+c)

	{

		memset(head,-1,sizeof(head));

		tot=0;

		for(int i=1;i<=m;i++)

		{

			scanf("%d%d%d",&u,&v,&w);

			addedge(u,v,w);

		}

		spfa();

		int ans=m;

		for(int i=0;i<=m;i++)

		{

			if(d[n][i]<=c)

			{

				ans=i;

				break;

			}

		}

		printf("%d\n",ans);

	}

	return 0;

}