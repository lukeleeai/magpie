#include"stdc++.h"

using namespace std;

const int maxn=2e5+10;

vector<int>G[maxn];

int in[maxn],out[maxn],tol;

int sz[maxn],S[maxn],is[maxn],son[maxn];

void get_cal(int v,int fa,int limit)

{

	son[v]=0;

	if(v>=limit)

		return;

	son[v]=1;

	for(int i=G[v].size()-1;i>=0;i--)

	{

		int u=G[v][i];

		if(u==fa)

			continue;

		get_cal(u,v,limit);

		son[v]+=son[u];

	}

}

void get_order(int v,int fa,int mx)

{

	is[v]=mx;

	for(int i=G[v].size()-1;i>=0;i--)

	{

		int u=G[v][i];

		if(u==fa)

			continue;

		if(is[v]>is[fa]||v>is[v])

			get_cal(u,v,is[v]);

		sz[u]=son[u];

	}

	for(int i=G[v].size()-1;i>=0;i--)

	{

		int u=G[v][i];

		if(u==fa)

			continue;

		get_order(u,v,max(mx,v));

	}

}

void dfs(int v,int fa)

{

	S[v]++;

	for(int i=G[v].size()-1;i>=0;i--)

	{

		int u=G[v][i];

		if(u==fa)

			continue;

		S[v]+=sz[u];

	}

	for(int i=G[v].size()-1;i>=0;i--)

	{

		int u=G[v][i];

		if(u==fa)

			continue;

		S[u]=S[v]-sz[u];

		dfs(u,v);

	}

}

int main()

{

	int n;scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int x,y;scanf("%d%d",&x,&y);

		G[x].push_back(y);

		G[y].push_back(x);

	}

	get_order(1,0,0);

	dfs(1,0);

	for(int i=2;i<=n;i++)

		printf("%d ",S[i]-1);

	return 0;

}
