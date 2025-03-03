#include<cstdio>

using namespace std;

#define N 105000

int n,head[N],cnt,is[N],f[N],g[N],dp[N][2],st,as=1e9,a,b;

char s[N];

struct edge{int t,next;}ed[N*2];

void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}

void dfs(int u,int fa){is[u]=s[u]=='W';for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u),is[u]|=is[ed[i].t];}

void dfs1(int u,int fa){int is1=(fa?0:1);for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&is[ed[i].t])dfs1(ed[i].t,u),f[u]+=f[ed[i].t]+2,is1++;if((is1&1)^(s[u]=='B'))f[u]++;}

void dfs2(int u,int fa){for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&is[ed[i].t])g[ed[i].t]=g[u]+f[u]-f[ed[i].t],dfs2(ed[i].t,u);}

void dfs3(int u,int fa)

{

	int su=0,m1=1e9,m2=1e9,m3=1e9,is1=fa?0:1;

	for(int i=head[u];i;i=ed[i].next)

	if(ed[i].t!=fa&&is[ed[i].t])

	{

		is1++;

		dfs3(ed[i].t,u);

		su+=f[ed[i].t]+2;

		if(m1>dp[ed[i].t][0]-f[ed[i].t]-1)m1=dp[ed[i].t][0]-f[ed[i].t]-1;

		if(m2>dp[ed[i].t][1]-f[ed[i].t]-1)m3=m2,m2=dp[ed[i].t][1]-f[ed[i].t]-1;

		else if(m3>dp[ed[i].t][1]-f[ed[i].t]-1)m3=dp[ed[i].t][1]-f[ed[i].t]-1;

	}

	dp[u][0]=(m1>0?0:m1)+f[u]+((is1&1)^(s[u]=='B')?-1:1);

	dp[u][1]=m2+f[u]+((is1&1)^(s[u]=='B')?-1:1);

	if(dp[u][1]>f[u])dp[u][1]=f[u];

	if(m2>0)m3=m2,m2=0;else if(m3>0)m3=0;

	for(int i=head[u];i;i=ed[i].next)

	if(ed[i].t!=fa&&is[ed[i].t])

	{

		int s1=dp[ed[i].t][0]-f[ed[i].t]-1;

		if(dp[ed[i].t][1]-f[ed[i].t]-1==m2)s1+=m3;

		else s1+=m2;

		int as1=f[u]+g[u]+s1+((is1&1)^(s[u]=='B')?-1:1);

		if(m3==0&&((is1&1)^(s[u]=='B'))==0)as1--;

		if(as>as1)as=as1;

	}

	for(int i=head[u];i;i=ed[i].next)

	if(ed[i].t!=fa&&is[ed[i].t])

	{

		int s1=dp[ed[i].t][1]-f[ed[i].t]-1;

		int as1=f[u]+g[u]+s1+((is1&1)^(s[u]=='B')?-1:1);

		if(as>as1)as=as1;

	}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);

	scanf("%s",s+1);

	for(int i=1;i<=n;i++)if(s[i]=='W')st=i;

	dfs(st,0);dfs1(st,0);as=f[st];dfs2(st,0);dfs3(st,0);

	if(!st)as=0;printf("%d\n",as);

}