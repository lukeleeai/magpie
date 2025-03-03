#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 100000

using namespace std;

typedef long long LL;

struct node

{

	int to,w;

	node *nxt;

}edges[MAXN*4+5];

node *ncnt,*Adj[MAXN+5];

int N,M;

int col[MAXN+5],cnt[3],edcnt=0;

bool legal=true;

void Init()

{

	ncnt=&edges[0];

	memset(col,-1,sizeof(col));

}

void AddEdge(int u,int v,int w)

{

	node *p=++ncnt;

	p->to=v;

	p->w=w;

	p->nxt=Adj[u];

	Adj[u]=p;

}

void DFS(int u)

{

	cnt[col[u]]++;

	for(node *p=Adj[u];p!=NULL;p=p->nxt)

	{

		int v=p->to;

		int w=p->w;

		if(w==1)

			edcnt++;

		if(col[v]==-1)

		{

			col[v]=(col[u]+w)%3;

			DFS(v);

		}

		else if(col[v]!=(col[u]+w)%3)

			legal=false;

	}

}

int main()

{

//	freopen("flower.in","r",stdin);

//	freopen("flower.out","w",stdout);

	Init();

	scanf("%d %d",&N,&M);

	int u,v;

	for(int i=1;i<=M;i++)

	{

		scanf("%d %d",&u,&v);

		AddEdge(u,v,1);

		AddEdge(v,u,2);

	}

	LL ans=0;

	for(int i=1;i<=N;i++)

		if(col[i]==-1)

		{

			edcnt=0;

			legal=true;

			memset(cnt,0,sizeof(cnt));

			col[i]=0;

			DFS(i);

			if(legal==false)

				ans+=(1LL*cnt[0]+1LL*cnt[1]+1LL*cnt[2])*(1LL*cnt[0]+1LL*cnt[1]+1LL*cnt[2]);

			else if(cnt[0]==0||cnt[1]==0||cnt[2]==0)

				ans+=1LL*edcnt;

			else if(legal==true)

				ans+=1LL*cnt[0]*cnt[1]+1LL*cnt[1]*cnt[2]+1LL*cnt[0]*cnt[2];

		}

	printf("%lld\n",ans);

	return 0;

}