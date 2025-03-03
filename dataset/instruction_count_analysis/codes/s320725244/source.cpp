#include<cstdio>

#include<algorithm>

#include<cstring>

#define MN 100005

using namespace std;

int n,m,q,v[MN],c[MN],d[MN],col[MN][11],num,head[MN];

struct edge{int to,next;}g[MN<<2];

void ins(int u,int v){g[++num].next=head[u];head[u]=num;g[num].to=v;}

void dfs(int u,int cc,int dd){

	if(col[u][dd])return;col[u][dd]=cc;

	for(int i=head[u];i;i=g[i].next)if(dd-1>=0)dfs(g[i].to,cc,dd-1);	

}

int main(){

	scanf("%d%d",&n,&m);int x,y;

	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);

	for(int i=1;i<=n;i++)ins(i,i);

	scanf("%d",&q);for(int i=1;i<=q;i++)scanf("%d%d%d",&v[i],&d[i],&c[i]);

	for(int i=q;i>=1;i--)dfs(v[i],c[i],d[i]);

	for(int i=1;i<=n;i++)printf("%d\n",col[i][0]);

}