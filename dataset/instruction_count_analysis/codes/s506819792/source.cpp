#include"stdc++.h"

int n;

std::vector<int> g[100005];

int dfs(int u,int fa){

	int sg=0;

	for(int v:g[u])if(v!=fa)sg^=dfs(v,u)+1;

	return sg;

}

int main(){

	scanf("%d",&n);

	for(int i=1,x,y;i<n;i++){

		scanf("%d%d",&x,&y);

		g[x].push_back(y),g[y].push_back(x);

	}

	puts(dfs(1,0)?"Alice":"Bob");

}
