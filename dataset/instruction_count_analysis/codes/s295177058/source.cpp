#include "stdc++.h"



#define f first 

#define s second 

#define pb push_back               

#define mp make_pair 



using namespace std;                    



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;



const int N = 2123, mod = (int)1e9 + 7, inf = (int)1e9;



vector< int > g[N];

int n, k, dp[N][N], tmp[N], ans, sz[N];



void dfs(int v,int p){

	

	sz[v] = 1;



	for(int i = 1; i < N; i++)

		dp[v][i] = inf;

	for(auto to : g[v]){

		if(to == p)

			continue;

		dfs(to, v);

		

		for(int i = 0; i < N; i++)

			tmp[i] = inf;

		

		for(int i = 0; i <= sz[to]; i++)

			for(int j = 0; j <= sz[v]; j++)

				if( i + j + 1 <= k )

					tmp[max(i + 1, j)] = min(tmp[max(i + 1, j)], dp[v][j] + dp[to][i]);

		

		sz[v] += sz[to];

		for(int i = 0; i <= sz[v]; i++)

			dp[v][i] = min(dp[v][i] + sz[to], tmp[i]);

	}

	for(int i = 0; i < N; i++)

		ans = min(ans, dp[v][i] + n - sz[v]);

}

int main(){    

	cin >> n >> k;

	for(int i = 1; i < n; i++){

		int v, u;

		cin >> v >> u;

		g[v].pb(u);

		g[u].pb(v);

	}

	ans = inf;

	dfs(1, 1);

	cout << ans;

	return 0;

}
