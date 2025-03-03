#include<cstdio>

#include<cctype>

#include<algorithm>

using namespace std;

typedef long long LL;

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,1000000,stdin),pa==pb)?EOF:*pa++

static char buf[1000000],*pa(buf),*pb(buf);

inline int readint() {

	int x=0;char c=gc;

	while(c<'0'||c>'9')c=gc;

	for(;c>='0'&&c<='9';c=gc)x=x*10+(c&15);

	return x;

}

const int N=5e5+5;

struct edge{

	int to,nxt,w;

}e[N*2];

struct E{

	int u,v;LL w;

	inline bool operator<(const E&rhs)const{return w<rhs.w;}

}G[N*2];

int cnt,head[N],w[N],id[N],tot;LL dis[N],ans,n;

void dfs(int now,int pre){

	id[now]=now;

	for(int i=head[now];i;i=e[i].nxt)if(e[i].to!=pre){

		dfs(e[i].to,now);

		if(dis[now]>dis[e[i].to]+e[i].w)dis[now]=dis[e[i].to]+e[i].w,id[now]=id[e[i].to];

	}

}

void dfs2(int now,int pre){

	for(int i=head[now];i;i=e[i].nxt)if(e[i].to!=pre){

		if(dis[e[i].to]>dis[now]+e[i].w)dis[e[i].to]=dis[now]+e[i].w,id[e[i].to]=id[now];

		dfs2(e[i].to,now);

		G[++tot]=(E){id[now],id[e[i].to],dis[now]+dis[e[i].to]+e[i].w};

	}

	G[++tot]=(E){id[now],now,dis[now]+w[now]};

}

#define fa head

#define sz w

inline int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}

int main(){

	n=readint();

	for(int i=1;i<=n;++i)dis[i]=w[i]=readint();

	for(int i=1;i<n;++i){

		int u=readint(),v=readint(),w=readint();

		e[++cnt]=(edge){v,head[u],w},head[u]=cnt;

		e[++cnt]=(edge){u,head[v],w},head[v]=cnt;

	}

	dfs(1,0),dfs2(1,0),sort(G+1,G+tot+1);

	for(int i=1;i<=n;++i)sz[fa[i]=i]=1;

	cnt=0;

	for(int i=1;i<=tot&&cnt!=n-1;++i){

		int x=find(G[i].u),y=find(G[i].v);

		if(x!=y){

			if(sz[x]<sz[y])swap(x,y);

			sz[x]+=sz[y],fa[y]=x,id[++cnt]=i,ans+=G[i].w;

		}

	}

	printf("%lld\n",ans);

//	for(int i=1;i<n;++i)printf("%d %d\n",G[id[i]].u,G[id[i]].v);

	return 0;

}