#include<cstdio>

#include<queue>

using namespace std;

#define N 200050

int fa[N],sz[N],head[N],cnt,mx[N],f[N],ti=1,as[N],n,a,b,fr[N],vl[N];

struct edge{int t,next;}ed[N*2];

priority_queue<pair<int,int> > st;

int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}

void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}

void dfs1(int u,int fa){f[u]=fa;mx[u]=mx[f[u]],fr[u]=fr[f[u]];if(mx[u]<fa)mx[u]=fa,fr[u]=u;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs1(ed[i].t,u);}

int que(int x){if(x<ti)return sz[finds(x)]-1;int as=0;for(int i=head[x];i;i=ed[i].next)if(ed[i].t<ti)as+=sz[finds(ed[i].t)];return as;}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);

	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;

	dfs1(1,0);

	for(int i=head[1];i;i=ed[i].next)st.push(make_pair(-1,ed[i].t));

	while(!st.empty())

	{

		int las=ti;

		ti=-st.top().first;int s=st.top().second;st.pop();

		for(int i=las;i<ti;i++)

		for(int j=head[i];j;j=ed[j].next)if(ed[j].t<i){int a=finds(i),b=finds(ed[j].t);fa[a]=b,sz[b]+=sz[a];}

		as[s]+=as[mx[s]]+que(s)+1-vl[fr[s]];

		for(int i=head[s];i;i=ed[i].next)if(ed[i].t!=f[s])st.push(make_pair(-mx[ed[i].t],ed[i].t)),vl[ed[i].t]=ed[i].t<ti?sz[finds(ed[i].t)]:0;

	}

	for(int i=2;i<=n;i++)printf("%d ",as[i]);

}//