#include<cstdio>

#include<algorithm>

#include<vector>

#include<cstring>

#include<cstdlib>

using namespace std;

#define MAXN 200005

#define INF 0x3f3f3f3f

#define LL long long

vector<int>G[MAXN];

int siz[MAXN],n,cnt;

void dfs(int u,int p)

{

	siz[u]=1;

	for(int i=0;i<G[u].size();i++)

	{

		int v=G[u][i];

		if(v==p) continue;

		dfs(v,u);

		if(siz[v]==2) siz[v]=-1;

		else siz[u]+=siz[v];//删点

	}

	return ;

}

void dfs2(int u,int p)

{

	++cnt;

	int num=0;//统计叶子个数 

	for(int i=0;i<G[u].size();i++)

	{

		int v=G[u][i];

		if(v==p) continue;

		if(siz[v]==1) num++;

		if(siz[v]!=-1)

			dfs2(v,u); 

	}

	if(num>=2)

	{

		printf("First\n");

		exit(0);

	}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n-1;i++)

	{

		int u,v;

		scanf("%d %d",&u,&v);

		G[u].push_back(v);

		G[v].push_back(u);

	}

	dfs(1,0);

	dfs2(1,0);

	if(cnt==1) printf("First\n");//只剩下一个节点 先手必胜 

	else printf("Second\n");//不存在那样的节点 先手必败 

    return 0;

}
