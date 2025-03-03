#include<cstdio>

#include<cstring>

const int maxn = 1e3 + 5;

const int inf = 1e9 + 7;

char G[maxn][maxn];

bool vis[maxn][maxn];

long long dp[maxn][maxn];

long long step ;

int n , m;

long long dfs(int x , int y){

	if(vis[x][y])return dp[x][y];

	if(x == n && y == m - 1)return 1;

	vis[x][y] = 1;

	if(G[x + 1][y] == '.') dp[x][y] += dfs(x + 1 , y);

	if(G[x][y + 1] == '.') dp[x][y] += dfs(x , y + 1);

	return dp[x][y] %inf;

}

int main(){

	int ans;

	scanf("%d%d ",&n,&m);

	for(int i = 1;i <= n;i++){

		scanf("%s",G[i]);

	}

	ans = dfs(1 , 0) %inf;

	printf("%d\n",ans);

return 0;

}