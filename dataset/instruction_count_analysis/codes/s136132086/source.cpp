#include<cstdio>

using namespace std;

#define N 105

int as1=1e8,n,head[N],cnt,in[N],dep[N],a,b,s[N][2];

long long as2;

struct edge{int t,next;}ed[N*2];

void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;in[f]++,in[t]++;}

void dfs(int u,int fa){dep[u]=dep[fa]+1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}

void solve1(int x)

{

	dfs(x,0);

	int mxdep=0;long long as=1;

	for(int i=1;i<=n;i++)if(dep[i]>mxdep)mxdep=dep[i];

	for(int i=1;i<mxdep;i++)

	{

		int mx=1;

		for(int j=1;j<=n;j++)

		if(dep[j]==i&&mx<in[j]-1)mx=in[j]-1;

		if(i==1)mx++;

		as*=mx;

	}

	if(as1>mxdep||(as1==mxdep&&as2>as))as1=mxdep,as2=as;

}

void solve2(int x,int y)

{

	dep[y]=0;dfs(x,y);dep[x]=0;dfs(y,x);dep[x]=1;

	int mxdep=0;long long as=2;

	for(int i=1;i<=n;i++)if(dep[i]>mxdep)mxdep=dep[i];

	for(int i=1;i<mxdep;i++)

	{

		int mx=1;

		for(int j=1;j<=n;j++)

		if(dep[j]==i&&mx<in[j]-1)mx=in[j]-1;

		as*=mx;

	}

	if(as1>mxdep||(as1==mxdep&&as2>as))as1=mxdep,as2=as;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)scanf("%d%d",&s[i][0],&s[i][1]),adde(s[i][0],s[i][1]);

	for(int i=1;i<=n;i++)solve1(i);

	for(int i=1;i<n;i++)solve2(s[i][0],s[i][1]);

	printf("%d %lld\n",as1,as2);

}//