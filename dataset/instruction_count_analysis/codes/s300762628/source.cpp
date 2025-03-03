#include<cstdio>

#include<cstring>

#include<vector>

#include<algorithm>

#define MAXN 100000

using namespace std;

typedef long long LL;

vector<int> G[MAXN+5];

int N,ans;

int cnt[MAXN+5][21];

void DFS(int u,int fa)

{

	for(int i=0;i<(int)G[u].size();i++)

	{

		int v=G[u][i];

		if(v==fa)

			continue;

		DFS(v,u);

		for(int j=0;j<20;j++)

			cnt[u][j]+=cnt[v][j];

	}

	int val=0;

	for(int i=20;i>=0;i--)

		if(cnt[u][i]>=2)

		{

			val=i+1;

			break;

		}

	while(cnt[u][val]==1)

		val++;

	ans=max(ans,val);

	cnt[u][val]++;

	for(int i=0;i<val;i++)

		cnt[u][i]=0;

}

int main()

{

//	freopen("uninity.in","r",stdin);

//	freopen("uninity.out","w",stdout);

	scanf("%d",&N);

	int u,v;

	for(int i=1;i<N;i++)

	{

		scanf("%d %d",&u,&v);

		G[u].push_back(v);

		G[v].push_back(u);

	}

	DFS(1,-1);

	printf("%d\n",ans);

	return 0;

}