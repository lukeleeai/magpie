#include<cstdio>

#include<algorithm>

#include<cstring>

#include<queue>

#include<map>

#define ull unsigned long long

using namespace std;

const int MAXN=100000+5;

struct Edge

{

	int flow,to,nxt;

}e[MAXN*20];

namespace Flow

{

	int dep[MAXN],tot,fir[MAXN],str,T,cur[MAXN];

	queue<int>q;

	void add(int x,int y,int w)

	{

		tot++;

		e[tot]=(Edge){w,y,fir[x]};

		fir[x]=tot;

		

		tot++;

		e[tot]=(Edge){0,x,fir[y]};

		fir[y]=tot;

	}

	void clr(int n)

	{

		T=n+1;str=0;

		memset(fir,0,sizeof(fir));

		tot=1;

	}

	bool bfs()

	{

		memset(dep,0,sizeof(dep));

		dep[str]=1;

		q.push(str);

		while(q.size())

		{

			int x=q.front();q.pop();

			for(int i=fir[x];i;i=e[i].nxt)

			{

				int v=e[i].to;

				if(e[i].flow==0||dep[v]) continue;

				dep[v]=dep[x]+1;

				q.push(v);

			}

		}

		return dep[T];

	}

	int dfs(int x,int flow)

	{

		if(x==T) return flow;

		int res=0,cnt;

		for(int &i=cur[x];i;i=e[i].nxt)

		{

			int v=e[i].to;

			if(dep[v]!=dep[x]+1||e[i].flow==0) continue;

			cnt=dfs(v,min(flow,e[i].flow));

			if(cnt)

			{

				e[i].flow-=cnt;

				e[i^1].flow+=cnt;

				res+=cnt;

				flow-=cnt;

			}

			if(!flow) return res;

		}

		return res;

	}

	int maxflow()

	{

		int res=0;

		while(bfs())

		{

			for(int i=str;i<=T;i++) cur[i]=fir[i];

			res+=dfs(str,1<<30);

		}

		return res;

	}

}

int n;

struct Node

{

	int p[MAXN],cnt,bel[MAXN];

}A,B;

int main()

{

//	freopen("1.in","r",stdin);

//	freopen("name.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",&A.p[i]),A.p[i]++;

	for(int i=1;i<=n;i++) scanf("%d",&B.p[i]),B.p[i]++;

	for(int i=1;i<=n;i++)

	if(!A.bel[i])

	{

		A.bel[i]=++A.cnt;

		for(int j=A.p[i];!A.bel[j];j=A.p[j])

			A.bel[j]=A.cnt;

	}

	for(int i=1;i<=n;i++)

	if(!B.bel[i])

	{

		B.bel[i]=++B.cnt;B.bel[i]=B.cnt+A.cnt;

		for(int j=B.p[i];!B.bel[j];j=B.p[j])

			B.bel[j]=B.cnt+A.cnt;

	}

	Flow::clr(A.cnt+B.cnt);

	int Ans=n;

	for(int i=1;i<=n;i++)

	if(A.p[i]!=i||B.p[i]!=i)

	{

		if(A.p[i]==i)

		{

			Flow::add(B.bel[i],Flow::T,1);

			continue;

		}

		if(B.p[i]==i)

		{

			Flow::add(0,A.bel[i],1);

			continue;

		}

		if(A.p[i]==B.p[i])

		{

			Flow::add(A.bel[i],B.bel[i],1);

			Flow::add(B.bel[i],A.bel[i],1);

			continue;

		}

		Flow::add(B.bel[i],A.bel[i],1);

	}

	else Ans--;

	printf("%d\n",Ans-Flow::maxflow());

	return 0;

}

	