#include"stdc++.h"

typedef long long LL;

using namespace std;

const int N=1e5+5;

int n,m,fa[N],p[N];

LL sum[N],f[N],a[N],b[N];

int head[N],ce;

bool vis[N];

struct edge{int to,nxt;} e[N<<1];

bool cmp(int x,int y) {return a[x]<a[y];}

void adde(int x,int y) {e[++ce].to=y,e[ce].nxt=head[x],head[x]=ce;}

int find(int x)

{

	if(x==fa[x]) return x;

	return fa[x]=find(fa[x]);

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;++i)

	{

		scanf("%lld%lld",&a[i],&b[i]);

		a[i]=max(a[i]-b[i],0ll);

		p[i]=fa[i]=i,f[i]=a[i],sum[i]=b[i];

	}

	for(int i=1;i<=m;++i)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		adde(x,y); adde(y,x);

	}

	sort(p+1,p+n+1,cmp);

	for(int i=1;i<=n;++i)

	{

		int u=p[i]; vis[u]=1;

		for(int j=head[u];j;j=e[j].nxt)

		{

			int v=e[j].to;

			if(!vis[v]) continue;

			int x=find(u),y=find(v);

			if(x!=y)

			{

				fa[y]=x,sum[x]+=sum[y];

				f[x]=min(f[x],max(f[y],a[x]-sum[y]));

			}

		}

	}

	printf("%lld",f[find(1)]+sum[find(1)]);

	return 0;

}