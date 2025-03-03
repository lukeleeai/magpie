#include <cstdio>

#include <algorithm>

using namespace std;

#define N 100010

#define inf 0x3f3f3f3f 

int n,K,num,tot,cnt,a[N],b[N],vis[N],d[N],h[N],low[N],up[N];

struct node{int to,next;}mp[N<<1];

inline bool cmp(int x,int y){return d[x]<d[y];}

inline void ins(int x,int y){

	mp[++num].to=y;mp[num].next=h[x];h[x]=num;

	mp[++num].to=x;mp[num].next=h[y];h[y]=num;

}

bool dfs1(int x,int fa,int t){

	if(vis[x] && (a[x]&1)!=t) return false; 

	for(int i=h[x];i;i=mp[i].next){

		int y=mp[i].to;if(y==fa) continue;

		if(!dfs1(y,x,t^1)) return false;

	}

	return true;

}

bool dfs2(int x,int fa){

	if(vis[x]) low[x]=a[x],up[x]=a[x];

	else low[x]=-inf,up[x]=inf;

	for(int i=h[x];i;i=mp[i].next){

		int y=mp[i].to;if(y==fa) continue;

		if(!dfs2(y,x)) return false;

		low[x]=max(low[x],low[y]-1);

		up[x]=min(up[x],up[y]+1);

	}

	return low[x]<=up[x];

}

void dfs3(int x,int fa,int w){

	if(!vis[x]) a[x]=w;

	for(int i=h[x];i;i=mp[i].next){

		int y=mp[i].to;if(y==fa) continue;

		dfs3(y,x,(low[y]<=w-1 && w-1<=up[y])?w-1:w+1);

	}

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<n;++i){

		int x,y;scanf("%d%d",&x,&y);

		ins(x,y);

	}

	scanf("%d",&K);

	for(int i=1;i<=K;++i){

		int x,y;scanf("%d%d",&x,&y);

		a[x]=y;vis[x]=1;b[++tot]=x;

	}

	if(!dfs1(b[1],0,a[b[1]]&1) || !dfs2(b[1],0)){puts("No");return 0;}

	dfs3(b[1],0,a[b[1]]);

	puts("Yes");

	for(int i=1;i<=n;++i) printf("%d\n",a[i]);

	return 0;

}