#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 200010

#define LL long long

int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c;

void AddEdge(int u,int v)

{

	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;

}

int dep[MAXN],f,dcnt,cnt1,cnt2,cnt3,n,m;

void dfs(int u)

{

	dcnt++;

	for(int i=Adj[u];i;i=nxt[i])

		if(!dep[V[i]])

		{

			dep[V[i]]=dep[u]+1;

			dfs(V[i]);

		}

		else if(dep[V[i]]%2==dep[u]%2)

			f=1;

}

int main()

{

	scanf("%d%d",&n,&m);

	int u,v;

	for(int i=1;i<=m;i++)

	{

		scanf("%d%d",&u,&v);

		AddEdge(u,v);

		AddEdge(v,u);

	}

	for(int i=1;i<=n;i++)

		if(!dep[i])

		{

			f=0,dcnt=0;

			dep[i]=1;

			dfs(i);

			if(f) cnt1++;

			else if(dcnt>1) cnt2++;

			else cnt3++;

		}

	LL ans=1LL*cnt1+cnt2*2LL+2LL*cnt1*cnt2+1LL*cnt1*(cnt1-1)+2LL*cnt2*(cnt2-1)+2LL*cnt3*n-1LL*cnt3*cnt3;

	printf("%lld\n",ans);

}