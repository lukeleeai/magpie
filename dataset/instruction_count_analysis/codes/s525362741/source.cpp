#include <iostream>

#include <cstdlib>

#include <cstdio>

#define N 200011

#define INF 0x7f7f7f7f

#define int long long

using namespace std;

int L[N],R[N],maxx1[N],maxx2[N],fa[N],siz[N],n,indexx[N],tot,Mark[N],ans;

char s[N];

struct apple{

	int v,nxt;

}edge[N*4];

void addedge(int x,int y){

	edge[++tot].v=y;

	edge[tot].nxt=indexx[x];

	indexx[x]=tot;

}

void dfs1(int u,int f){

	if(Mark[u]){

		siz[u]=1;

		L[u]=0;

	}

	else L[u]=INF;

	fa[u]=f;

	maxx1[u]=0;

	maxx2[u]=-INF;

	int t=indexx[u],vv;

	while(t){

		vv=edge[t].v;

		if(vv!=f){

			dfs1(vv,u);

			siz[u]+=siz[vv];

			if(maxx1[vv]+1>maxx1[u]){

				maxx2[u]=maxx1[u];

				maxx1[u]=maxx1[vv]+1;

			}

			else if(maxx1[vv]+1>maxx2[u]){

				maxx2[u]=maxx1[vv]+1;

			}

			if(siz[vv]) L[u]=min(L[u],maxx1[vv]+1);

		}

		t=edge[t].nxt;

	}

}

void dfs(int u){

	int temp;

	R[u]=min(maxx1[u]-1,maxx2[u]+1);

	if(R[u]>=L[u]) ans+=R[u]-L[u]+1;

	int t=indexx[u],vv;

	while(t){

		vv=edge[t].v;

		if(vv!=fa[u]){

			if(maxx1[u]==maxx1[vv]+1){

				temp=maxx2[u]+1;

			}

			else temp=maxx1[u]+1;

			if(temp>maxx1[vv]) maxx2[vv]=maxx1[vv],maxx1[vv]=temp;

			else if(temp>maxx2[vv]) maxx2[vv]=temp;

			if(siz[1]-siz[vv]) L[vv]=min(L[vv],temp);

			dfs(vv);

		}

		t=edge[t].nxt;

	}

}

signed main(){

	int x,y;

	scanf("%lld",&n);

	for(int i=1;i<n;i++){

		scanf("%lld%lld",&x,&y);

		addedge(x,y);

		addedge(y,x);

	}

	scanf("%s",s+1);

	for(int i=1;i<=n;i++) Mark[i]=s[i]-'0';

	dfs1(1,0);

	dfs(1);

	printf("%lld",ans+1);

	return 0;

}