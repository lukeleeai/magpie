#include"stdc++.h"

using namespace std;

#define ll long long

const int N=2005;

int n,sz[N];ll ans=1e18,f[N],g[N];

char s[N];vector<int>G[N];

void dfs(int x,int p)

{

	sz[x]=s[x]=='1';g[x]=0;ll mx=0,sum=0;

	for(int i=0;i<G[x].size();i++)if(G[x][i]!=p)

	{

		int y=G[x][i];dfs(y,x);sz[x]+=sz[y];

		g[y]+=sz[y];g[x]+=g[y];f[y]+=sz[y];

		if(f[y]>=f[mx])sum+=g[mx],mx=y;else sum+=g[y];

	}

	if(sum>=f[mx])f[x]=(sum-f[mx])&1;else f[x]=f[mx]-sum;

}

int main()

{

	scanf("%d%s",&n,s+1);

	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);

	for(int i=1;i<=n;i++){dfs(i,0);if(!f[i])ans=min(ans,g[i]);}

	printf("%d\n",ans==1e18?-1:ans/2);return 0;

}