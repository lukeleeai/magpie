#include<cstdio>

#include<algorithm>

using namespace std;

#define N 2050

struct edge{int t,next;}ed[N*2];

int head[N],cnt,n,mn[N],mx[N],sz[N],a,b,as=1e9;

char is[N];

void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}

void dfs(int u,int fa)

{

	sz[u]=(is[u]=='1');mn[u]=mx[u]=0;

	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u),mx[u]+=mx[ed[i].t]+sz[ed[i].t],sz[u]+=sz[ed[i].t];

	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)mn[u]=max(mn[u],mn[ed[i].t]+mx[ed[i].t]-mx[u]+sz[ed[i].t]*2);

}

int main()

{

	scanf("%d%s",&n,is+1);

	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);

	for(int i=1;i<=n;i++)dfs(i,0),as=min(as,(mn[i]||(mx[i]&1))?1000000000:mx[i]/2);

	printf("%d\n",as>1e8?-1:as);

}