#include<iostream>

#include<algorithm>

using namespace std;

typedef long long LL;

const int N=2e5+5;

int w[N],n,head[N],cnt,tot,sz[N],all,mxd[N],rt;

int U[N*20],V[N*20],id[N*20],fa[N];LL W[N*20],ans;

bool vis[N];

struct edge{

	int to,nxt,w;

}e[N<<1];

inline bool cmp(const int&a,const int&b){return W[a]<W[b];}

inline int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}

void getrt(int now,int pre){

	sz[now]=1,mxd[now]=0;

	for(int i=head[now];i;i=e[i].nxt)if(e[i].to!=pre&&!vis[e[i].to]){

		getrt(e[i].to,now),sz[now]+=sz[e[i].to],mxd[now]=max(mxd[now],sz[e[i].to]);

	}

	mxd[now]=max(mxd[now],all-sz[now]);

	if(!rt||mxd[now]<mxd[rt])rt=now;

}

LL mx;int num; 

void dfs(int now,int pre,LL s){

	if(mx>s+w[now])num=now,mx=s+w[now];

	for(int i=head[now];i;i=e[i].nxt)if(!vis[e[i].to]&&e[i].to!=pre)dfs(e[i].to,now,s+e[i].w);

}

void DFS(int now,int pre,LL s){

	U[++tot]=num,V[tot]=now,W[tot]=s+w[now]+mx,id[tot]=tot;

	for(int i=head[now];i;i=e[i].nxt)if(!vis[e[i].to]&&e[i].to!=pre)DFS(e[i].to,now,s+e[i].w);

}

void work(int now){

	mx=w[now],num=now;

	for(int i=head[now];i;i=e[i].nxt)if(!vis[e[i].to])dfs(e[i].to,now,e[i].w);

	for(int i=head[now];i;i=e[i].nxt)if(!vis[e[i].to])DFS(e[i].to,now,e[i].w);

	U[++tot]=num,V[tot]=now,W[tot]=w[now]+mx,id[tot]=tot;

}

void solve(int now){

	vis[now]=1;

	work(now);

	int sm=all;

	for(int i=head[now];i;i=e[i].nxt)if(!vis[e[i].to]){

		all=sz[now]>sz[e[i].to]?sz[e[i].to]:sm-sz[now];

		rt=0;

		getrt(e[i].to,now);

		solve(rt);

	}

}

int main(){

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;

	for(int i=1;i<=n;++i)cin>>w[i];

	for(int i=1;i<n;++i){

		int u,v,w;

		cin>>u>>v>>w;

		e[++cnt]=(edge){v,head[u],w},head[u]=cnt;

		e[++cnt]=(edge){u,head[v],w},head[v]=cnt;

	}

	all=n;

	getrt(1,0);

	solve(rt);

	sort(id+1,id+tot+1,cmp);

	for(int i=1;i<=n;++i)sz[fa[i]=i]=1;

	cnt=n-1;

	for(int j=1,i=id[1];j<=tot&&cnt;i=id[++j])if(find(U[i])!=find(V[i])){

		int u=find(U[i]),v=find(V[i]);

		if(sz[u]<sz[v])swap(u,v);

		sz[u]+=sz[v],fa[v]=u,ans+=W[i],--cnt;

	}

	cout<<ans<<'\n';

	return 0;

}