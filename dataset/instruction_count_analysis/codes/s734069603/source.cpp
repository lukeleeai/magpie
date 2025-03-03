#include<iostream>

#include<cstdio>

using namespace std;

typedef long long ll;

const int Maxn=1e5+5;

const int Mod=1e9+7;

struct edge{

	int v,nx;

}e[Maxn<<1];

int n,ne,f[Maxn];

ll dp[Maxn][2];

void read(int u,int v)

{	e[++ne].v=v;

	e[ne].nx=f[u];

	f[u]=ne;

}

void dfs(int u,int fa)

{	dp[u][0]=dp[u][1]=1ll;

	for(int i=f[u];i;i=e[i].nx)

	{	int v=e[i].v;

		if(v==fa)continue;

		dfs(v,u);

		dp[u][0]=((dp[v][1]+dp[v][0])%Mod*dp[u][0])%Mod;

		dp[u][1]=(dp[u][1]*dp[v][0])%Mod;

	}

}

int main()

{	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{	int u,v;

		scanf("%d%d",&u,&v);

		read(u,v);read(v,u);

	}

	dfs(1,0);

	printf("%lld\n",(dp[1][0]+dp[1][1])%Mod);

	return 0;

}