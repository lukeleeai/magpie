#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<vector>

#define SF scanf

#define PF printf

#define MAXN 200010

using namespace std;

int n;

struct node{

	int x;

	node *nxt;	

}edge[MAXN*2];

node *head[MAXN],*ncnt=edge;

void add_edge(int x,int y){

	ncnt++;

	ncnt->x=y;

	ncnt->nxt=head[x];

	head[x]=ncnt;

}

int sg[MAXN];

void dfs(int x,int fa){

	for(node *v=head[x];v!=NULL;v=v->nxt){

		int u=v->x;

		if(u==fa)

			continue;

		dfs(u,x);

		sg[x]^=(sg[u]+1);	

	}

}

int main(){

	SF("%d",&n);

	int u,v;

	for(int i=1;i<n;i++){

		SF("%d%d",&u,&v);

		add_edge(u,v);

		add_edge(v,u);

	}

	dfs(1,0);

	if(sg[1]==0)

		PF("Bob");

	else

		PF("Alice");

}