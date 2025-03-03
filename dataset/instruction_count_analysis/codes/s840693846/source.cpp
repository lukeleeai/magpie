#include <algorithm>

#include <iostream>

#include <cstdlib>

#include <cstring>

#include <cstdio>

#include <vector>

#define N 200011

using namespace std;

int ti,All[N],siz,tot,indexx[N],dp[N],vist[N],hashh[N],n,fa[N],cir[N],cnt;

vector<int> V[N];

struct apple{

	int v,nxt;

}edge[N*4];

void addedge(int x,int y){

	edge[++tot].v=y;

	edge[tot].nxt=indexx[x];

	indexx[x]=tot;

}

void dfs(int u,int f){

	int t=indexx[u],vv;

	while(t){

		vv=edge[t].v;

		if(!cir[vv] || vv==f){

			dfs(vv,u);

			V[u].push_back(dp[vv]);

		}

		t=edge[t].nxt;

	}

	ti++;

	int len=V[u].size();

	for(int i=0;i<len;i++){

		hashh[V[u][i]]=ti;

	}

	for(int i=0;i<=n*2;i++){

		if(hashh[i]!=ti){

			dp[u]=i;

			break;

		}

	}

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&fa[i]);

		addedge(fa[i],i);

	}

	int x=1;

	while(1){

		if(vist[x]) break;

		vist[x]=1;

		x=fa[x];

	}

	memset(vist,0,sizeof(vist));

	int u=x;

	while(1){

		if(cir[u]) break;

		cir[u]=1;

		cnt++;

		u=fa[u];

	}

	if(cnt%2==0){

		printf("POSSIBLE");

		return 0;

	}

	u=x;

	while(1){

		if(vist[u]) break;

		vist[u]=1;

		dfs(u,0);

		All[++siz]=dp[u];

		u=fa[u];

	}

	sort(All+1,All+siz+1);

	for(int i=1;i<siz;i++){

		if(All[i]!=All[i+1]){

			printf("POSSIBLE");

			return 0;

		}

	}

	printf("IMPOSSIBLE");

	return 0;

}